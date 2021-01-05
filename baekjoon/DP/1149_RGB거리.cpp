/*
    오랜만?에 알고리즘 문제 풀이를 다시 시작했다. 
    2학기에 ps 수업을 들었고, 종강이후 지금까지 알고리즘 풀이를 쉬다가 오늘(1/5)부터 다시 시작했다.
    몇 주 쉬었다고 좀 안되는 느낌을 받았고, 1문제씩이라도 꾸준히 해야겠다고 생각했다.
    개인적으로 dp가 제일 부족하다고 생각해서 당분간 dp문제를 풀려고 한다.

    -----------------------------------------------------------------------------

    이 문제는 인접한 집끼리는 같은 색을 칠해서는 안된다.
    그러므로 i번째 집의 색은 i-1번째 집의 색과 다른 두 색 중 하나를 칠해야한다.
    
    언뜻보면 가장 최소의 색을 계속 칠하면 된다고 생각할 수 있으나 인접한 집끼리 같은 색을 칠해서는 안된다는 조건 때문에 가장 최소의 색을 칠하는 것만으로는 최소의 답을 찾는다고 볼 수 없다.
    
    home[i][j](0 <= j < 3)
    i = i번째 집
    j = 0: 색깔 R
    j = 1: 색깔 G
    j = 2: 색깔 B

    따라서 아래와 같이 생각할 수 있다.
    i번째 집을 R로 칠할 때의 총 최소 비용 -> home[i][0]
    i번째 집을 G로 칠할 때의 총 최소 비용 -> home[i][1]
    i번째 집을 B로 칠할 때의 총 최소 비용 -> home[i][2]

    각 값을 구하기 위해서 아래와 같이 계산할 수 있다.
    home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0]
    home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1]
    home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2]
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cost[1000][3];
int home[1000][3];

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    home[0][0] = cost[0][0];
    home[0][1] = cost[0][1];
    home[0][2] = cost[0][2];

    for (int i = 1; i < n; i++) {
        home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
        home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
        home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
    }

    int answer = home[n - 1][0];
    for (int i = 1; i < 3; i++) {
        answer = min(answer, home[n - 1][i]);
    }

    cout << answer << "\n";

    return 0;
}