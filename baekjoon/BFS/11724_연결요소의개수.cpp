/*
    무방향 그래프이기 때문에 양쪽 모두 연결시켜준후,
    BFS로 탐색하였다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int cnt=0;
bool checked[1001];
vector<int> graph[1001];

void bfs(int start) {
    cnt++;
    queue<int> q;
    q.push(start);
    checked[start]=true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0;i<graph[x].size();i++) {
            int y=graph[x][i];

            if(!checked[y]) {
                q.push(y);
                checked[y]=true;
            }
        }
    }
}

int main(void) {
    int u, v;

    cin >> N >> M;

    for(int i=0;i<M;i++) {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=N;i++) {
        if(checked[i]) continue;
        bfs(i);
    }

    printf("%d\n", cnt);

    return 0;
}