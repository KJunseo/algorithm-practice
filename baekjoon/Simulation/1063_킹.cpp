/*
    설명대로 구현하면 되는 문제였다.
    문제에서는 ㄴ 자 형태의 좌표로 설명하였고 나는 이것을 익숙한 r 형태의 좌표로 생각해서 풀었다.
    이렇게 풀 때 주의할 점은 아래, 위 이동이 서로 반대관계에 있다는 것이다.
    처음에는 좌표는 r 형태로 하고 위 아래 이동은 ㄴ기준으로 풀었다가 틀렸다.
    ㄴ 좌표에서 위로 이동은 r좌표에서는 아래이동이다. 
*/
#include <iostream>

using namespace std;

string king, stone;
int N;

// 이동 방법
int dy[]={0, 0, -1, 1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, 1, -1};

int main(void) {

    cin >> king >> stone >> N;

    // 좌표 정수로 변환
    int ky=king[1]-48-1;
    int kx=king[0]-'A';
    int sy=stone[1]-48-1;
    int sx=stone[0]-'A';

    for(int i=0;i<N;i++) {
        string move;
        int dir;

        cin >> move;

        // 움직이는 방향 설정 
        if(move=="R") dir=0; 
        else if(move=="L") dir=1;
        else if(move=="B") dir=2;
        else if(move=="T") dir=3;
        else if(move=="RT") dir=4;
        else if(move=="LT") dir=5;
        else if(move=="RB") dir=6;
        else if(move=="LB") dir=7;

        // king의 다음 좌표
        int nky=ky+dy[dir];
        int nkx=kx+dx[dir];

        if(nky<0 || nkx<0 || nky>=8 || nkx>=8) continue; // 범위 벗어나면 스킵 

        // 킹이 움직인 자리에 돌이 있다면 
        if(nky==sy && nkx==sx) {

            // 돌의 다음 좌표
            int nsy=sy+dy[dir];
            int nsx=sx+dx[dir];

            if(nsy<0 || nsx<0 || nsy>=8 || nsx>=8) continue; // 범위 벗어나면 스킵 

            sy=nsy;
            sx=nsx;
        }

        ky=nky;
        kx=nkx;
    }

    // 정수 -> 문자
    king=(kx+'A');
    king+=(ky+'1');

    stone=(sx+'A');
    stone+=(sy+'1');

    cout << king << "\n";
    cout << stone << "\n";

    return 0;
}