/*
    2579 계단오르기 문제와 유사한 문제였다.
    dp[i]는 i번쨰 포도주까지의 최대양을 뜻한다.

    3잔 연속 마실 수 없으므로 n번째 포도주까지의 최대양은 3가지 경우 중 하나이다.
    1) n - 1번 잔까지의 최대양
    2) n - 2번 잔까지의 최대양 + n번째 포도주의 양
    3) n - 3번 잔까지의 최대양 + n - 1 번째 포도주의 양 + n번째 포도주의 양
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wineAmount[10001];
int dp[10001];

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> wineAmount[i];
    }

    dp[1] = wineAmount[1];
    dp[2] = wineAmount[1] + wineAmount[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + wineAmount[i - 1]) + wineAmount[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}