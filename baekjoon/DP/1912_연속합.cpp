/*
    dp[n]을 n번 자리까지의 연속합의 최대라고 생각하자.

    연속합이기 때문에 n번까지의 최대 연속합은 n-1번까지의 최대 연속합에 현재수를 더한 값이나, 이때까지의 연속합을 포기하고, 자기 자신의 값만 사용하는 2가지 경우 중 하나에 해당된다.
    즉 dp[n] = max(dp[n - 1] + arr[n], arr[n]) 으로 구할 수 있다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int answer = dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";

    return 0;
}