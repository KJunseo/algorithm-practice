/*
    BFS로 풀었다.
    이때까지 풀던 BFS와 조금 달랐다. 최단경로를 구해야했기 때문이다.
    큐에 넣을 때, 깊이를 나타내는 값을 하나 추가했다.
    인접 범위가 늘어날 수록 깊이+1을 해주었고, 목적지에 도착하면 종료시켰다.
    인접 범위가 같은 요소끼리는 어차피 같은 비용이 들기 때문이다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maze[101][101];
bool visit[101][101];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};

void bfs(int y, int x) {
    int answer;
    queue<pair<pair<int ,int>, int> > q;
    q.push(make_pair(make_pair(y, x), 0));
    visit[y][x]=true;

    while(!q.empty()) {
        int cur_y=q.front().first.first;
        int cur_x=q.front().first.second;
        int cur_d=q.front().second;
        q.pop();

        if(cur_y==N && cur_x==M) {
            answer=cur_d+1;
            break;
        }

        for(int i=0;i<4;i++) {
            int ny=cur_y+dy[i];
            int nx=cur_x+dx[i];

            if(ny<1 || nx<1 || ny>N || nx>M) continue;

            if(visit[ny][nx]) continue;

            if(maze[ny][nx]==0) continue;

            q.push(make_pair(make_pair(ny, nx), cur_d+1));
            visit[ny][nx]=true;
        }
    }

    printf("%d\n", answer);
}

int main(void) {

    cin >> N >> M;

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            scanf("%1d",&maze[i][j]);
        }
    }

    bfs(1, 1);

    return 0;
}