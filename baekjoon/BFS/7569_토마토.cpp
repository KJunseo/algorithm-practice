/*
    BFS로 풀었다.
    7576번 토마토의 업그레이드 버전이었다.
    위 상자, 아래 상자로도 움직일 수 있어야했다.
    나머지 과정은 동일했다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int R, C, H;
int cnt;
int box[100][100][100];
bool visit[100][100][100];
int dy[6]={1, -1, 0, 0, 0, 0};
int dx[6]={0, 0, -1, 1, 0, 0};
int dh[6]={0, 0, 0, 0, 1, -1};

struct Coordi {
    int y;
    int x;
    int h;
};

queue<pair<Coordi, int> > q;

void bfs() {

    while(!q.empty()) {
        int cur_y = q.front().first.y;
        int cur_x = q.front().first.x;
        int cur_h = q.front().first.h;
        int cur_d = q.front().second;
        q.pop();

        for(int i=0;i<6;i++) {
            int ny=cur_y+dy[i];
            int nx=cur_x+dx[i];
            int nh=cur_h+dh[i];

            if(nx<0 || ny<0 || nh<0 || nx>=C || ny>=R || nh>=H) continue;

            if(visit[ny][nx][nh]) continue;

            if(box[ny][nx][nh]==-1 || box[ny][nx][nh]==1) continue;

            Coordi next = {ny, nx, nh};

            box[ny][nx][nh]=1;
            q.push(make_pair(next, cur_d+1));
            visit[ny][nx][nh]=true;
        }
        cnt=cur_d;
    }
}

int main(void) {
    int temp;
    cin >> C >> R >> H;

    for(int k=0;k<H;k++) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                scanf("%d", &box[i][j][k]);
                Coordi cur={i, j, k};

                if(box[i][j][k]==1) {
                    temp++;
                    q.push(make_pair(cur, 0));
                    visit[i][j][k]=true;
                }
            }
        }
    }

    if(temp==R*C*H) {
        cout << 0;
        return 0;
    }

    bfs();

    for(int k=0;k<H;k++) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(box[i][j][k]==0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}