/*
    이동하는데 확률이 있다고 하니 어떻게 접근해야할지 감이 잡히지 않았다..

    dfs를 이용하고, 트리에서 엣지를 지나가면 확률이 곱해진다고 생각하면 된다고 한다.

    경로 이동시 해당 방향의 확률을 곱해준다.
    만약 무사히 이동하였으면 단순한 경로이다.

    아직도 잘 이해가 되지 않긴 한다.
*/
#include <iostream>
#define MAX 29 // N 최대값이 14이므로 

using namespace std;

int N;
double result;
double p[4]; // 동 서 남 북 확률 
int visit[MAX][MAX];
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

// cnt: 반복 횟수   probability: 현재 확률
void dfs(int y, int x, int cnt, double probability) {

    // N번 만큼 다 움직인 경우(단순한 경로인 경우) 
    if(cnt==N) {
        result+=probability; // 결과값에 현재 확률을 더해줌
        return;
    }

    visit[y][x]=true;

    // 동 서 남 북 이동 
    for(int i=0;i<4;i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];

        // 방문 하지 않은 곳이면
        if(!visit[ny][nx]) {
            dfs(ny, nx, cnt+1, probability*p[i]); // 카운트 증가, 확률 * 해당 방향 확률 
        }
    }

    visit[y][x]=false; // 방문 해제
}

int main(void) {

    cin >> N;

    // 동 서 남 북 확률을 입력받음 
    for(int i=0;i<4;i++) {
        cin >> p[i];
        p[i]/=100.0;
    }

    result=0.0;
    dfs(14, 14, 0, 1.0); // map의 중앙은 14, 14 
    
    printf("%.10lf\n", result);

    return 0;
}