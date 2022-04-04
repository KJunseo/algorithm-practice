package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 바이러스_2606 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static List<Integer>[] connection;
    private static boolean[] visited;
    private static int count;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        connection = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            connection[i] = new ArrayList<>();
        }

        StringTokenizer st;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            connection[u].add(v);
            connection[v].add(u);
        }

        visited = new boolean[n + 1];
        dfs(1);

        System.out.println(count - 1);
    }

    private static void dfs(int cur) {
        visited[cur] = true;
        count++;

        List<Integer> adj = connection[cur];
        for (int i = 0; i < adj.size(); i++) {
            Integer next = adj.get(i);
            if (visited[next]) {
                continue;
            }
            dfs(next);
        }
    }
}
