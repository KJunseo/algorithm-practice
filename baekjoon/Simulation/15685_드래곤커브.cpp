/*
    문제 자체를 이해하는게 어려웠다..

    1. 각 방향 별로 pattern을 저장해둔다.
        방향이 0 일 때 기준으로 설명하자면
        0 세대: 0
        1 세대: 0 1
        2 세대: 0 1 2 1
        3 세대: 0 1 2 1 2 3 2 1
        이런식으로 다음 세대는 이전 세대를 그대로 가져온 후, 가져온 것을 역방향으로 +1 해준 값들이 뒤에 더해진다.
        예를 들어 3세대는 2세대의 0 1 2 1을 그대로 가져오고, 0 1 2 1을 역방향으로 하면 1 2 1 0이 되는데 이 값들에 +1을 해준 2 3 2 1이 뒤에 더해지는 형식이다.
        총 10세대까지 존재하므로 각 패턴 별 크기는 1<<10이 최대이다.

    2. 그 후 입력받은 시작점에서 입력받은 방향에 맞는 미리 저장해둔 패턴을 이용하여 좌표를 움직이고 방문처리해준다.

    3. 방문처리한 배열을 완전탐색하여 모든 꼭지점이 true인 부분의 카운트를 세어준다.
*/
#include <stdio.h>

int N;
bool grid[101][101];
int pattern[4][1<<10];

// 각 방향별 패턴을 10세대까지 저장한다.
void patternSetting() {
    for(int i=0;i<4;i++) pattern[i][0]=i; // 각 방향 별 패턴의 첫 값은 자기 자신

    for(int k=0;k<4;k++) { // 각 방향(0, 1, 2, 3)
        for(int i=1;i<=10;i++) { // 각 세대(0세대 ~ 10세대) 어차피 다음 세대의 처음 반틈은 이전세대의 값과 동일하므로 배열에 이어서 저장하고, 사용할 때 끝지점을 달리해서 사용하면 된다.
            int start = 1<<(i-1); // 시작 지점 
            int end = 1<<i; // 끝 지점
            for(int j=start, l=1;j<end;j++, l+=2) { // l값을 이용하여 역방향 인덱스를 조정한다.
                pattern[k][j]=(pattern[k][j-l]+1)%4; // 만약 역방향 +1 값이 4라면 0으로 바꿔준다.
            }
        }
    }
}

int main(void) {

    scanf("%d", &N);

    patternSetting();

    int x, y, d, g;
    int end;
    for(int i=0;i<N;i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);

        end=1<<g; // 끝 지점은 각 세대별로 다르게 지정해준다.

        grid[y][x]=true; // 현재 지점 방문처리

        // 패턴에 저장된 방향에 따라 y, x값 변경 후 방문 처리
        for(int j=0;j<end;j++) {
            if(pattern[d][j]==0) x++;
            else if(pattern[d][j]==1) y--;
            else if(pattern[d][j]==2) x--;
            else if(pattern[d][j]==3) y++;
            grid[y][x]=true; 
        }
    }

    // 모든 꼭지점이 true인 경우의 수 완전 탐색으로 세기
    int cnt=0;
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1]) cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}