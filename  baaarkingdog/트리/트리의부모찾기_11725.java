package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 트리의부모찾기_11725 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static List<Integer>[] tree;
    private static boolean[] visited;
    private static int[] parent;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        tree = new List[n + 1];
        for (int i = 1; i < n + 1; i++) {
            tree[i] = new ArrayList<>();
        }

        StringTokenizer st;
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }

        visited = new boolean[n + 1];
        parent = new int[n + 1];
        dfs(1);

        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= n; i++) {
            sb.append(parent[i]).append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int node) {
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node].get(i);

            if (visited[next]) {
                continue;
            }

            visited[node] = true;
            parent[next] = node;
            dfs(next);
        }
    }
}
