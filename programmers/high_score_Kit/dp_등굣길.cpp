/*
    경로의 경우의 수를 저장해가면서 계산하면 될 거 같았는데, 그 방법을 생각해내지 못했다.

    (x, y)칸까지의 경로 수 =  (x-1, y)칸까지의 경로 수 + (x, y-1)칸까지의 경로 수

    위의 공식을 이용하면 된다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int grid[n+1][m+1]; // 전체 격자 

    // 격자 초기화 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            grid[i][j]=1;
        }
    }
    
    // 물 웅덩이 0으로 초기화
    for(int i=0;i<puddles.size();i++) {
        grid[puddles[i][1]][puddles[i][0]]=0;
        
        // 맨 위 가로줄에 물 웅덩이가 있는 경우,
        // 웅덩이보다, 오른편에 있는 곳은 최단경로로 갈 수 없기 때문에 웅덩이가 있는 것과 마찬가지이다.
        if(puddles[i][0]==1) {
            for(int j=puddles[i][1];j<=n;j++) grid[j][1]=0;
        }

        // 맨 왼편 세로줄에 물 웅덩이가 있는 경우,
        // 웅덩이보다, 아래쪽에 있는 곳은 최단 경로로 갈 수 없기 때문에 웅덩이가 있는 것과 마찬가지이다.
        if(puddles[i][1]==1) {
            for(int j=puddles[i][0];j<=m;j++) grid[1][j]=0;
        }
    }
    
    // (x, y)칸까지의 경로 수 =  (x-1, y)칸까지의 경로 수 + (x, y-1)칸까지의 경로 수)
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=m;j++) {

            // 물 웅덩이인 경우는 무시
            if(grid[i][j]!=0) {
                grid[i][j]=(grid[i-1][j] + grid[i][j-1]) % 1000000007;
            }
        }
    }
    
    answer=grid[n][m];
    
    return answer;
}