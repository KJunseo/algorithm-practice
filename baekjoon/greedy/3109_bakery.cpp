/*
    처음에 우선순위를 두어 오른쪽 위 - 오른쪽 - 오른쪽 아래로 갈 수 있는 길을 따져서 맨 끝에 도달하면 카운트해주는 식으로 구현하였다.
    테스트 케이스를 만족하여 통과했을거라고 생각했는데 실패하였다.

    dfs를 적용해서 풀었다
    * char 배열 대신 string 타입을 사용해서 풀려고 하니 런타임 에러가 나왔다. 
    * dfs시 =='.' 대신 !='x'를 사용했더니 런타임에러가 났다.. 마찬가지로 이유는 모르겠다.
    
*/
#include <stdio.h>
#include <iostream>
#define ROW 10001
#define COL 501

using namespace std;

int row,col;
bool checked[ROW][COL]; // 이미 방문한 곳인지 체크 
char grid[ROW][COL];

// 갈 수 있는 경우의 수(오른쪽 위 / 오른쪽 / 오른쪽 아래)
typedef struct {
    int r;
    int c;
} Cases;

Cases go[3] = {
    {-1,1},
    {0,1},
    {1,1}
};

// dfs
int dfs(int y, int x) {
    checked[y][x]=true; // 방문표시
    if(x==col-1) return 1; // 끝까지 도달했으면 카운트 1
    
    // 갈 수 있는 경우의 수들로 dfs 
    for(int i=0;i<3;i++) {
        int nextRow=y+go[i].r;
        int nextCol=x+go[i].c;

        // 방문하지 않았고, 건물이 없으면 갈 수 있다.
        if(!checked[nextRow][nextCol] && grid[nextRow][nextCol]=='.') {
            int v = dfs(nextRow,nextCol);
            if(v) return v;
        }
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &row, &col);

    int cnt=0;

    for(int i=0;i<row;i++) {
        cin >> grid[i];
    }

    for(int i=0;i<row;i++) {
        cnt+=dfs(i,0);
    }

    printf("%d\n", cnt);

    return 0;
}