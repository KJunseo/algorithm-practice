/*
    BFS를 사용해야겠다고 생각은 했지만 생각보다 구현하는데 어려움을 겪었다..
    시작점부터 bfs를 통해 진행하여주었다.
    4방향 모두 청소한 경우는 해당 지점에서 4방향 모두 탐색했을 때 큐에 넣을 곳이 없는 경우이다.
    이 경우 후진 시켜서 조건에 따라 판단한다.
*/
#include <iostream>
#include <queue>

using namespace std;

struct robot {
    int y;
    int x;
    int dir;
};

int N, M;
int cnt;
int map[50][50];
robot start;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void bfs() {
    queue<robot> q;
    q.push({start.y, start.x, start.dir}); // 시작점 넣어주기

    while(!q.empty()) {
        // 현재 위치 
        int y=q.front().y;
        int x=q.front().x;
        int dir=q.front().dir;

        // 청소해야하는 곳이면 청소(2)하고 카운트 증가
        if(map[y][x]==0) {
            map[y][x]=2;
            cnt++;
        }

        q.pop();

        bool flag=false; // 4방향 모두 청소되었는지 확인하는 변수

        for(int i=0;i<4;i++) {
            int ndir=(dir+(3-i))%4; // 다음 방향 정해주기 
            int ny=y+dy[ndir];
            int nx=x+dx[ndir];

            if(ny>=0 && nx>=0 && ny<N && nx<M) {
                
                // 청소해야하는 곳이면
                if(!map[ny][nx]) {
                    q.push({ny, nx, ndir});
                    flag=true; // 청소할 곳이 있다고 나타내줌
                    break;
                }
            }
        }

        // 4방향 모두 청소할 곳이 없는 경우
        if(!flag) {

            // 이전 좌표(후진)
            int by=y-dy[dir];
            int bx=x-dx[dir];

            if(by>=0 && bx>=0 && by<N && bx<M) {

                // 후진을 할 수 있다면(벽이 아니면)
                if(map[by][bx]!=1) {
                    q.push({by, bx, dir});
                } else break;
            }
        }
    }
}

int main(void) {

    cin >> N >> M;

    cin >> start.y >> start.x >> start.dir;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    bfs();

    cout << cnt << "\n";

    return 0;
}