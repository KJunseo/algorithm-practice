/*
    dfs로 하면 될 것 같아서 dfs로 풀어 테스트케이스는 통과했는데
    채점해보니까 전부 시간 초과가 나왔다..

    dp 문제였다.

    아직 dp문제는 이걸 dp로 풀어야되는지도 잘 모르겠고, 어떻게 적용하는지도 잘 모르겠다.
*/
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land) {
    int answer=0;
    int row=land.size();
    int col=4;
    int dp[row][col];
    
    // 초기화 
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            dp[i][j]=0;
        }
    }

    // 제일 첫째 행은 자기 자신 
    for(int i=0;i<col;i++) {
        dp[0][i]=land[0][i];
    }

    // 둘째 행부터는 각 칸이 가질 수 있는 최대값으로 업데이트해줌
    for(int i=1;i<row;i++) {
        for(int j=0;j<col;j++) {
            for(int k=0;k<col;k++) {
                if(j!=k) {
                    dp[i][j]=max(dp[i][j], land[i][j]+dp[i-1][k]);
                }
            }
        }
    }

    // 마지막 행의 가장 큰 열의 값이 정답
    for(int i=0;i<col;i++) {
        answer=max(answer, dp[row-1][i]);
    }

    return answer;
}