/*
    각 알파벳을 정점으로 두고 순서에 따라 간선으로 연결한다
    알파벳의 순서는 위상정렬 결과가 된다.

    인접한 단어만 비교하면 된다.

    dfs를 수행하면 역순으로 저장되므로 reverse를 이용하여 역순으로 뒤집어줘야한다.

    위상 정렬 결과 사이클이 존재하면 invalid이다.

*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n;

// 알파벳의 각 글자에 대한 인접 행렬 표현
// 간선 (i, j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
vector<vector<int> > adj;

vector<int> seen, order;

// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다. 
void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));

    for(int  j = 1; j < words.size(); j++) {
        int i = j - 1;
        int len = min(words[i].size(), words[j].size());

        // words[i]가 words[j] 앞에 오는 이유 찾기 
        for(int k = 0; k < len; k++) {
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

void dfs(int here) {
    seen[here] = 1;

    for(int there = 0; there < adj.size(); there++) 
        if(adj[here][there] && !seen[there]) dfs(there);
    
    order.push_back(here);
}

// adj에 주어진 그래프를 위상정렬한 결과 반환
// 그래프가 DAG가 아니라면 빈 벡터를 반환
vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();

    for(int i = 0; i < m; i++) if(!seen[i]) dfs(i);
    reverse(order.begin(), order.end());

    // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            if(adj[order[j]][order[i]]) return vector<int>();
        }
    }

    return order;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        vector<string> words(n);

        for(int i = 0; i < n; i++) 
            cin >> words[i];
        
        makeGraph(words);

        vector<int> ret = topologicalSort();

        if(ret.empty()) cout << "INVALID HYPOTHESIS";
        else for(int i = 0; i < ret.size(); i++) 
                cout << char(ret[i] + 'a');
        cout << "\n";
    }

    return 0;
}