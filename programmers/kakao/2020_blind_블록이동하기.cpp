/*
    BFS를 사용해서 풀어야한다고 한다.
    아직 BFS 문제를 많이 풀어보지 못해 어려움을 겪었다.

    로봇에 대한 구조체에 (x좌표, y좌표, 방향)을 표시하고, 방향에 따라 로봇이 좌표 두 칸을 모두 알아낼 수 있다.

    체크해야하는 경우는 8가지로, 
    상 하 좌 우 이동(4가지)
    로봇의 첫째 칸 기준으로 시계, 반시계 회전(2가지)
    로봇의 둘째 칸 기준으로 시계, 반시계 회전(2가지) 이다.
    가능한 움직임을 큐에 넣어주면서 진행한다.

    방문 체크는 x,y를 기준으로 한다

    참고: https://regularmember.tistory.com/177
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 로봇 구조체 
struct Robot {
    int x;
    int y;
    int d;
    int time;
};

struct Dir {
    int x;
    int y;
};

struct nDir {
    int x;
    int y;
};

// 이동방법 
Dir dir[4] = {
    {0, 1}, 
    {1, 0},
    {0, -1},
    {-1, 0}
};

// 회전시 지나치는 곳 
nDir ndir[4] = {
    {-1, 1},
    {1, 1},
    {1, -1},
    {-1, -1}
};
int N;
bool visit[100][100][4];

// board를 벗어나지 않는지 체크 
bool check(int x, int y, int xx, int yy) {
    if(x<0 || x>=N || y<0 || y>=N) return false;
    if(xx<0 || xx>=N || yy<0 || yy>=N) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    N=board.size();
    // 목적지 좌표
    int destX=N-1; 
    int destY=N-1;
    int answer = 0;
    queue<Robot> q;

    q.push({0, 0, 0, 0}); // 제일 처음 좌표와, 가로방향, 시간 0초 를 넣어준다.
    visit[0][0][0] = true; // 방문 처리

    while(!q.empty()) {
        int x=q.front().x;
        int y=q.front().y;
        int d=q.front().d;
        int time=q.front().time;
        q.pop();

        // 방향에 따라 로봇의 나머지 칸 확인 
        int xx=x+dir[d].x;
        int yy=y+dir[d].y;

        // 로봇의 한 칸이라도 목적지에 도달할 경우 종료
        if(x==destX && y==destY) return time; 
        if(xx==destX && yy==destY) return time;

        // 다음 좌표
        int nx, ny, nxx, nyy;

        // 상, 하, 좌, 우 확인 
        for(int i=0;i<4;i++) {
            nx=x+dir[i].x;
            ny=y+dir[i].y;
            nxx=xx+dir[i].x;
            nyy=yy+dir[i].y;

            if(!check(nx, ny, nxx, nyy)) continue; // board 범위를 벗어나는지 확인 
            if(visit[nx][ny][d]) continue; // 이미 방문한 경우 
            if(board[nx][ny]==1 || board[nxx][nyy]==1) continue; // 이동 가능 여부 확인 

            visit[nx][ny][d]=true;
            q.push({nx, ny, d, time+1});
        }

        // x, y 기준으로 시계, 반시계 회전
        for(int i=1;i<4;i+=2) {
            int nd=(d+i)%4;
            nxx=x+dir[nd].x;
            nyy=y+dir[nd].y;

            int rx, ry; // 회전할 때 부딪힐 수 있는 좌표
            if(i==1) { // 시계 방향
                rx=x+ndir[nd].x;
                ry=y+ndir[nd].y;
            } else { // 반시계 방향
                rx=x+ndir[d].x;
                ry=y+ndir[d].y;
            }

            if(!check(rx, ry, nxx, nyy)) continue;
            if(visit[x][y][nd]) continue;
            if(board[nxx][nyy]==1) continue;
            if(board[rx][ry]) continue;

            visit[x][y][nd]=true;
            q.push({x, y, nd, time+1});
        }

        // 나머지 로봇 좌표를 기준으로 시계, 반시계 방향 회전
        d=(d+2)%4; // 방향이 반대 
        for(int i=1;i<4;i+=2) {
            int nd=(d+i)%4;
            nx=xx+dir[nd].x;
            ny=yy+dir[nd].y;
 
            int rx, ry; // 회전할 때 부딪힐 수 있는 좌표
            if(i==1) { //시계방향 
                rx=xx+ndir[nd].x;
                ry=yy+ndir[nd].y;
            } else { //반시계방향 
                rx=xx+ndir[d].x;
                ry=yy+ndir[d].y;
            }
 
            if(!check(nx, ny, rx, ry)) continue;
            if(board[nx][ny] == 1) continue;
            if(board[rx][ry] == 1) continue;
 
            nd=(nd+2)%4;
            if(visit[nx][ny][nd]) continue;
            visit[nx][ny][nd] = true;
            q.push({nx, ny, nd, time+1});
        }
        if(q.empty()) answer=time;
    }
    
    return answer;
}