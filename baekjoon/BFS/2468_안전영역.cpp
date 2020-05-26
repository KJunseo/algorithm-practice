/*
    BFS로 풀었다.
    지역을 입력받으면서 가장 낮은 지역의 높이와, 가장 높은 지역의 높이를 구해서
    가장 낮은 높이 ~ 가장 높은 높이를 반복하면서, 해당 높이보다 높은 지역들의 영역을 세어
    가장 많은 안전 지역을 구하였다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int cnt;
int area[100][100];
bool visit[100][100];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};

void bfs(int y, int x, int height) {
    cnt++;
    queue<pair<int, int> > q;

    q.push(make_pair(y, x));
    visit[y][x]=true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(nx>=N || ny>=N || nx<0 || ny<0) continue;

            if(visit[ny][nx]) continue;

            if(area[ny][nx]<=height) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }
    }
}

int main(void) {
    int max_height=0;
    int min_height=100;
    int answer=1;

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &area[i][j]);
            if(max_height<area[i][j]) max_height=area[i][j];
            if(min_height>area[i][j]) min_height=area[i][j];
        }
    }

    for(int i=min_height;i<=max_height;i++) {
        cnt=0;

        for(int j=0;j<N;j++) {
            fill(visit[j], visit[j]+N, false);
        }

        for(int row=0;row<N;row++) {
            for(int col=0;col<N;col++) {
                if(area[row][col]<=i) continue;
                if(visit[row][col]) continue;
                bfs(row, col, i);
            }
        }
        if(answer<cnt) answer=cnt;
    }

    printf("%d", answer);

    return 0;
}
