/*
    dfs를 써야할 것 같았다.
    dfs를 두 번 쓰면 되지 않을까라는 생각을 했다.
    1. 3개의 벽을 세울때
    2. 3개의 벽을 세운 후 전염시킬때

    혼자 해결하지 못하였다.
    1. 재귀를 통해 3개의 벽 설치
    2. 벽이 3개가 되면 BFS를 사용해서 전염시키기

    ** 배열을 복사해서 사용해야 한다.
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 9

using namespace std;

typedef struct {
    int x;
    int y;
} Dir;

Dir go[4] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};

int n,m;
int a[MAX][MAX];
int b[MAX][MAX];
int result;
vector< pair<int, int> > virus;

// bfs로 바이러스 전파
void infect() {
    int after[MAX][MAX];
    copy(&b[0][0], &b[0][0]+ MAX * MAX, &after[0][0]);

    queue <pair<int, int> >q;

    for(int i=0;i<virus.size();i++) q.push(virus[i]);

    while(!q.empty()) {
        // 큐에 들어간 순서대로 바이러스의 좌표 가져옴
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nextX = x + go[i].x;
            int nextY = y + go[i].y;

            // 전염 시키기
            if(nextX>=0 && nextX<n && nextY >=0 && nextY < m) {
                if(after[nextX][nextY] == 0) {
                    after[nextX][nextY]=2;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    int temp=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(after[i][j]==0) temp++;
        }
    }
    result = max(result, temp);
}

// 재귀로 3개의 벽을 쌓는 함수
void makeWall(int cnt) {
    if(cnt==3) {
        infect();
        return;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(b[i][j]==0) {
                b[i][j]=1;
                makeWall(cnt+1);
                b[i][j]=0;
            }
        }
    }
}

int main(void) {
    int cnt=0;
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &a[i][j]);
            
            if(a[i][j]==2) virus.push_back(make_pair(i,j));
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j]==0) {
                copy(&a[0][0], &a[0][0]+ MAX * MAX, &b[0][0]);

                b[i][j]=1;
                makeWall(1); // 벽 3개 세우기
            }
        }
    }

    printf("%d\n", result);

    return 0;
}