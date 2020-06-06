/*
    최단 경로 문제여서 BFS를 사용했다.
    벽을 부술 수 있다는 조건이 있으므로, visit배열에 벽을 부순경우와 안부순경우 두 가지 배열이 필요했다.
    이미 방문한 곳이여도, 벽을 부순경우와 아직 부수지 않은 경우의 경로가 달라지기 때문이다.

    큐에 넣을 수 있는 경우는 두 가지이다.
    1. 다음 칸이 벽이고, 벽을 부술 수 있는 경우
    2. 다음 칸이 벽이 아니고, 벽을 이미 부쉈거나, 아직 부수지 않은 경우
*/
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int y;
    int x;
    int destroy;
    int d;
} Node;

int N, M;
int map[1001][1001];
int visit[1001][1001][2];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

void bfs(int y, int x) {
    queue<Node> q;
    Node start = {y, x, 0, 1};
    q.push(start);
    visit[y][x][0]=true;

    while(!q.empty()) {
        int cy=q.front().y;
        int cx=q.front().x;
        int destroy=q.front().destroy;
        int d=q.front().d;
        q.pop();

        if(cy==N && cx==M) {
            cout << d << endl;
            return;
        }

        for(int i=0;i<4;i++) {
            int ny=cy+dy[i];
            int nx=cx+dx[i];

            if(ny<1 || nx<1 || ny>N || nx>M) continue;

            if(map[ny][nx]==1 && destroy==0) {
                visit[ny][nx][destroy+1]=true;
                Node newNode={ny, nx, destroy+1, d+1};
                q.push(newNode);
            } else if(map[ny][nx]==0 && !visit[ny][nx][destroy]) {
                visit[ny][nx][destroy]=true;
                Node newNode={ny, nx, destroy, d+1};
                q.push(newNode);
            }
        }
    }
    cout << -1 << endl;
}

int main(void) {

    cin >> N >> M;

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(1, 1);

    return 0;
}