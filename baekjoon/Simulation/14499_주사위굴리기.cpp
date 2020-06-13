/*
    주사위의 각 면의 위치를 배정해주는게 너무 헷갈렸다.
    또 y x 좌표 문제로 시간을 많이썼다..
*/
#include <iostream>

using namespace std;

int N, M;
int K;
int map[20][20];
int dice[6];

int dr[]={0, 0, -1, 1};
int dc[]={1, -1, 0, 0};

int main(void) {
    int x, y;

    cin >> N >> M >> x >> y >> K;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<K;i++) {
        int command;
        cin >> command;

        int nr = x + dr[command - 1];
        int nc = y + dc[command - 1];

        if(nr<0 || nc<0 || nr>=N || nc>=M) continue;

        if(command==1) { // 동 
            int temp = dice[3];
            dice[3] = dice[0]; dice[0] = dice[2]; dice[2] = dice[1]; dice[1] = temp;
        } else if(command==2) { // 서 
            int temp = dice[3];
            dice[3] = dice[1]; dice[1] = dice[2]; dice[2] = dice[0]; dice[0] = temp;
        } else if(command==3) { // 북
            int temp = dice[4];
            dice[4] = dice[1]; dice[1] = dice[5]; dice[5] = dice[0]; dice[0] = temp;
        } else if(command==4) { // 남
            int temp = dice[5];
            dice[5] = dice[1]; dice[1] = dice[4]; dice[4] = dice[0]; dice[0] = temp;
        }

        if(map[nr][nc]==0) {
            map[nr][nc]=dice[1];
        } else {
            dice[1]=map[nr][nc];
            map[nr][nc]=0;
        }

        x=nr;
        y=nc;

        cout << dice[0] << "\n";
    }

    return 0;
}
