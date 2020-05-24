/*
    프로그래머스에서 문제를 풀다가 오랜만에 백준을 풀려니 뭔가 어색했다.
    기본적인 DFS와 BFS를 구현하는 문제였다.
    '방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문'을 보지 못하여 나중이나 되서야 sort를 사용했다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NODE 1001

using namespace std;

int checked[NODE];
vector<int> v[NODE];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    checked[start]=true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        sort(v[x].begin(), v[x].end());
        for(int i=0;i<v[x].size();i++) {
            int y = v[x][i];
            
            if(!checked[y]) {
                q.push(y);
                checked[y]=true;
            }
        }
    }

}

void dfs(int x) {
    if(checked[x]) return;
    checked[x]=true;

    cout << x << " ";
    
    sort(v[x].begin(), v[x].end());
    for(int i=0;i<v[x].size();i++) {
        int y=v[x][i];
        dfs(y);
    }
}

int main(void) {
    int N, M, V;

    cin >> N >> M >> V;

    for(int i=0;i<M;i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    dfs(V);

    printf("\n");
    fill(checked, checked+NODE, false);

    bfs(V);

    return 0;
}