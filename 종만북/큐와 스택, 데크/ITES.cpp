/*
    온라인 알고리즘이라는 개념을 처음 배워서 신기했다.
    온라인 알고리즘은 전체 입력이 한꺼번에 주어지지 않아도 계산을 시작할 수 있는 알고리즘으로 예시로 삽입 정렬이 있다.

    또 난수 생성을 하는 것도 신기했다. 문제 자체가 잘 이해되진 않았지만 신기했다.
*/
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int C;
int K, N;

/*
// 메모리에 모든 숫자를 저장할 수 있다고 가정할 때의 오프라인 알고리즘 
int optimized(const vector<int>& signals) {
    int ret = 0, tail = 0, rangeSum = signals[0];

    for(int head = 0; head < signals.size(); head++) {

        // rangeSum이 K이상인 최초의 구간을 만날 때까지 tail을 옮긴다. 
        while(rangeSum < K && (tail + 1) < signals.size()) {
            rangeSum += signals[++tail];
        }

        if(rangeSum == K) ret++;

        // head가 증가한 후에 구간합을 새로 계산할 필요가 없게 미리 빼준다. 
        rangeSum -= signals[head];
    }

    return ret;
}
*/

// 선형 합동 난수 생성기의 구현 
struct RNG {
    unsigned seed;

    RNG(): seed(1983) {}

    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

int countRanges() {
    RNG rng; // 신호값을 생성하는 난수 생성기 
    queue<int> range; // 현재 구간에 들어 있는 숫자들을 저장하는 큐 
    int ret = 0, rangeSum = 0;

    for(int i = 0; i < N; i++) {

        // 구간에 숫자를 추가한다. 
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        // 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다.
        while(rangeSum > K) {
            rangeSum -= range.front();
            range.pop();
        }

        if(rangeSum == K) ret++;
    }

    return ret; 
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> K >> N;

        cout << countRanges() << "\n";
    }

    return 0;
}