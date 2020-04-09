/*
    union found를 사용했다.
    코드 풀이를 찾아보지는 않았고, union found 코드는 참고하여 풀었다.

    dfs로도 풀이 할 수 있는 문제였다.
    방문여부를 체크할 수 있는 배열을 선언해주고,
    해당 노드를 방문하지 않은 경우 dfs로 탐색한다.
    해당 노드를 방문처리 해주고, 연결된 노드를 확인하여, 방문하지 않은 경우면 연결된 노드를 탐색한다.
    checked 배열을 공유하고 있으므로, 네트워크 갯수를 찾을 수 있다.
*/
#include <string>
#include <vector>

using namespace std;

int getParent(int parent[], int x) {
    // 재귀를 통해 부모 찾기 
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
    // 현재 부모값을 얻어온다.
    a=getParent(parent, a); 
    b=getParent(parent, b);
    
    // 작은 값으로 업데이트 한다.
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool findParent(int parent[], int a, int b) {
    // 현재 부모값을 얻어온다.
    a=getParent(parent, a); 
    b=getParent(parent, b);
    
    // 같은 부모면 true 아니면 false
    if(a==b) return true;
    else return false;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int cnt = 0; // 결합 된 수 
    int parent[n]; // 해당 노드의 부모가 누구인지 나타내주는 배열 
    
    for(int i=0;i<n;i++) {
        parent[i]=i; // 초기에는 모두 자기자신이 부모
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // 연결되어 있고,
            if(computers[i][j]==1) {
                // 같은 부모를 가진 경우가 아니면
                if(!findParent(parent, i, j)) {
                    cnt++;
                    unionParent(parent, i, j); // 합쳐준다.         
                }
            } 
        }
    }

    answer=n-cnt; // 모두 연결되지 않은 경우(최대)에서 결합된 수 를 빼준다.

    return answer;
}

// dfs 사용 방법
bool checked[200];

void dfs(int start, vector<vector<int>> computers) {
    checked[start] = true;

    for(int i=0;i<computers[start].size();i++) {
        if(i==start) continue;

        if(computers[start][i] && !checked[i]) dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0;i<n;i++) {
        if(!checked[i]) {
            answer++;
            dfs(i, computers);
        }
    }

    return answer;
}