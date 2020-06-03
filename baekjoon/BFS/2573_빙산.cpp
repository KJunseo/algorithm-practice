/*
    BFS로 풀었다.
    난이도를 보고 실패할 거 같았는데, 풀어내서 기분이 좋았다.
    무한 루프를 돌면서 bfs를 수행했다. bfs가 수행되는 횟수가 빙산의 그룹 수이기 때문에
    bfs가 수행되는 수가 2이상이면 종료하였다. 또한 bfs가 한 번도 수행되지 않으면 빙산이 없기 때문에 종료하였다.
    빙산을 나타내는 배열 하나로 문제를 풀려고 하면, 빙산을 동시에 녹일 수 없기 때문에 origin이라는 같은 배열을 하나 더 사용했다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
int iceberg[300][300];
int origin[300][300];
int visit[300][300];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        int zerocnt=0;
        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;

            if(origin[ny][nx]==0) {
                zerocnt++;
                continue;
            }

            if(visit[ny][nx]) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }

        iceberg[cur.first][cur.second]-=zerocnt;
        if(iceberg[cur.first][cur.second]<0) iceberg[cur.first][cur.second]=0;
    }
}

int main(void) {
    int year=0;
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%d", &iceberg[i][j]);

            origin[i][j]=iceberg[i][j];
        }
    }

    while(true) {

        for(int i=0;i<N;i++) {
            memset(visit[i], false, sizeof(visit[i]));
        }

        int cnt=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(iceberg[i][j]==0) continue;
                if(visit[i][j]) continue;
                bfs(i, j);
                cnt++;
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                origin[i][j]=iceberg[i][j];
            }
        }

        if(cnt>=2) break;
        else if(cnt==0) {
            year=0;
            break;
        }
        year++;
    }

    printf("%d\n", year);

    return 0;
}