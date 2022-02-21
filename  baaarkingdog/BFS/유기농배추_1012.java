package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 유기농배추_1012 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int T;
    private static int M, N, K;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, -1, 0, 1};

    private static int[][] field;
    private static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            field = new int[M][N];
            visited = new boolean[M][N];

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int X = Integer.parseInt(st.nextToken());
                int Y = Integer.parseInt(st.nextToken());
                field[X][Y] = 1;
            }

            int count = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (field[i][j] == 1 && !visited[i][j]) {
                        bfs(i, j);
                        count++;
                    }
                }
            }
            System.out.println(count);
        }
    }

    private static void bfs(int x, int y) {
        Queue<Node> queue = new LinkedList<>();
        visited[x][y] = true;
        queue.add(new Node(x, y));

        while (!queue.isEmpty()) {
            Node cur = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.getX() + dx[dir];
                int ny = cur.getY() + dy[dir];

                if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
                    continue;
                }

                if (field[nx][ny] == 0) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                queue.add(new Node(nx, ny));
            }
        }
    }
}
