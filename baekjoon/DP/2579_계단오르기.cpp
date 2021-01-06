/*
    dp문제는 아직 점화식 만들어내기가 쉽지 않다.
    감이 없는 것 같다. 많이 풀다보면 감이 생기겠지 뭐.

    계단을 오를 때 한 칸이나 두 칸을 오를 수 있고
    연속해서 3개는 오를 수 없고
    마지막 계단은 무조건 밟아야한다.

    score[i]를 i 번째 계단이 마지막 계단일 때의 점수라고 생각해보자.
    처음 3개의 계단을 보면
    score[0] = stair[0]의 값이 최대값이다.
    score[1] = stair[0] + stair[1]의 값이 최대값이다.
    score[2]은 처음 계단을 밟고 3번째 계단을 밟을 수도 있고, 처음 계단을 밟지 않고 2번, 3번 계단을 밟을 수도 있기 때문에 2가지 경우의 수 중 큰 값이 최대값이다.
    
    그 후로는 규칙이 보인다.
    i번째 계단의 최대값은 [i - 2번 계단까지의 최대값 + i번째 계단의 값] 또는 [i - 3번 계단까지의 최대값 + i - 1번 계단의 값 + i번째 계단의 값]중 더 큰 값이다.
    (두 번째 경우에서 i - 1번 계단까지의 최대값 + i번쨰 계단의 값으로 계산할 수 없는 이유는 '연속해서 3개는 오를 수 없다'는 조건 때문이다.)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stair[300];
int score[300];

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &stair[i]);
    }

    score[0] = stair[0];
    score[1] = stair[0] + stair[1];
    score[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++) {
        score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << score[n - 1] << "\n";

    return 0;
}