/*
    BFS를 이용하여 풀었다.
    map을 사용하여 처음에는 R G B 로 구분하였고,
    그 다음에는 G를 모두 R로 바꾼후 R B 로 구분하였다.
    조금 지저분한 느낌이 없지않아 있다.
*/
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char board[100][100];
bool visit[100][100];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};
map<char, int> m;

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;

    char color=board[y][x];
    m[board[y][x]]++;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;

            if(visit[ny][nx]) continue;

            if(color!=board[ny][nx]) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }
    }
}

int main(void) {
    int answer;
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visit[i][j]) continue;
            bfs(i, j);
        }
    }

    answer=m.find('R')->second + m.find('G')->second + m.find('B')->second;

    printf("%d ", answer);

    for(int i=0;i<N;i++) {
        fill(visit[i], visit[i]+N, false);
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j]=='G') board[i][j]='R';
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visit[i][j]) continue;
            bfs(i, j);
        }
    }

    answer=m.find('R')->second + m.find('G')->second + m.find('B')->second - answer;

    printf("%d", answer);

    return 0;
}