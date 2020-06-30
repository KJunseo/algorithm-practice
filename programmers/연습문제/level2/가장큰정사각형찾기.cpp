/*
    board를 순회하면서 1인 부분이면 그 부분을 기준으로 한 변의 길이를 늘려가면서
    내부가 모두 1인 최대 길이를 찾는식으로 풀었으나 실패하여 검색을 통해 풀이를 알아냈다.

    DP 문제라고 한다. DP문제는 아직 경험이 거의 없어 잘 모른다..

    이 문제 같은 경우는 오른쪽 아래를 기준으로 생각하고 푼다.
    dp배열을 만든다. dp[i][j]의 뜻은 오른쪽 아래가 i, j일때 최대로 만들 수 있는 정사각형 크기를 뜻한다.
    i,j를 기준으로 왼쪽, 위쪽, 왼&위쪽 중 최솟값에 1을 더해주고 자기자신의 값을 곱해준다. 자기자신이 0일 경우 0을 표시하기 쉽기 때문이다. 

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board) {
    int answer = 0;

    for(int i=1;i<=board.size();i++) {
        for(int j=1;j<=board[0].size();j++) {
            dp[i][j]=(min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1)*board[i-1][j-1];
            answer=max(answer, dp[i][j]);
        }
    }


    return answer*answer;
}