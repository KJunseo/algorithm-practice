/*
    DFS로 풀었다.
    먼저 벡터를 사용하여 연결 정보를 담아주고, DFS를 돌려 출발지에서 목적지까지 이어질 수 있는지 확인하였다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> graph[101];
bool checked[101];

// dfs(d는 자기자신으로 가는 경로일 경우 처음부터 from==to를 비교하면 안되기 때문에 임의로 넣은 변수)
bool dfs(int from, int to, int d) {

    if(d!=0 && from==to) return true; // 출발지와 목적지가 같아지면 true

    if(checked[from]) return false; // 이미 방문한 곳이면 false
    checked[from]=true;

    for(int i=0;i<graph[from].size();i++) {
        int y=graph[from][i];
        if(dfs(y, to, d+1)) return true;
    }

    return false;
}

int main(void) {

    cin >> N;

    int answer[N][N];

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            int edge;
            cin >> edge;

            if(edge==1) graph[i].push_back(j); // 이어진 곳 벡터에 담아줌 
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            fill(checked, checked+N+1, false); // 방문여부 초기화 

            if(dfs(i, j, 0)) answer[i-1][j-1]=1;
            else answer[i-1][j-1]=0;
        }   
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}