/*
    어려웠다. 규칙찾기도 힘들었다.
    규칙은 길이가 홀 수인 경우는 오른쪽, 위쪽 이동
    짝수인 경우는 왼쪽, 아래쪽 이동을 길이만큼 반복하는 형태였다.
    그 후, 출력할 범위내의 값 중 가장 큰 값을 찾아 그 수의 자리수를 알아낸다.
    %*d를 이용하여 모든 수를 가장 큰 수 만큼의 폭으로 출력해준다.

    ** printf("%*d", 폭, 정수); 로 사용할 수 있다.
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int paper[50][5];
int r1, c1;
int r2, c2;

int dy[]={0, -1, 0, 1};
int dx[]={1, 0, -1, 0};

int main(void) {

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int row=r2-r1+1;
    int col=c2-c1+1;
    int total=row*col; // 전체 숫자 갯수
    int x=0, y=0; // 지점 
    int dir=0; // 방향 
    int len=1; // 이동 방향으로 이동할 길이 
    int value=1; // 값 

    // 소용돌이 만들기 
    while(total>0) {
        for(int i=0;i<2;i++) { // 같은 길이가 두 번씩 반복되므로
            for(int j=0;j<len;j++) { // 현재 길이만큼 이동
                if(y>=r1 && y<=r2 && x>=c1 && x<=c2) { // 모든 소용돌이를 저장하지 않고 출력할 범위 내의 값만 저장
                    paper[y-r1][x-c1]=value;
                    total--;
                }
                value++; // 모든 소용돌이를 만든다고 가정하기 때문에 값은 매번 증가해줘야 함
                y+=dy[dir];
                x+=dx[dir];
            }
            dir=(dir+1)%4;
        }
        len++;
    }

    // 출력할 소용돌이 중에 가장 큰 값 찾기 
    value=max(max(paper[0][0], paper[0][col-1]), max(paper[row-1][0], paper[row-1][col-1]));

    // 가장 큰 값의 자리수 찾기 
    int cnt=0;
    while(value) {
        value/=10;
        cnt++;
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {            
            printf("%*d ", cnt, paper[i][j]);
        }
        printf("\n");
    }

    return 0;
}