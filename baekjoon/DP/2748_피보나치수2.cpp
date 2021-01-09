/*
    문제 자체에 점화식이 주어져있었고, 유명한 피보나치 문제였다.
    다만 long long을 써야한다는 것에 유의해야한다.
*/
#include <iostream>

using namespace std;

int n;
long long dp[91];

int main(void) {
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << "\n";

    return 0;
}