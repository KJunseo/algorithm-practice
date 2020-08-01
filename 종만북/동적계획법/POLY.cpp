/*
    접근 방법을 보고 많이 놀랐다.
    어떻게 이런 문제를 보고 각 가로줄에 포함된 정사각형들은 항상 일렬로 연속해있으므로, 각 가로줄에 들어갈 정사각형의 수를 정해주고 왼쪽-오른쪽으로 밀면 된다고 생각해내는지 신기했다..
    또 경우의 수가 first+second-1 개라는 것과 이 모든 걸 구현하는 것이 신기했다.
    지금 내 실력으로는 도저히 풀 수 없는 문제였다.
    아무래도 종만북을 한 번 읽고 나서 다시 모든 문제를 풀이 참고 없이 풀어봐야 할 것 같다..
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 10000000

using namespace std;

int C;
int n;
int cache[101][101];

// n개의 정사각형을 포함하되, 첫 줄에 first개의 정사각형이 들어가는 폴리오미노의 수를 반환하는 함수
int poly(int n, int first) {

    // 기저 사례: n개의 정사각형이 있고, 첫 줄이 n개이면 가로로 n개를 나열한 단 한가지 방법 뿐
    if(n == first) return 1;

    // 메모이제이션
    int& ret = cache[n][first];
    if(ret != -1) return ret;

    // 첫 째줄에 first개의 정사각형이 있는 경우
    // 두번째줄에 올 수 있는 정사각형의 수는 1 ~ n-first 개
    // 일반화 하면 방법의 수는 first + second - 1 개 
    ret = 0;
    for(int second = 1; second <= n-first; second++) {
        int add = second+first-1;
        add *= poly(n-first, second); // 제일 첫째줄에 first개를 썼으므로 남은 총 정사각형은 n-first개. 부분 문제의 폴리오미노 첫 째줄에는 1 ~ n-first 개의 정사각형이 올 수 있음. 각 경우의 수 x 부분 문제의 폴리오미노
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    
    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {
        int sum=0;

        memset(cache, -1, sizeof(cache));

        cin >> n;

        for(int i=1;i<=n;i++) {
            sum+=poly(n, i);
            sum%=MOD;
        }

        cout << sum << "\n";
    }

    return 0;
}