package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 연결요소의개수_11724 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[][] graph;
    private static boolean[] visited;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new int[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        visited = new boolean[n + 1];

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            bfs(i);
            count++;
        }
        System.out.println(count);
    }

    private static void bfs(int node) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(node);
        visited[node] = true;

        while (!queue.isEmpty()) {
            Integer cur = queue.poll();

            for (int next = 0; next < graph[cur].length; next++) {
                int connect = graph[cur][next];

                if (connect == 0) {
                    continue;
                }

                if (visited[next]) {
                    continue;
                }

                queue.add(next);
                visited[next] = true;
            }
        }
    }
}
