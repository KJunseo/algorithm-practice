/*
    summer/winter 코딩에서 높이별로 나누는 문제를 본 적이 있어서 비슷하게 풀었다.
    BFS를 이용했다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 25

using namespace std;

int N;
int group=0;
int board[MAX][MAX];
int visit[MAX][MAX];
int g[MAX*MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void bfs(int y, int x) {
    group++; // 단지 구분 
    queue<pair<int, int> > q;

    q.push(make_pair(y, x)); // 시작 점을 큐에 넣어줌 
    visit[y][x]=group;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        // 상, 하, 좌, 우 탐색 
        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=N) continue; // 배열 범위를 넘으면 무시 

            if(visit[ny][nx]>0) continue; // 그룹에 속해있으면 무시 

            if(board[ny][nx]==0) continue; // 0이라면 무시 

            visit[ny][nx]=group; // 단지에 추가 
            
            q.push(make_pair(ny, nx));
        }
    }
}

int main(void) {

    cin>>N;

    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;

        for(int j=0;j<temp.size();j++) {
            board[i][j]=temp[j]-'0';
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j]==0) continue; // 집이 없는 곳이면 무시 
            if(visit[i][j]>0) continue; // 이미 어떤 그룹에 속해있다면 무시
            bfs(i, j); 
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visit[i][j]==0) continue; 
            g[visit[i][j]-1]++;
        }
    }

    sort(g, g+group);
    printf("%d\n", group);

    for(int i=0;i<group;i++) {
        printf("%d\n", g[i]);
    }

    return 0;
}