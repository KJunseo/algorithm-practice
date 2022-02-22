package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 적록색약_10026 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int N;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        char[][] normal = new char[N][N];
        char[][] weakness = new char[N][N];
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < N; j++) {
                char color = input.charAt(j);
                normal[i][j] = color;
                if (color == 'G') {
                    weakness[i][j] = 'R';
                } else {
                    weakness[i][j] = color;
                }
            }
        }

        System.out.println(countColor(normal) + " " + countColor(weakness));
    }

    private static int countColor(char[][] map) {
        int count = 0;
        boolean[][] visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, map, visited);
                    count++;
                }
            }
        }
        return count;
    }

    private static void bfs(int i, int j, char[][] map, boolean[][] visited) {
        char color = map[i][j];
        Queue<Node> queue = new LinkedList<>();
        visited[i][j] = true;
        queue.add(new Node(i, j));

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                    continue;
                }

                if (map[nx][ny] != color) {
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
