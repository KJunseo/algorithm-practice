/*
    BFS로 풀었다.
    입력받은 직사각형들로 영역을 나누고 각 영여 별로 BFS를 진행시켜주면 된다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int area;
vector<int> answer;
int board[100][100];
bool visit[100][100];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};

void bfs(int y, int x) {
    area++;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;
    int cnt=1;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny = cur.first+dy[i];
            int nx = cur.second+dx[i];

            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;

            if(visit[ny][nx]) continue;
            
            if(board[ny][nx]==1) continue;

            cnt++;
            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }
    }
    answer.push_back(cnt);
}

int main(void) {

    cin >> M >> N >> K;

    for(int i=0;i<K;i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        for(int r=y1;r<y2;r++) {
            for(int c=x1;c<x2;c++) {
                board[r][c]=1;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(board[i][j]==1) continue;
            if(visit[i][j]) continue;
            bfs(i,j);
        }
    }

    sort(answer.begin(), answer.end());

    cout << area << endl;

    vector<int>::iterator iter;
    for(iter=answer.begin();iter!=answer.end();iter++) {
        cout << *iter << " ";
    }


    return 0;
}