/*
    한 지점에서 다른 모든 지점의 거리를 구하는 것이라 다익스트라를 사용했다.
    다익스트라 코드는 참고하였다.
*/
#include <vector>
#include <queue> 
#define INF 1000000000

using namespace std;

int maxValue;

void dijkstra(int start, int d[], vector<pair<int, int> > a[]) {
    d[start] = 0;

    priority_queue<pair<int, int> > pq; 

    pq.push(make_pair(start, 0));
    
    while(!pq.empty()) {  
        int current = pq.top().first; 
        int distance = -pq.top().second;

        pq.pop();

        if(d[current] < distance) continue;

        for(int i=0;i<a[current].size();i++) {
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;

            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    vector<pair<int, int> > a[n+1];
    int d[n+1];
    int answer=0;

    for(int i=1;i<=n;i++) {
        d[i] = INF;
    }

    for(int i=0;i<edge.size();i++) {
        a[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        a[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }

    dijkstra(1, d, a);

    for(int i=1;i<=n;i++) {
        if(maxValue<d[i]) maxValue=d[i];
    }
    
    for(int i=1;i<=n;i++) {
        if(maxValue==d[i]) answer++;
    }    
    
    return answer;
}