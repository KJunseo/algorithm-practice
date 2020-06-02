/*
    DFS를 사용하여 풀었다. 이분 그래프에 대한 개념이 없어서 힘들었다.
    이분 그래프는 그래프의 정점의 집합을 둘로 분리하여, 각 집합에 속한 정점들 끼리는 간선으로 연결되어 있지 않은 그래프를 뜻한다.

    제일 처음 정점을 빨간색 집합으로 지정하고, DFS를 시작한다.
    정점과 인접한 다른 정점들이 아직 집합에 속해있지 않으면, 파란색 집합으로 지정해주고,
    만약 인접한 다른 정점들이 같은 집합에 이미 속한 경우 이분그래프가 아니므로 flag를 바꿔준다.
*/
#include <iostream>
#include <string.h>
#include <vector>
#define RED 1
#define BLUE -1

using namespace std;

int node, edge;
vector<int> graph[20001]; // 각 노드의 연결관계를 나타내는 그래프
int group[20001]; // 각 노드가 어느 정점에 속한지 확인
bool isBipartitleGraph; // 이분 그래프 여부를 판단하기 위한 flag

// dfs
void dfs(int x, int color) {
    group[x]=color; // 그룹을 지정해준다.

    for(int i=0;i<graph[x].size();i++) {
        int y=graph[x][i]; // 인접한 정점들 

        // 인접한 정점들끼리 같은 그룹이면 이분 그래프가 아니다.
        if(group[y]==color) {
            isBipartitleGraph=false;
            return;
        }

        // 그룹에 속해있지 않은 경우 반대 집합을 지정해준다.
        if(group[y]==0) {
            dfs(y, -color);
        }
    }
}

int main(void) {

    int testNum;

    cin >> testNum;

    for(int i=0;i<testNum;i++) {

        // 테스트 케이스마다 초기화 해줘야 함
        for(int j=1;j<20001;j++) {
            graph[j].clear();
        }
        memset(group, 0, sizeof(group));
        isBipartitleGraph=true;

        cin >> node >> edge;

        // 양방향 연결
        for(int j=0;j<edge;j++) {
            int n1, n2;
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        // 이어지지 않은 그래프도 판별해야하기 때문
        for(int j=1;j<node+1;j++) {

            if(!isBipartitleGraph) break; // 이분 그래프가 아니면 종료

            if(group[j]==0) {
                dfs(j, RED);
            }
        }

        if(isBipartitleGraph) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}