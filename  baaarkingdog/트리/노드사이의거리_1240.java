package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 노드사이의거리_1240 {
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

            sb.append(findDistance(u, -1, v, 0)).append("\n");
        }

        System.out.println(sb.toString());
    }

    private static int findDistance(int cur, int prev, int goal, int dist) {
        if (cur == goal) {
            return dist;
        }

        int d = 0;
        for (int i = 0; i < tree[cur].size(); i++) {
            Node nextNode = tree[cur].get(i);
            int next = nextNode.id;
            if (next == prev) {
                continue;
            }
            d += findDistance(next, cur, goal, dist + nextNode.dist);
        }

        return d;
    }

    static class Node {
        int id;
        int dist;

        public Node(int id, int dist) {
            this.id = id;
            this.dist = dist;
        }
    }
}
