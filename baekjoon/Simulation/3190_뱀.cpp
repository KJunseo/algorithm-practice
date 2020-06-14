/*
    시뮬레이션 문제가 생각보다 힘들다.
    차근차근 구현하여 다 되었다고 생각해도 결과가 잘 안나온다.
    다른 풀이를 봐도 풀이 방법은 비슷하게 한 것 같은데 구현능력이 아직 부족한 것 같다..
    문제 이해 능력도 조금 부족한 것 같다.
*/
#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
int L;
int y, x, d;
int map[100][100]; // 0: 빈 곳, 1: 사과, 2: 뱀 
int second;
queue<pair<int, char> > q; // 명령어
queue<pair<int, int> > snake; // 뱀의 꼬리와 머리 좌표 

// 동 남 서 북
int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};

int main(void) {

    cin >> N;
    cin >> K;

    for(int i=0;i<K;i++) {
        int row, col;

        cin >> row >> col;

        map[row-1][col-1]=1; // 0이 아니라 1이 시작점이기 때문
    }

    cin >> L;

    for(int i=0;i<L;i++) {
        int X;
        char C;

        cin >> X >> C;
        
        q.push(make_pair(X, C));
    }

    map[0][0]=2; // 처음 위치 방문 처리 
    snake.push(make_pair(0, 0)); 

    while(true) {
        // 방향에 따른 뱀의 다음 위치
        int ny=y+dy[d]; 
        int nx=x+dx[d];
        second++;

        // 벽을 만날 경우 종료 
        if(ny<0 || nx<0 || ny>=N || nx>=N) {
            cout << second << "\n";
            return 0;
        }

        // 자기 몸을 만날 경우 종료 
        if(map[ny][nx]==2) {
            cout << second << "\n";
            return 0;
        }

        // 빈 곳인 경우 꼬리 삭제 
        if(map[ny][nx]==0) {
            map[snake.front().first][snake.front().second]=0; 
            snake.pop();
        }

        // 머리 위치는 사과든 아니든 항상 방문
        map[ny][nx]=2;
        snake.push(make_pair(ny, nx));

        // 방향을 이동해야하는 경우
        if(second==q.front().first) {
            char command=q.front().second;

            if(command=='D') {
                d+=1;
                if(d==4) d=0;
            } else if(command=='L') {
                d-=1;
                if(d==-1) d=3;
            }
            q.pop();
        }

        y=ny;
        x=nx;
    }

    return 0;
}