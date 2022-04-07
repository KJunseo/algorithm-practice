package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 트리_4803 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static List<Integer>[] graph;
    private static int treeCount;
    private static boolean isTree;
    private static boolean[] visited;

    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int tc = 1;
        while (true) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) {
                break;
            }

            graph = new List[n + 1];
            for (int i = 1; i <= n; i++) {
                graph[i] = new ArrayList<>();
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                graph[u].add(v);
                graph[v].add(u);
            }

            visited = new boolean[n + 1];
            treeCount = 0;
            for (int i = 1; i <= n; i++) {
                if (visited[i]) {
                    continue;
                }

                isTree = true;
                dfs(i, 0);
                if (isTree) {
                    treeCount++;
                }
            }

            sb.append("Case ").append(tc).append(": ");

            if (treeCount == 0) {
                sb.append("No trees.").append("\n");
            } else if (treeCount == 1) {
                sb.append("There is one tree.").append("\n");
            } else {
                sb.append("A forest of ").append(treeCount).append(" trees.").append("\n");
            }

            tc++;
        }

        System.out.println(sb.toString());
    }

    private static void dfs(int cur, int prev) {
        if (visited[cur]) {
            isTree = false;
            return;
        }

        visited[cur] = true;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur].get(i);

            if (next == prev) {
                continue;
            }

            dfs(next, cur);
        }
    }
}
