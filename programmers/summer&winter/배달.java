/*
    다익스트라를 사용하는 문제였다.
    다익스트라를 아직 안보고는 구현하지 못하여서 다익스트라 코드를 참고하여 문제에 적용했다.
    자바로 알고리즘 문제를 푸는 것이 안 익숙해서 적응하는데 시간이 좀 걸릴 것 같다...
*/
import java.util.*;

class 배달 {

    class Edge implements Comparable<Edge> {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to; // 목적지 
            this.weight = weight; // 걸리는 시간 
        }

        @Override
        public int compareTo(Edge e) {
            return this.weight - e.weight;
        }
    }

    PriorityQueue<Edge> pq;
    ArrayList<ArrayList<Edge>> adj;
    int [] dist;
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;

        pq = new PriorityQueue<>();
        adj = new ArrayList<>();
        dist = new int[N+1];

        Arrays.fill(dist, Integer.MAX_VALUE); // 가장 큰 값으로 초기화 

        for(int i=0;i<=N;i++) {
            adj.add(new ArrayList<>());
        }

        // 양방향으로 연결 
        for(int i=0;i<road.length;i++) {
            adj.get(road[i][0]).add(new Edge(road[i][1], road[i][2]));
            adj.get(road[i][1]).add(new Edge(road[i][0], road[i][2]));
        }

        dist[1] = 0; // 탐색 시작 지점 최소 비용은 0이다.
        pq.offer(new Edge(1, 0)); // 시작지점 우선순위 큐에 삽입 

        dijkstra();

        for(int distance : dist) {
            if(distance<=K) answer++;
        }
        
        return answer;
    }

    private void dijkstra() {
        while(!pq.isEmpty()) {
            Edge temp = pq.poll(); // 가장 위의 것 꺼내서 

            // 인접 노드 모두 조사 
            for(Edge e : adj.get(temp.to)) {

                // 직접 가는 것 보다, 거쳐서 가는 것이 더 작으면 업데이트 후 집어 넣음 
                if(dist[e.to] > dist[temp.to] + e.weight) {
                    dist[e.to] = dist[temp.to] + e.weight;
                    pq.offer(e);
                }
            }
        }
    }
}
