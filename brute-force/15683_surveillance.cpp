/*
    dfs로도 도전해보고,
    큐를 사용해 bfs로 구현해보려고도 했지만 구현방법이 생각나지 않았다.

    1번 감시카메라는 경우의 수가 4가지
    2번 감시카메라는 경우의 수가 2가지
    3번 감시카메라는 경우의 수가 4가지
    4번 감시카메라는 경우의 수가 4가지
    5번 감시카메라는 경우의 수가 1가지

    위와 같이 경우의 수가 너무 많아서 어떻게 해야할지 감이 잘 안왔다..

    풀이는 dfs였다.
    1. 감시카메라의 타입과 좌표를 벡터에 넣어준다.
    2. 감시카메라의 갯수만큼 dfs를 시행한다.
    3. 감시카메라의 종류에 따라 모든 경우의 수 만큼 dfs를 시행한다.

    체감상 많이 어려웠다. 대략 생각은 비슷하게 했는데, 구현이 정말 쉽지 않았다.
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 8

using namespace std;

int n, m;
int cctvCnt=0;
int result=64;
int office[MAX][MAX];
vector < pair<int, pair <int, int> > > cctv;

void go(int direction, int y, int x) {

    switch(direction) {
        // 동
        case 0:
            // 벽을 만날 때 까지 탐지(탐지한 곳은 -1로 표시)
            for(int j=x+1;j<m;j++) {
                if(office[y][j]==6) break;
                if(office[y][j]==0) office[y][j]=-1;
            }
            break;
        // 남
        case 1:
            // 벽을 만날 때 까지 탐지(탐지한 곳은 -1로 표시)
            for(int i=y+1;i<n;i++) {
                if(office[i][x]==6) break;
                if(office[i][x]==0) office[i][x]=-1;
            }
            break;
        // 서
        case 2:
            // 벽을 만날 때 까지 탐지(탐지한 곳은 -1로 표시)
            for(int j=x-1;j>=0;j--) {
                if(office[y][j]==6) break;
                if(office[y][j]==0) office[y][j]=-1;
            }
            break;
        // 북
        case 3:
            // 벽을 만날 때 까지 탐지(탐지한 곳은 -1로 표시)
            for(int i=y-1;i>=0;i--) {
                if(office[i][x]==6) break;
                if(office[i][x]==0) office[i][x]=-1;
            }
            break;
    }
}

void dfs(int num) {
    // 모든 cctv를 살펴보았으면 0의 갯수를 세고 최솟값으로 갱신
    if(num==cctvCnt) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(office[i][j]==0) cnt++;
            }
        }
        result=min(result, cnt);
        return;
    }

    int cctyType=cctv[num].first; // cctv 종류 
    int y=cctv[num].second.first; // cctv y좌표
    int x=cctv[num].second.second; // cctv x좌표

    int temp[MAX][MAX]; // 이전 값을 유지하기 위한 배열 

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            temp[i][j]=office[i][j]; // 현재 사무실 값 복사 
        }
    }

    // cctv 종류 별로 dfs
    switch(cctyType) {
        // 경우의 수 4가지(동, 서, 남, 북)
        case 1:
            for(int i=0;i<4;i++) {
                go(i, y, x);
                dfs(num+1);
                // 이전 값으로 다시 복사 
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        office[i][j]=temp[i][j];
                    }
                }
            }
            break;
        // 경우의 수 2가지(동서, 남북)
        case 2:
            for(int i=0;i<2;i++) {
                go(i, y, x);
                go(i+2, y, x);
                dfs(num+1);
                // 이전 값으로 다시 복사 
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        office[i][j]=temp[i][j];
                    }
                }
            }
            break;
        // 경우의 수 4가지(동북, 동남, 서남, 서북)
        case 3:
            for(int i=0;i<4;i++) {
                go(i, y, x);
                go((i+1)%4, y, x);
                dfs(num+1);
                // 이전 값으로 다시 복사 
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        office[i][j]=temp[i][j];
                    }
                }
            }            
            break;
        // 경우의 수 4가지(동남북, 동남서, 서남북, 서동북)
        case 4:
            for(int i=0;i<4;i++) {
                go(i, y, x);
                go((i+1)%4, y, x);
                go((i+2)%4, y, x);
                dfs(num+1);
                // 이전 값으로 다시 복사 
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        office[i][j]=temp[i][j];
                    }
                }
            }        
            break;
        // 경우의 수 1가지(동서남북)
        case 5:
            for(int i=0;i<4;i++) go(i, y, x);
            dfs(num+1);
            break;
    }

}

int main(void) {

    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &office[i][j]);

            // cctv의 종류와 위치를 기억한다.
            if(office[i][j]!=0 && office[i][j]!=6) {
                cctvCnt++;
                cctv.push_back(make_pair(office[i][j],make_pair(i,j)));
            }
        }
    }

    // 모든 cctv를 탐색할 때까지 dfs
    dfs(0);

    printf("%d\n", result);

    return 0;
}