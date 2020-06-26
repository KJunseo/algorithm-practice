/*
    처음에 재귀로 풀었다가 테스트케이스 통과했길래 맞았다 싶었는데
    시간초과, 메모리 초과 다 나왔다..

    1. 운동 종료 조건
        운동 시 증가하는 맥박 수가 최대 맥박-최소 맥박보다 큰 경우 운동 불가
    2. 조건에 맞게 운동 가능할 때만 N을 --시키면서 반복 횟수 세기(운동이 가능하면 무조건 운동하는 것이 최소 시간이다.)
*/
#include <stdio.h>

using namespace std;

int N, m, M, T, R, t;

int main(void) {

    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

    int cur=m;

    if(T>M-m) {
        printf("-1\n");
        return 0;
    }

    while(N>0) {
        t++;

        if(cur+T<=M) {
            cur+=T;
            N--;
        } else {
            if(cur-R<m) cur=m;
            else cur-=R;
        }
    }
    
    printf("%d\n", t);

    return 0;
}