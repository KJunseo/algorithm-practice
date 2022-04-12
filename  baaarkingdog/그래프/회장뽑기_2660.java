package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 회장뽑기_2660 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] graph;

    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        graph = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                graph[i][j] = 51;
            }
        }

        while (true) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            if (u == -1 && v == -1) {
                break;
            }

            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        int[] scores = new int[n + 1];
        int chairmanScore = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            int score = 0;
            for (int j = 1; j <= n; j++) {
                score = Math.max(score, graph[i][j]);
            }
            scores[i] = score;
            chairmanScore = Math.min(chairmanScore, score);
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (scores[i] == chairmanScore) {
                count++;
            }
        }

        sb.append(chairmanScore).append(" ").append(count).append("\n");

        for (int i = 1; i <= n; i++) {
            if (scores[i] == chairmanScore) {
                sb.append(i).append(" ");
            }
        }

        System.out.println(sb.toString());
    }
}
