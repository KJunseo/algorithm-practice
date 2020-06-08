/*
    DFS로 풀었다.
    감이 잘 안 잡히는 문제였다.
    처음에 송도를 map으로 잡고 해야하나 생각했었는데 범위를 어떻게 잡아야할지 몰랐다.

    출발지, 도착지를 포함한 모든 좌표를 입력받고,
    모든 경우의 수의 맨해튼 거리를 계산하여 50*20(50미터당 하나 20개) 범위 안에 들어오면 벡터에 넣어주었다.
    그 후 0부터 dfs를 시작하였고, 만약 n+1을 방문했다면 happy, 못했다면 sad를 출력시킨다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > all;
vector<int> graph[102];
int visit[102];

// 연결된 좌표를 통해 목적지에 도착할 수 있는지 여부 확인하는 dfs
void dfs(int x) {
    visit[x]=true;

    for(int i=0;i<graph[x].size();i++) {
        int y=graph[x][i];

        if(!visit[y]) dfs(y);
    }
}

int main(void) {
    int testCase;

    cin >> testCase;

    for(int i=0;i<testCase;i++) {
        cin >> n;

        memset(visit, 0, sizeof(visit));
        all.clear();
        for(int j=0;j<102;j++) 
            graph[j].clear();

        // 모든 좌표를 입력받음
        for(int j=0;j<n+2;j++) {
            int y, x;
            cin >> y >> x;
            all.push_back(make_pair(y, x));
        }

        // 맨해튼거리를 비교하여 갈 수 있는 곳만 연결
        for(int j=0;j<n+2;j++) {
            for(int k=0;k<n+2;k++) {
                if(abs(all[j].first - all[k].first)+abs(all[j].second - all[k].second)<=1000) {
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }

        dfs(0);

        if(visit[n+1]) cout << "happy\n";
        else cout << "sad\n";
    }


    return 0;
}