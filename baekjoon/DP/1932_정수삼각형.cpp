/*
    A4용지에 그려보면서 하니까 조금 감이 오긴하는데,
    아직 감을 잡았다고는 할 수 없는 단계인 것 같다.

    삼각형의 각 층의 값을 이용해 각 자리의 누적 최대값을 저장하는 식으로 계산한다.
    각 층의 가장 왼쪽, 가장 오른쪽은 바로 위의 누적값에 더해주는 방법 밖에 없다.(각각 왼쪽 대각선 위, 오른쪽 대각선 위가 하나씩 밖에 존재하지 않으므로)
    나머지 칸들은 자기의 왼쪽 위, 오른쪽 위 중 큰 값에 자기 값을 더해 값으로 가지면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[500][500];

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    int answer = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][0] + dp[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
            }

            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << "\n";

    return 0;
}