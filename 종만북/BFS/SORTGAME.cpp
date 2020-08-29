/*
    문제를 읽었을때 이게 왜 BFS지? 라는 생각이 먼저 들었고
    주어진 숫자를 배열하는 모든 경우의 수를 정점으로 두어 부분 구간을 뒤집어 다른 배열을 만들 수 있는 경우 간선으로 연결하는 식으로 그래프를 만든다는 생각을 어떻게 하는거지 라는 생각이 두 번째로 들었다..

    최적화를 하는 것도 신기했다.
    1. 상대적인 크기가 같은 배열들에 대한 답은 항상 같다.
    2. 한 배열을 정렬하는 데 드는 연산의 수는 정렬된 배열을 원래 배열로 바꾸는 데 드는 연산의 수와 같다.

    또 백준에서 BFS를 풀어보았지만(조금) 큐에 벡터 자체를 넣는 것도 처음봐서 신기했다.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int C;
int n;
map<vector<int>, int> toSort;

// [0, ..., n-1]의 모든 순열에 대해 toSort[]를 계산해 저장한다.
void precalc() {
    vector<int> perm(n);

    for(int i = 0; i < n; i++) 
        perm[i] = i;

    queue<vector<int> > q;
    q.push(perm);
    toSort[perm] = 0;

    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();

        int cost = toSort[here];

        for(int i = 0; i < n; i++) {
            for(int j = i+2; j <= n; j++) {
                reverse(here.begin() + i, here.begin() + j);
                if(toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

// perm을 [0, ..., n-1]의 순열로 변환한다.
int solve(const vector<int>& perm) {

    int n = perm.size();
    vector<int> fixed(n);

    for(int i = 0; i < n; i++) {
        int smaller = 0;

        for(int j = 0; j < n; j++) 
            if(perm[j] < perm[i]) smaller++;
        
        fixed[i] = smaller;
    }

    return toSort[fixed];
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        vector<int> perm(n);
        for(int i = 0; i < n; i++) {
            cin >> perm[i];
        }

        precalc();
        cout << solve(perm) << "\n";
    }

    return 0;
}