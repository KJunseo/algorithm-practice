/*
    최대힙, 최소힙에 나누어 저장하여 항상 최대힙의 루트값을 답으로 하는 방식이 매우 신선했다.
    stl의 priority_queue 는 힙의 구현이다.
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

// 난수 생성기 
struct RNG {
    int seed, a, b;

    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}

    int next() {
        int ret = seed;
        seed = ((seed * (long long)a) + b) % 20090711;
        return ret;
    }
};

int C;
int N, a, b;

int runningMedian(RNG rng) {
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int ret = 0;

    // 1. maxHeap의 크기는 minHeap의 크기와 같거나 1 더 크다.
    // 2. maxHeap의 최대 원소는 minHeap의 최소원소보다 항상 작거나 같다.
    for(int cnt = 1; cnt <= N; cnt++) {

        // 1번 조건부터 만족시키기 
        if(maxHeap.size() == minHeap.size()) maxHeap.push(rng.next());
        else minHeap.push(rng.next());

        // 2번 조건이 맞지 않는 경우 복구 
        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int a = maxHeap.top();
            int b = minHeap.top();

            maxHeap.pop(), minHeap.pop();

            maxHeap.push(b);
            minHeap.push(a);
        }

        ret = (ret + maxHeap.top()) % 20090711;
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N >> a >> b;

        RNG rng(a, b);

        cout << runningMedian(rng) << "\n";
    }   

    return 0;
}