/*
    완전탐색으로 가능한 8*8 배열들을 복사하고,
    그 배열로 처음이 W일 때와, B일 때를 완전 탐색으로 계산하였다.
*/
#include <stdio.h>
#include <algorithm>
#define MAX 51

using namespace std;

char originalBoard[MAX][MAX];
char board[8][8];
int minNum=64;

void copyBoard(int r, int c) {
    int col=c;
    for(int i=0;i<8;i++,r++) {
        for(int j=0;j<8;j++,c++) {
            board[i][j]=originalBoard[r][c];
        }
        c=col;
    }
}

void rePaint() {
    int temp=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if((i+j)%2==0 && board[i][j]!=board[0][0]) {
                temp++;
            } else if((i+j)%2==1 && board[i][j]==board[0][0]) {
                temp++;
            }
        }
    }
    temp=min(temp, 64-temp);
    minNum = min(minNum,temp);
}

int main(void) {
    int n,m;

    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        getchar();
        for(int j=0;j<m;j++) {
            scanf("%c",&originalBoard[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i+8<=n && j+8<=m) {
                copyBoard(i,j);   
                rePaint();
            }
        }
    }

    printf("%d\n", minNum);

    return 0;
}