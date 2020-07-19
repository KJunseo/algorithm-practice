/*
    난이도 하 문제였지만 조금 복잡했다.
    if문안에 계산식을 둘 경우 참 거짓에 상관없이 일단 계산이 일어나므로 이를 통해
    블럭을 놓고, 치우는 행위를 한 함수에 구현했다.
    나중에 한 번 더 풀어봐야겠다.
*/
#include <cstdio>
#include <iostream>

using namespace std;

int C;
int H, W;
char board[20][20];

// 가능한 4가지 블럭 타입의 상대 좌표 
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

// 블럭을 놓거나, 치우는 함수 
// status가 1인 경우 -> 블럭을 덮는다, 2인 경우 -> 블럭을 치운다 
bool set(int y, int x, int type, int status) {
    bool check = true; // 블럭을 놓을 수 있는지 여부 

    // 블럭을 놓을 수 있는지 검사 
    for(int i=0;i<3;i++) {
        const int ny = y+coverType[type][i][0];
        const int nx = x+coverType[type][i][1];

        if(ny<0 || nx<0 || ny>=H || nx>=W) check=false; // board를 벗어나면 false
        else if((board[ny][nx]+=status)>1) check=false; // 겹쳐진 경우 false 
    }

    return check;
}

// 모든 빈 칸을 덮을 수 있는 방법의 수를 반환하는 함수 
int cover() {
    int y = -1, x = -1;

    // 가장 위쪽 가장 왼쪽부터 탐색하여 블럭을 놓을 시작지점을 탐색(흰 칸)
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(board[i][j]==0) {
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1) break;
    }

    // 기저 사례: 흰 칸이 없는 경우(모든 칸을 채운 경우) 1을 리턴
    if(y==-1) return 1;

    int cnt=0;

    // 블럭의 종류가 4개이므로 모든 블럭을 놓아본다. 
    for(int i=0;i<4;i++) {

        // i 타입의 블럭을 놓을 수 있는 경우
        if(set(y, x, i, 1)) {
            cnt += cover(); // 재귀 호출 
        }

        // i타입의 블럭을 놓을 수 없는 경우 놓으려 시도했던 블럭을 지운다.
        set(y, x, i, -1);
    }

    return cnt;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {
        int whiteNum=0; // 흰 칸의 숫자

        cin >> H >> W;

        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                char temp;
                cin >> temp;

                // 1: 검은칸 또는 이미 덮힌 칸, 0: 흰 칸 
                if(temp=='#') board[i][j]=1; 
                else if(temp=='.') {
                    board[i][j]=0;
                    whiteNum++;
                }
            }
        }
        
        // 3으로 나누어지니 않으면 0 그게 아니라면 cover 호출
        cout << (whiteNum%3!=0 ? 0 : cover()) << "\n"; 
    }

    return 0;
}