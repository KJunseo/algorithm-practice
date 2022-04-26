package blind2021;

public class 합승택시요금 {

    public int solution(int n, int s, int a, int b, int[][] fares) {
        int[][] dist = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = 100_001;
                }
            }
        }

        for (int[] fare : fares) {
            int from = fare[0];
            int to = fare[1];
            int cost = fare[2];

            dist[from][to] = Math.min(dist[from][to], cost);
            dist[to][from] = Math.min(dist[to][from], cost);
        }

        for (int k = 0; k < n + 1; k++) {
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int answer = Integer.MAX_VALUE;
        for (int k = 1; k < n + 1; k++) {
            answer = Math.min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
        }

        return answer;
    }
}
