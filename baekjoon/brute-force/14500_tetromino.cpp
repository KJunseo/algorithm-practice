/*
    dfs를 써야한다는 것은 알았다.
    그렇지만 ㅗ 모양은 dfs로 찾아낼 수 없다는 것을 찾아보기 전에는 알지 못했다.
    연속된 4점을 찾아 합을 구하면 된다고 생각했는데, 연속된 점을 찾기가 힘들었다.

    풀이방법은 dfs로 ㅗ 를 제외한 도형들의 합 중 가장 큰 값과,
    ㅗ 모양에서 발생할 수 있는 4가지 모양의 합을 구해서 가장 큰 값이 정답이었다.
*/
#include <stdio.h>
#include <algorithm>
#define MAX 500

using namespace std;

typedef struct {
    int y;
    int x;
} Dir;

Dir go[4]={
    {0, 1},
    {0,-1},
    {-1, 0},
    {1, 0}
};

int n, m;
int paper[MAX][MAX];
bool checked[MAX][MAX];
int dfs(int r, int c, int cnt) {
    if(cnt==4) {
        return paper[r][c];
    }

    int sum=0;

    for(int i=0;i<4;i++) {
        int nextY = r+go[i].y;
        int nextX = c+go[i].x;

        if(nextY>=0 && nextY<n && nextX>=0 && nextX<m && !checked[nextY][nextX]) {
            checked[nextY][nextX]=true;
            sum = max(sum, paper[r][c]+dfs(nextY, nextX, cnt+1));
            checked[nextY][nextX]=false;
        }
    }
    return sum;
}

int exceptShape(int r, int c) {
    int sum=0;

    // ㅗ 
    if(r>=1 && c>=1 && c<m-1)
        sum=max(sum, paper[r][c-1]+paper[r][c]+paper[r][c+1]+paper[r-1][c]);
    // ㅏ
    if(r>=1 && r<n-1 && c<m-1)
        sum=max(sum, paper[r][c]+paper[r-1][c]+paper[r+1][c]+paper[r][c+1]);
    // ㅜ
    if(r>=0 && r<n-1 && c<m-1)
        sum=max(sum, paper[r][c]+paper[r][c-1]+paper[r+1][c]+paper[r][c+1]);
    // ㅓ
    if(c>=1 && r>=1 && r<n-1)
        sum=max(sum, paper[r][c]+paper[r][c-1]+paper[r-1][c]+paper[r+1][c]);
    return sum;
}   

int main(void) {
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    int maxNum=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            checked[i][j]=true;
            maxNum=max(maxNum, dfs(i,j,1));
            maxNum=max(maxNum, exceptShape(i,j));
            checked[i][j]=false;
        }
    }

    printf("%d", maxNum);

    return 0;
}