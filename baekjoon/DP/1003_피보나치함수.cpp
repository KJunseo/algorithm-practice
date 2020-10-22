/*
    이전 문제들과 접근방식이 비슷했던 것 같다.
    2차원 배열로 생각하고 풀었다.
    dp[i][0]은 i일 때 0의 호출 수, dp[i][1]은 i일 때 1의 호출 수로 생각하였다.

    피보나치 공식이 fibo(n) = fibo(n - 1) + fibo(n - 2)이므로 
    dp[i][0] = dp[i - 1][0] + dp[i - 2][0](i의 0 호출 수는 (i - 1) 0 호출 수 + (i - 2)의 0 호출 수이다.)
    dp[i][1] = dp[i - 1][1] + dp[i - 2][1](i의 1 호출 수는 (i - 1) 1 호출 수 + (i - 2)의 1 호출 수이다.)

    다른 사람들의 풀이를 보니 규칙을 찾아서 풀었다
    i의 0 호출 수는 fibo(i-1)의 값이고 
    i의 1 호출 수는 fibo(i)의 값이었다.

    따라서 그냥 일차원 dp만 계산하는 방식이었다.
*/
#include <stdio.h>

int dp[41][2];

int main(void) {
    int tc;
    scanf("%d", &tc);

    dp[0][0] = 1;
    dp[0][1] = 0;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    for(int i = 0; i < tc; i++) {
        int n;
        scanf("%d", &n);

        printf("%d %d\n", dp[n][0], dp[n][1]);
    }

    return 0;
}