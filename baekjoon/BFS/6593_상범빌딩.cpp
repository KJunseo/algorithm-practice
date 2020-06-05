/*
    dfs를 사용하려고 하였으나 값이 제대로 나오지 않았다.
    최단거리를 구하는 문제는 BFS를 사용하는 게 더 낫다고 한다.
    bfs는 도착점을 발견하면 종료되지만, dfs는 모든 경로를 탐색하기 때문에 비효율적이라고 한다.

    bfs의 시작점을 S의 좌표로 하고, E를 만나면 시간을 출력, 못 만나면 trapped을 출력한다.
    시간은 탐색 순서와 동일하다.
    시작점에서 떨어진 정도이다.
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int y;
    int x;
    int z;
} Coordi;

int L, R, C;
char building[30][30][30];
int visit[30][30][30];
int dy[]={1, -1, 0, 0, 0, 0};
int dx[]={0, 0, 1, -1, 0, 0};
int dz[]={0, 0, 0, 0, 1, -1};

void bfs(int y, int x, int z) {
    queue<Coordi> q;
    Coordi temp = {y, x, z};
    q.push(temp);

    while(!q.empty()) {
        Coordi cur = q.front();
        q.pop();

        if(building[cur.y][cur.x][cur.z]=='E') {
            cout << "Escaped in " << visit[cur.y][cur.x][cur.z] << " minute(s)." << endl;
            return;
        }

        for(int i=0;i<6;i++) {
            int ny=cur.y+dy[i];
            int nx=cur.x+dx[i];
            int nz=cur.z+dz[i];

            if(ny<0 || nx<0 || nz<0 || ny>=R || nx>=C || nz>=L) continue;

            if(building[ny][nx][nz]=='#') continue;

            if(visit[ny][nx][nz]) continue;

            Coordi nCoordi = {ny, nx, nz};
            q.push(nCoordi);
            visit[ny][nx][nz]=visit[cur.y][cur.x][cur.z]+1;
        }
    }

    cout << "Trapped!" << endl;
}

int main(void) {
    int s_y, s_x, s_z;
    int e_y, e_x, e_z;

    while(true) {
        cin >> L >> R >> C;

        if(L==0 && R==0 && C==0) break;

        memset(visit, 0, sizeof(visit));

        for(int k=0;k<L;k++) {
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++) {
                    cin >> building[i][j][k];

                    if(building[i][j][k]=='S') {
                        s_y=i;
                        s_x=j;
                        s_z=k;
                    }
                }
            }
        }

        bfs(s_y, s_x, s_z);
    }

    return 0;
}