/*
    BFS를 두 번 사용했다.
    첫 번째 bfs로 각 섬의 좌표를 모두 저장하고(각 섬마다 다른 숫자로)
    두 번째 bfs로 각 섬마다 모든 좌표를 큐에 넣고 bfs를 돌렸다.
    다른 섬에 도착했을 때 해당 섬이 다른 숫자를 가지고 있는 경우 두 섬에 다리가 놓인 것이다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N;
int label=1;
int map[100][100];
int visit[100][100];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

// 첫 번째 bfs(각 섬을 서로 다른 숫자로 분리)
void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;
    map[y][x]=label;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;

            if(map[ny][nx]==0) continue;

            if(visit[ny][nx]) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
            map[ny][nx]=label;
        }
    }
    label++;
}

// 두 번째 bfs 두 섬 사이 다리 놓는 역할 
int findPath(int label) {
    queue<pair<int, int> > q;

    // 해당 섬의 모든 좌표를 큐에 넣음
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]==label) {
                visit[i][j]=true;
                q.push(make_pair(i, j));
            }
        }
    }

    int result=0;
    while(!q.empty()) {
        int size=q.size();
        for(int i=0;i<size;i++) {
            int y=q.front().first;
            int x=q.front().second;
            q.pop();

            for(int j=0;j<4;j++) {
                int ny=y+dy[j];
                int nx=x+dx[j];

                if(ny<0 || nx<0 || ny>=N || nx>=N) continue;

                // 육지이고 다른 섬인 경우 return 
                if(map[ny][nx] && map[ny][nx]!=label) return result;
                // 바다이고 방문하지 않은 경우 큐에 넣음 
                else if(!map[ny][nx] && !visit[ny][nx]) {
                    visit[ny][nx]=true;
                    q.push(make_pair(ny, nx));
                } 

            }

        }
        result++;
    }
}

int main(void) {
    int answer;
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]==0) continue;
            if(visit[i][j]) continue;
            bfs(i, j);
        }
    }

    for(int i=1;i<label;i++) {
        memset(visit, false, sizeof(visit));
        answer=min(answer, findPath(i));
    }

    cout << answer << endl;

    return 0;
}