/*
    BFS로 풀었다.
    처음에는 익은 토마토가 하나라고만 생각했었는데, 테스트 케이스를 보니 여러개인 경우도 있었다.
    그래서 bfs에서 큐를 만들지 않고, 큐를 미리 만들고, 익은 토마토의 위치를 큐에 넣고 bfs를 시작했다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int cnt;
int box[1000][1000];
bool visit[1000][1000];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};
queue<pair<pair<int ,int>, int> > q;

void bfs() {

    while(!q.empty()) {
        int cur_y=q.front().first.first;
        int cur_x=q.front().first.second;
        int cur_d=q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur_y+dy[i];
            int nx=cur_x+dx[i];

            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;

            if(visit[ny][nx]) continue;

            if(box[ny][nx]==-1 || box[ny][nx]==1) continue;

            box[ny][nx]=1;
            q.push(make_pair(make_pair(ny, nx), cur_d+1));
            visit[ny][nx]=true;
        }
        cnt=cur_d;
    }
}

int main(void) {

    cin >> M >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%d", &box[i][j]);

            if(box[i][j]==1) {
                q.push(make_pair(make_pair(i, j), 0));
                visit[i][j]=true;
            }
        }
    }

    bfs();

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(box[i][j]==0) cnt=-1;
        }
    }
    printf("%d\n", cnt);

    return 0;
}