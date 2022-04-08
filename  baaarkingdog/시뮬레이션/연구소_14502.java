package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 연구소_14502 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[][] map;
    private static int answer;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        setWall(0);

        System.out.println(answer);
    }

    private static void setWall(int count) {
        if (count == 3) {
            answer = Math.max(answer, bfs());
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    setWall(count + 1);
                    map[i][j] = 0;
                }
            }
        }
    }

    private static int bfs() {
        Queue<Node> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        int[][] originalMap = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                originalMap[i][j] = map[i][j];
                if (map[i][j] == 2) {
                    queue.add(new Node(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.x + dx[dir];
                int ny = node.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (map[nx][ny] != 0) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                map[nx][ny] = 2;
                queue.add(new Node(nx, ny));
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    count++;
                }
                map[i][j] = originalMap[i][j];
            }
        }

        return count;
    }

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
