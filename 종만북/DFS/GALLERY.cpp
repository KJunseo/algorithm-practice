/*
    루트 없는 트리로 문제를 푸는 경우였다. 최소 지배 집합을 찾는 문제다.
    1. 잎 노드는 선택하지 않고
    2. 트리의 밑에서부터 
        2-1. 자손 중 지배당하지 않은 노드가 존재하면 선택
        2-2. 이 외의 경우 노드 선택 x
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int C;
int g, h;
vector<int> adj[1000];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed; // 지금까지 설치한 카메라의 총 수

// here로 부터 깊이 우선 탐색을 하고, here의 정보를 반환한다.
int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};

    for(int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];

        if(!visited[there]) children[dfs(there)]++;
    }

    // 자손 노드 중 감시되지 않는 노드가 있을 경우 카메라를 설치한다.
    if(children[UNWATCHED]) {
        installed++;
        return INSTALLED;
    }

    // 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다.
    if(children[INSTALLED]) return WATCHED;

    return UNWATCHED;
}

// 그래프를 감시하는 데 필요한 카메라의 최소 수를 반환한다.
int installCamera() {
    installed = 0;
    visited = vector<bool>(g, false);

    for(int u = 0; u < g; u++) 
        if(!visited[u] && dfs(u) == UNWATCHED) installed++;
    
    return installed;
}

int main(void) {
    
    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> g >> h;

        for(int i = 0; i < g; i++) adj[i].clear();

        int u, v;
        for(int i = 0; i < h; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << installCamera() << "\n";
    }

    return 0;
}