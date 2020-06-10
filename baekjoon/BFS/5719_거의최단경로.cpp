/*
    어려웠다. 혼자 풀지 못했다.

    1. 다익스트라를 이용해 S->D 최단 경로 구하기
        dist에 최단 경로 업데이트
    2. 해당 최단 경로 삭제
        최단 경로를 역순으로 탐색(dist와 b벡터 사용) check배열에 방문 체크
    3. 다익스트라를 이용해 S->D 최단 경로 구하기
        check배열에 방문된 최단경로를 제외하고 최단 경로 탐색

    나중에 다시 풀어봐야한다.

    참고: https://rebas.kr/701
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
#define MAX 501

using namespace std;

struct graph {
    int node; // 연결된 노드 
    int cost; // 비용 

    bool operator < (const graph t) const {return cost > t.cost;}
};

int N, M;
int S, D;

vector<vector<graph> > a; // 정방향 연결 벡터
vector<vector<graph> > b; // 역방향 연결 벡터 
vector<int> dist; // 최단 경로를 저장할 배열 
vector<vector<bool> > check; // 방문 체크 배열 

void dijkstra() {  
    priority_queue<graph> pq;
    pq.push({S, 0});
    fill(dist.begin(), dist.end(), INF); // 최단 경로 배열 INF으로 초기화 
    dist[S]=0; // 시작점의 비용은 0 

    while(!pq.empty()) {
        int cur=pq.top().node; 
        int d=pq.top().cost;
        pq.pop();

        if(dist[cur]<d) continue; // 현재 비용이 더 작은 경우 스킵 

        // 인접한 모든 노드 탐색 
        for(auto i : a[cur]) {
            int next=i.node; // 인접 노드
            int nd=d+i.cost; // 인접 노드에 가기 위한 비용 

            if(check[cur][next]) continue; // 최단 경로에 포함된 경우 스킵 

            if(dist[next]>nd) { // 현재 비용이 더 큰 경우 
                dist[next]=nd; // 비용 최소로 업데이트 
                pq.push({next, nd});
            }
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(D); // 목적지를 큐에 넣음

    while(!q.empty()) {
        int cur=q.front();
        q.pop();

        if(cur==S) continue; // 현재 노드와 시작점이 동일할 경우 스킵(이전 노드가 없음)

        // 인접한 노드 탐색 
        for(auto i : b[cur]) {
            int prev=i.node; // 이전 노드 
            int d=i.cost; // 비용 

            if(dist[cur]==dist[prev]+d) { // 현재 비용과 과거 비용에다 과거노드->현재노드로 오기 위한 비용을 더한 값이 같으면 
                check[prev][cur]=true; // 최단경로이므로 방문 처리
                q.push(prev);
            }
        }
    }
}

int main(void) {

    while(true) {
        cin >> N >> M;

        if(N==0 && M==0) break;

        cin >> S >> D;

        a = vector<vector<graph> >(N, vector<graph>());
        b = vector<vector<graph> >(N, vector<graph>());
        dist = vector<int>(N);
        check = vector<vector<bool> >(N, vector<bool>(N, false));

        for(int i=0;i<M;i++) {
            int U, V, P;

            cin >> U >> V >> P;
            a[U].push_back({V, P});
            b[V].push_back({U, P});
        }

        dijkstra();
        bfs();
        dijkstra();

        if(dist[D]!=INF) cout << dist[D] <<"\n";
        else cout << "-1\n";
    }

    return 0;
}