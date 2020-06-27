/*
    어렵진 않은 문제이다.
    직진 시키다가 오른쪽 -> 아래 -> 왼쪽 -> 위 순서로 방향을 바꿔주고 바꿔주는 횟수를 센다.
    방향을 바꿨는데도 길이 막혀있다면 모든 곳을 방문한 것이므로 종료시킨다.
*/
#include <iostream>

using namespace std;

int N, M;
int cnt;
int visit[100][100];
int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};

int main(void) {
    int row=0, col=0;
    int dir;

    cin >> M >> N;

    visit[row][col]=true;
    dir=0;

    while(true) {
        int ny=row+dy[dir];
        int nx=col+dx[dir];

        if(visit[ny][nx] || ny<0 || nx<0 || ny>=M || nx>=N) {
            cnt++;

            dir=(dir+1)%4;

            if(visit[row+dy[dir]][col+dx[dir]]) break;
        } else {
            visit[ny][nx]=true;
            row=ny;
            col=nx;
        }
    }

    cout << cnt-1 <<"\n";

    return 0;
}