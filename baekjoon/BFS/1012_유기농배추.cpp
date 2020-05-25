/*
    BFS로 풀었다.
    상 하 좌 우 이동의 경우를 모두 따져주고 cnt를 세면된다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int cnt=0;
int field[50][50];
bool visit[50][50];
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

void bfs(int y, int x) {
    cnt++;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;

    while (!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(nx>=M || ny>=N || nx<0 || ny<0) continue;

            if(visit[ny][nx]) continue;

            if(field[ny][nx]==0) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }
    }   
}

int main(void) {
    int t;

    cin>>t;

    for(int i=0;i<t;i++) {
        int k;

        cin >> M >> N >> k;

        for(int j=0;j<N;j++) {
            fill(visit[j], visit[j]+M, false);
            fill(field[j], field[j]+M, 0);
        }

        for(int j=0;j<k;j++) {
            int x, y;

            cin >> x >> y;

            field[y][x]=1;
        }

        for(int col=0;col<N;col++) {
            for(int row=0;row<M;row++) {
                if(field[col][row]==0) continue;
                if(visit[col][row]) continue;
                bfs(col, row);
            }
        }

        printf("%d\n", cnt);
        cnt=0;
    }

    return 0;
}