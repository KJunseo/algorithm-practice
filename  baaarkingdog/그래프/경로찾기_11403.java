package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 경로찾기_11403 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] graph;
    private static int[][] answer;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        answer = new int[n][n];

        graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            dfs(i, i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(answer[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    private static void dfs(int start, int parent) {
        for (int i = 0; i < graph[start].length; i++) {
            int next = graph[start][i];

            if (next == 0) {
                continue;
            }

            if (answer[parent][i] == 0) {
                answer[parent][i] = 1;
                dfs(i, parent);
            }
        }
    }
}
