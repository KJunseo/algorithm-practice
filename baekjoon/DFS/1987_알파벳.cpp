/*
    처음에 BFS로 해결하려고 했으나, 테스트케이스를 통과했지만 이유를 모르겠는데 제출하자마자 틀렸다고 떴다.
    DFS를 이용한 백트래킹으로 풀어야한다고 한다.
    dfs에 조건을 줘서 백트래킹을 진행했다.
*/
#include <iostream>

using namespace std;

int R, C;
int answer=0;
char board[21][21];
bool alpabet[26];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};

void dfs(int y, int x, int cnt) {
    if(answer<cnt) {
        answer=cnt;
    }

    for(int i=0;i<4;i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<0 || nx<0 || ny>=R || nx>=C) continue;

        if(alpabet[board[ny][nx]-65]) continue;

        alpabet[board[ny][nx]-65]=true;

        dfs(ny, nx, cnt+1);

        alpabet[board[ny][nx]-65]=false;

    }
}

int main(void) {

    cin >> R >> C;

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> board[i][j];
        }
    }

    alpabet[board[0][0]-65]=true;
    dfs(0, 0, 1);

    printf("%d", answer);

    return 0;
}

/*
// 실패한 BFS
void bfs(int y, int x, int cnt) {
    cnt++;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    alpabet[board[y][x]-65]=true;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=R || nx>=C) continue;

            if(alpabet[board[ny][nx]-65]) continue;

            q.push(make_pair(ny, nx));
            alpabet[board[ny][nx]-65]=true;
            cnt++;
        }
    }
}
*/