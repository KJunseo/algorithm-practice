/*
    dfs를 사용하여 사다리를 모든 위치에 하나씩 넣어보면서 검사.
    사다리를 2개씩 넣어보면서 검사
    사다리를 3개씩 넣어보면서 검사
    모두 자기자신에게 도착하면 사다리 수를 출력.
    그렇지 않으면 -1을 출력하면 될 거 같았는데, 도저히 구현을 못하겠었다.

    접근 방법은 맞았었지만, 구현 능력이 아직 많이 부족한 것 같다...
    그래도 사고가 조금은 발전한 것 같기도 하다.
    계속 풀다보면 점점 나아질 것이라고 생각한다...
*/
#include <stdio.h>

int n, m, h;
int ladderNum;
bool flag;
bool ladder[30][11];

// y: 사다리 탐색 시작점 | cnt: 추가한 사다리 수
void dfs(int y, int cnt) {
    if(flag) return; // 답을 찾은 경우

    // 현재 사다리 개수와 추가한 사다리 수가 같은 경우
    if(ladderNum==cnt) {
        bool possible=true;

        // 각 세로줄 확인 
        for(int i=1;i<=n;i++) {
            int col=i; // 가로 위치 인덱스

            for(int j=0;j<h;j++) {
                // 사다리가 놓여진 경우 오른쪽 이동
                if(ladder[j][col]) col++;
                // 사다리가 놓여진 경우 왼쪽 이동
                else if(col>1 && ladder[j][col-1]) col--;
            }

            // 하나라도 자기 자신의 위치로 돌아오지 못한 경우
            if(i!=col) {
                possible=false;
                break;
            }
        }
        if(possible) flag=true; // 모든 세로줄이 자기 자신으로 돌아온 경우
        return;
    }
    
    for(int i=y;i<h;i++) {
        for(int j=1;j<n;j++) {
            if(!ladder[i][j]) {
                // 가로선이 연속되지 않은 경우
                if(!ladder[i][j-1] && !ladder[i][j+1]) {
                    ladder[i][j]=true; // 사다리를 세운다.
                    dfs(i,cnt+1);
                    ladder[i][j]=false;
                }
            }
        }
    }
    return;
}

int main(void) {
    int a, b;
    scanf("%d %d %d", &n, &m, &h); // n: 세로줄 수 | m: 초기 사다리 갯수 | h: 가로줄 수 

    for(int i=0;i<m;i++) {
        scanf("%d %d", &a, &b);

        ladder[a-1][b]=true; // a-1번 위치에서 b ----- b+1  사디리를 이었다는 뜻 
    }

    // 사다리를 추가한 개수 0~3 
    for(int i=0;i<=3;i++) {
        ladderNum=i;
        dfs(0,0);
        if(flag) {
            printf("%d\n", ladderNum);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}