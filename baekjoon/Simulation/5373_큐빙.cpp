/*
    큐브를 돌릴 때 나머지 4개의 면의 큐브가 3개씩 바뀌는데 그걸 구현하는게 너무 어려웠다.
    실제 큐브를 사서 번호 붙이면서 해보고 싶었다..
    완전 노가다였다. 머리가 진짜 아팠던 거 같다.
*/
#include <iostream>

using namespace std;

int n; 
string command;
char cube[6][3][3];
char temp[3][3];
int t[3];
char color[6]={'w', 'y', 'r', 'o', 'g', 'b'};

// 큐브를 초기 상태로 초기화
void cubeSetting() {
    for(int k=0;k<6;k++) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                cube[k][i][j]=color[k];
            }
        }
    }
}

// 큐브의 윗 면을 출력
void printUpside() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%c", cube[0][i][j]);
        }
        printf("\n");
    }
}

// 큐브 한 면 복사
void copyCube(int side) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            temp[i][j]=cube[side][i][j];
        }
    }
}

// 큐브를 돌리면 자기 자신의 면도 바뀐다.
void selfChange(int side, char dir) {
    copyCube(side);

    if(dir=='+') { // 시계 방향일 때
        cube[side][0][0]=temp[2][0];
        cube[side][0][1]=temp[1][0];
        cube[side][0][2]=temp[0][0];
        cube[side][1][0]=temp[2][1];
        cube[side][1][2]=temp[0][1];
        cube[side][2][0]=temp[2][2];
        cube[side][2][1]=temp[1][2];
        cube[side][2][2]=temp[0][2];
    } else if(dir=='-') { // 반시계 방향일 때
        cube[side][0][0]=temp[0][2];
        cube[side][0][1]=temp[1][2];
        cube[side][0][2]=temp[2][2];
        cube[side][1][0]=temp[0][1];
        cube[side][1][2]=temp[2][1];
        cube[side][2][0]=temp[0][0];
        cube[side][2][1]=temp[1][0];
        cube[side][2][2]=temp[2][0];
    }
}

// 위를 기준으로 돌렸을 때
void spinU(int k) {
    for(int i=0;i<3;i++) t[i]=cube[4][k][i];
    for(int i=0;i<3;i++) cube[4][k][i]=cube[2][k][i];
    for(int i=0;i<3;i++) cube[2][k][i]=cube[5][k][i];
    for(int i=0;i<3;i++) cube[5][k][i]=cube[3][k][i];
    for(int i=0;i<3;i++) cube[3][k][i]=t[i];
}

// 아래를 기준으로 돌렸을 때
void spinD(int k) {
    for(int i=0;i<3;i++) t[i]=cube[4][k][i];
    for(int i=0;i<3;i++) cube[4][k][i]=cube[3][k][i];
    for(int i=0;i<3;i++) cube[3][k][i]=cube[5][k][i];
    for(int i=0;i<3;i++) cube[5][k][i]=cube[2][k][i];
    for(int i=0;i<3;i++) cube[2][k][i]=t[i];
}

// 앞을 기준으로 돌렸을 때
void spinF(int k) {
    int j = k == 0 ? 2 : 0;
    for(int i=0;i<3;i++) t[i]=cube[0][k][i];
    for(int i=0;i<3;i++) cube[0][k][i]=cube[4][2-i][k];
    for(int i=0;i<3;i++) cube[4][i][k]=cube[1][j][i];
    for(int i=0;i<3;i++) cube[1][j][i]=cube[5][2-i][j];
    for(int i=0;i<3;i++) cube[5][i][j]=t[i];

}

// 뒤를 기준으로 돌렸을 때 
void spinB(int k) {
    int j = k == 0 ? 2 : 0;
    for(int i=0;i<3;i++) t[i]=cube[0][k][i];
    for(int i=0;i<3;i++) cube[0][k][i]=cube[5][i][j];
    for(int i=0;i<3;i++) cube[5][i][j]=cube[1][j][2-i];
    for(int i=0;i<3;i++) cube[1][j][i]=cube[4][i][k];
    for(int i=0;i<3;i++) cube[4][i][k]=t[2-i];
}

// 왼쪽을 기준으로 돌렸을 때
void spinL(int k) {
    int j = k == 0 ? 2 : 0;
    for(int i=0;i<3;i++) t[i]=cube[0][i][k];
    for(int i=0;i<3;i++) cube[0][i][k]=cube[3][2-i][j];
    for(int i=0;i<3;i++) cube[3][i][j]=cube[1][2-i][k];
    for(int i=0;i<3;i++) cube[1][i][k]=cube[2][i][k];
    for(int i=0;i<3;i++) cube[2][i][k]=t[i];
}

// 오른쪽을 기준으로 돌렸을 때 
void spinR(int k) {
    int j = k == 0 ? 2 : 0;
    for(int i=0;i<3;i++) t[i]=cube[0][i][k];
    for(int i=0;i<3;i++) cube[0][i][k]=cube[2][i][k];
    for(int i=0;i<3;i++) cube[2][i][k]=cube[1][i][k];
    for(int i=0;i<3;i++) cube[1][i][k]=cube[3][2-i][j];
    for(int i=0;i<3;i++) cube[3][i][j]=t[2-i];
}

// 큐브 돌리기 
void spinCube() {
    char side=command[0];
    char dir=command[1];

    if(side=='U') {
        selfChange(0, dir);      

        if(dir=='+') {
            spinU(0);
        } else if(dir=='-') {
            spinD(0);
        }
    } else if(side=='D') {
        selfChange(1, dir);

        if(dir=='+') {
            spinD(2);
        } else if(dir=='-') {
            spinU(2);
        }
    } else if(side=='F') {
        selfChange(2, dir);

        if(dir=='+') {
            spinF(2);
        } else if(dir=='-') {
            spinB(2);
        }
    } else if(side=='B') {
        selfChange(3, dir);

        if(dir=='+') {
            spinB(0);
        } else if(dir=='-') {
            spinF(0);
        }
    } else if(side=='L') {
        selfChange(4, dir);

        if(dir=='+') {
            spinL(0);
        } else if(dir=='-') {
            spinR(0);
        }
    } else if(side=='R') {
        selfChange(5, dir);

        if(dir=='+') {
            spinR(2);
        } else if(dir=='-') {
            spinL(2);
        }
    }
}

int main(void) {
    int testcase;

    cin >> testcase;

    for(int k=0;k<testcase;k++) {
        cubeSetting();

        cin >> n;

        for(int i=0;i<n;i++) {
            cin >> command;

            spinCube();
        }

        printUpside();
    }

    return 0;
}