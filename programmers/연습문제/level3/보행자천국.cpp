/*
    dfs로 해보려했으나 실패했다.
    결국 또 dp문제였다. dp는 아직 감이 안 잡힌다..

    왼->오 로 진행되는 배열하나와
    위->아래 로 진행되는 배열하나를 사용한다.

    각 지점 처음은 각각 경우의 수 1이다.
    그 다음 city_map의 값에 따라 달라진다.
    city_map이 0일 경우는 각 배열에 왼쪽에서 오는 값+위에서 오는 값을 더해준다.
    city_map이 1일 경우는 갈 수 없으므로 두 배열모두 0이다.
    city_map이 2일 경우는 왼->오 배열은 왼쪽 값만, 위->아래 배열은 위쪽 값만을 그대로 준다.
*/
#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;
int right[501][501]; // 왼 -> 오
int bottom[501][501]; // 위 -> 아래 

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(right, 0 ,sizeof(right));
    memset(bottom, 0 ,sizeof(bottom));
    
    right[1][1]=bottom[1][1]=1; // 각 배열 시작지점 경우의 수는 각각 1
    
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(city_map[i-1][j-1]==0) { // 모두 가능한 경우이므로 왼쪽에서 오는 값 + 위쪽에서 오는 값 
                right[i][j]=(right[i][j]+right[i][j-1]+bottom[i-1][j])%MOD; 
                bottom[i][j]=(bottom[i][j]+right[i][j-1]+bottom[i-1][j])%MOD;
            } else if(city_map[i-1][j-1]==1) { // 갈 수 없는 경우이므로 0 
                right[i][j]=bottom[i][j]=0;
            } else if(city_map[i-1][j-1]==2) { // 같은 방향만 가능하므로 왼->오 배열은 왼쪽 값, 위->아래 배열은 위쪽 값
                right[i][j]=right[i][j-1];
                bottom[i][j]=bottom[i-1][j];
            }
        }
    }
    
    return right[m][n];
}