/*
    여러 코딩테스트를 쳐보았지만 결과가 모두 좋지않았다..
    dp쪽이 많이 부족한 것 같다는 생각이 들어서 dp 카테고리부터 다시 백준 공부를 해보려고한다.
    비록 올해 취업이 실패하더라도 내년을 위해서 조금씩 다시 시작해야겠다.

    브론즈1 dp문제였다. 처음 보자마자 그리디한 방법이 떠올랐지만 dp연습을 하기 위해 dp로 생각해보려 했으나 쉽지않았다.
    이차원 배열을 막 생각해보다가 풀이를 참고하였다.

    dp[i] = min(dp[i - 3] + dp[i - 5]) + 1 의 점화식 문제였다.
    dp[i - 3]은 i - 3 키로 까지의 봉지 갯수에다 3키로 봉지를 추가할 경우이고
    dp[i - 5]는 i - 5 키로 까지의 봉지 갯수에다 5키로 봉지를 추가할 경우이다.

    dp 감을 빨리 잡으면 좋겠다.
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 1700;

int dp[5001];

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i <= n; i++) 
        dp[i] = MAX;

    dp[3] = dp[5] = 1;

    for(int i = 6; i <= n; i++)
        dp[i] = min(dp[i - 5], dp[i - 3]) + 1;

    if(dp[n] >= MAX)
        printf("%d\n", -1);
    else
        printf("%d\n", dp[n]);

    return 0;
}