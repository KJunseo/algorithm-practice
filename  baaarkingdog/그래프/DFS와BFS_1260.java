package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class DFS와BFS_1260 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m, v;
    private static List<Integer>[] graph;
    private static boolean[] visited;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        graph = new List[n + 1];
        for (int i = 0; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph[u].add(v);
            graph[v].add(u);
        }

        for (int i = 0; i < n + 1; i++) {
            Collections.sort(graph[i]);
        }

        visited = new boolean[n + 1];
        dfs(v);
        sb.append("\n");

        for (int i = 0; i < n + 1; i++) {
            visited[i] = false;
        }
        bfs(v);

        System.out.println(sb.toString());
    }

    private static void dfs(int cur) {
        if (visited[cur]) {
            return;
        }

        visited[cur] = true;
        sb.append(cur).append(" ");

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur].get(i);
            dfs(next);
        }
    }

    private static void bfs(int cur) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(cur);
        visited[cur] = true;
        sb.append(cur).append(" ");

        while (!queue.isEmpty()) {
            Integer node = queue.poll();

            for (int i = 0; i < graph[node].size(); i++) {
                int next = graph[node].get(i);

                if (visited[next]) {
                    continue;
                }

                queue.add(next);
                visited[next] = true;
                sb.append(next).append(" ");
            }
        }
    }
}
