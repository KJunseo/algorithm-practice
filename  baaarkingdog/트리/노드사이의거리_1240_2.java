package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 노드사이의거리_1240_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static List<Node>[] tree;

    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        tree = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            tree[u].add(new Node(v, d));
            tree[v].add(new Node(u, d));
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            sb.append(dijkstra(u, v)).append("\n");
        }

        System.out.println(sb.toString());
    }

    private static int dijkstra(int u, int v) {
        int[] dist = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(u, 0));
        dist[u] = 0;

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int next = node.id;
            int d = node.dist;

            if (d > dist[next]) {
                continue;
            }

            for (Node n : tree[next]) {
                if (dist[n.id] > d + n.dist) {
                    dist[n.id] = d + n.dist;
                    pq.add(new Node(n.id, d + n.dist));
                }
            }
        }

        return dist[v];
    }

    static class Node implements Comparable<Node> {
        int id;
        int dist;

        public Node(int id, int dist) {
            this.id = id;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.dist, o.dist);
        }
    }
}
