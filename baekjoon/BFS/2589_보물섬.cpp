/*
    BFS로 풀었고 크게 어렵지 않았다.
    모든 땅에서 BFS를 수행해 가장 멀리 갈 수 있는 경우를 업데이트 해주면 된다.
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int R, C;
int ans;
char map[50][50];
int visit[50][50];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

void bfs(int y, int x) {
    int d=0;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=R || nx>=C) continue;

            if(visit[ny][nx]) continue;

            if(map[ny][nx]=='W') continue;

            visit[ny][nx]=visit[cur.first][cur.second]+1;
            d=visit[cur.first][cur.second];
            q.push(make_pair(ny, nx));
        }
    }

    if(ans<d) ans=d;
}

int main(void) {
    vector<pair<int, int> > land;
    cin >> R >> C;

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> map[i][j];

            if(map[i][j]=='L') land.push_back(make_pair(i, j));
        }
    }

    for(int i=0;i<land.size();i++) {
        memset(visit, 0, sizeof(visit));
        bfs(land[i].first, land[i].second);
    }

    cout << ans << endl;

    return 0;
}