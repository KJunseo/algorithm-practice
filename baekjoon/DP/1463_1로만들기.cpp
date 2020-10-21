/*
    바로 전에 풀었던 설탕 배달이랑 거의 유사한 문제였다.
    dp[i] 는 i - 1 일 때의 최소 연산 횟수에 1 을 더한 값(+ 1)
    2로 나눠질 경우 i / 2 일 때의 최소 연산 횟수에 1을 더한 값(* 2)
    3으로 나눠질 경우 i / 3 일 때의 최소 연산 횟수에 1을 더한 값(* 3)
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(void) {
    int n;
    scanf("%d", &n);

    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0) 
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    printf("%d\n", dp[n]);

    return 0;
}