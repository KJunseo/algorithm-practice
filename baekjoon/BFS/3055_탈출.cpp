/*
    BFS로 풀었다.
    한 번의 BFS로 풀 수도 있을 것 같았지만, 제일 처음 생각난 방법으로 풀었다.
    먼저 물이 범람하는 경우를 먼저 BFS로 계산하고
    그 후 고슴도치를 이동시킬 때, 물이 먼저 범람한 곳은 가지못하게 하였다.
*/
#include <iostream>
#include <queue>

using namespace std;

int R, C;
char map[50][50];
char water[50][50];
int m_visit[50][50];
int w_visit[50][50];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};
queue<pair<int, int> > m_q;
queue<pair<int, int> > w_q;

// 물이 범람하는 경우 
void w_bfs() {

    while(!w_q.empty()) {
        pair<int, int> cur = w_q.front();
        w_q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=R || nx>=C) continue; // 맵을 벗어나거나 

            if(w_visit[ny][nx]) continue; // 이미 방문했거나

            if(water[ny][nx]=='X' || water[ny][nx]=='*' || water[ny][nx]=='D') continue; // 돌이나, 이미 물이거나, 비버소굴이면 

            w_visit[ny][nx]=w_visit[cur.first][cur.second]+1;
            w_q.push(make_pair(ny, nx));
        }
    }
}

// 고슴도치가 이동하는 경우
void m_bfs() {

    while(!m_q.empty()) {
        pair<int, int> cur = m_q.front();
        m_q.pop();

        if(map[cur.first][cur.second]=='D') {
            cout << m_visit[cur.first][cur.second]-1 << endl;
            return;
        }

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=R || nx>=C) continue; // 맵을 벗어나거나

            if(m_visit[ny][nx]) continue; // 이미 방문했거나

            if(map[ny][nx]=='X' || map[ny][nx]=='*') continue; // 돌이나 물이거나 

            m_visit[ny][nx]=m_visit[cur.first][cur.second]+1;
            if(map[ny][nx]!='D' && w_visit[ny][nx]!=0 && w_visit[ny][nx]<=m_visit[ny][nx]) continue; // 도착지나 이미 물이 도착했거나

            m_q.push(make_pair(ny, nx));
        }
    }
    cout << "KAKTUS" << endl;
}

int main(void) {

    cin >> R >> C;

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> map[i][j];
            water[i][j]=map[i][j];

            if(map[i][j]=='S') {
                m_q.push(make_pair(i, j));
                m_visit[i][j]=true;
            } else if(map[i][j]=='*') {
                w_q.push(make_pair(i, j));
                w_visit[i][j]=true;
            }
        }
    }

    w_bfs();

    m_bfs();

    return 0;
}