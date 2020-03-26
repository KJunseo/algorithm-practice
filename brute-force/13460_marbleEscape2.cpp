/*
    조건도 많고, bfs로 해결하려 시도해보았으나 성공하지 못했다. 개인적으로 너무 어려웠다.

    1. 빨간 구슬과, 파란 구슬의 위치를 기억한다.
    2. 방문처리를 한 후, 큐에 넣는다.
    3. bfs를 수행한다.
    3-1. 현재 빨간 구슬과, 파란 구슬의 좌표를 가져온다.
    3-2. 위, 아래, 오른쪽, 왼쪽으로 벽이나 구멍이 나올때까지 이동시킨다.
    3-3. 파란 구슬이 구멍에 도착한 경우는 무시한다.
    3-4. 빨간 구슬이 구멍에 도착한 경우 이동한 횟수를 출력하고 종료한다,
    3-5. 만약 빨간구슬과 파란구슬의 이동 후 위치가 같다면, 움직인 거리가 긴 구슬을 한 칸 뒤로 움직인다.
    3-6. 10번을 움직여도 구멍에 도착하지 못하면 -1을 출력한다.
    3-7. 더 이상 갈 곳이 없는 경우도 -1을 출력한다.
*/
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	pair<int, int> R;
	pair<int, int> B;
    int d;
} Marble;

typedef struct {
	int y,x;
} Dir;

Dir go[4] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int n, m;
char board[10][10];
bool check[10][10][10][10];
queue<Marble> q;

// bfs로 큐가 빌 때 까지 반복
void bfs() {
    while (!q.empty()) {
		int ry = q.front().R.first, rx = q.front().R.second; // 현재 빨간 구슬 좌표 가져오기
		int by = q.front().B.first, bx = q.front().B.second; // 현재 파란 구슬 좌표 가져오기 
        int d = q.front().d; // 현재까지 움직인 횟수 가져오기
		q.pop();
        
		if (d >= 10) break; // 10번 움직여도 구멍에 들어가지 못했으면, -1 출력

        // 구슬은 위, 아래, 왼쪽, 오른쪽 으로 움직일 수 있다.
        for (int i=0; i<4; i++) {
            int nextRy = ry, nextRx = rx; 
			int nextBy = by, nextBx = bx;
            int rCnt = 0, bCnt = 0; // 겹쳐질 경우를 제외하기 위한 움직인 거리 카운트
			int nextD = d+1;

            // 벽이나 구멍을 만나기 전까지 빨간구슬 이동
			while(board[nextRy+go[i].y][nextRx+go[i].x]!='#' && board[nextRy][nextRx]!='O') {
				nextRy+=go[i].y;
				nextRx+=go[i].x;
				rCnt++;
			}

            // 벽이나 구멍을 만나기 전까지 파란구슬 이동
			while(board[nextBy+go[i].y][nextBx+go[i].x]!='#' && board[nextBy][nextBx]!='O') {
				nextBy+=go[i].y;
				nextBx+=go[i].x;
				bCnt++;
			}

            // 파란 구슬이 구멍에 먼저 들어갔으면 무효처리
            if (board[nextBy][nextBx] == 'O') continue; 

            // 빨간 구슬이 구멍에 먼저 들어간 경우, 움직인 횟수 출력 후 종료
            if (board[nextRy][nextRx] == 'O') {
                printf("%d\n", nextD);
                return;
            }

            // 파란 구슬과 빨간 구슬이 겹쳐진 경우 
            if (nextRy == nextBy && nextRx == nextBx) {

                // 빨간 구슬이 파란 구슬보다 더 많이 움직였으면, 
                // 파란 구슬이 현재위치에 먼저 도착한 것이므로,
                // 빨간 구슬을 한 칸 뒤로 이동
                if (rCnt > bCnt) {
					nextRy-=go[i].y; 
					nextRx-=go[i].x;
				} else {
					nextBy-=go[i].y;
					nextBx-=go[i].x;
				}
            }

            // 빨간 구슬과 파란 구슬이 방문한 곳 방문 처리
            // 이미 방문한 경우 큐에 넣어주지 않음 
            if (check[nextRy][nextRx][nextBy][nextBx]) continue;
            check[nextRy][nextRx][nextBy][nextBx] = true;

            // 움직인 빨간 구슬, 파란 구슬 좌표와 움직인 횟수 큐에 넣어줌
			q.push({make_pair(nextRy, nextRx), make_pair(nextBy, nextBx), nextD});
        }
    }
    printf("-1\n");
}

int main() {
	pair<int, int> R, B;

    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++) {
		getchar();
        for (int j=0; j<m; j++) {
            scanf("%c", &board[i][j]);
			
            if (board[i][j] == 'R') { // 빨간 구슬의 좌표 기억 
				R.first=i;
				R.second=j;
			}
            else if (board[i][j] == 'B') { // 파란 구슬의 좌표 기억 
				B.first=i;
				B.second=j;
			}
        }
    }

	q.push({R, B, 0}); // 빨간 구슬 좌표, 파란 구슬 좌표, 움직인 횟수 큐에 넣어줌

    check[R.first][R.second][B.first][B.second] = true; // 큐에 넣어준 빨간 구슬, 파란 구슬 좌표 방문 처리

    bfs();

    return 0;
}

