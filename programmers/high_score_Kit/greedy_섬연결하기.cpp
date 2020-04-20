/*
    값을 기준으로 오름차순으로 정렬 후,
    union-found로 하나 씩 연결하고, 연결할 때마다 모두 연결되었는지 확인하여
    모두 연결된 상태면 종료하는 식으로 구현했다.
    
    연결하려는 두 섬의 부모가 다르다면(다른 그래프) 연결하고, 비용을 증가시켰다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[2]<b[2]) return true;
    return false;
}

int getParent(int parent[], int x) {
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
    a=getParent(parent, a);
    b=getParent(parent, b);
    
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int parent[n];
    
    for(int i=0;i<n;i++) parent[i]=i;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i=0;i<costs.size();i++) {
        if(getParent(parent, costs[i][0])!=getParent(parent, costs[i][1])) {
            unionParent(parent, costs[i][0], costs[i][1]);
            answer+=costs[i][2];
        }
    }
    
    return answer;
}