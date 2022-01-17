package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 하나의 큐에 지훈을 먼저넣고 불을 넣은다음 BFS를 수행하려고 하였으나 실패했다.
 * 불을 먼저 BFS 하고 그 후 지훈을 BFS하면서 해당 칸에 불보다 지훈이 먼저 갈 수 있는 경우를 살펴보는 방식이었다.
 */

public class 불_4179 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int n;
    static int m;

    public static void main(String[] args) throws IOException {
        String[] size = br.readLine().split(" ");
        n = Integer.parseInt(size[0]);
        m = Integer.parseInt(size[1]);

        char[][] map = new char[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            String[] c = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                map[i][j] = c[j].charAt(0);
            }
        }

        int[][] fire = fireBfs(map);
        int answer = jhBfs(map, fire);
        if (answer == -1) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println(answer);
        }
    }

    private static int[][] fireBfs(char[][] map) {
        int[][] visited = new int[n + 1][m + 1];
        Queue<Node> queue = new LinkedList<>();
        init(map, visited, queue, 'F');

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny] > 0 || map[nx][ny] == '#') {
                    continue;
                }
                visited[nx][ny] = visited[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }
        return visited;
    }

    private static void init(char[][] map, int[][] visited, Queue<Node> queue, char type) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == type) {
                    visited[i][j] = 1;
                    queue.add(new Node(i, j));
                }
            }
        }
    }

    private static int jhBfs(char[][] map, int[][] fire) {
        int[][] visited = new int[n + 1][m + 1];
        Queue<Node> queue = new LinkedList<>();
        init(map, visited, queue, 'J');

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    return visited[node.getX()][node.getY()];
                }
                if (map[nx][ny] != '.' || visited[nx][ny] > 0) {
                    continue;
                }
                int jh = visited[node.getX()][node.getY()] + 1;
                if (fire[nx][ny] > jh || fire[nx][ny] == 0) {
                    visited[nx][ny] = jh;
                    queue.add(new Node(nx, ny));
                }
            }
        }
        return -1;
    }
}

//class Node {
//    private int x;
//    private int y;
//
//    public Node(int x, int y) {
//        this.x = x;
//        this.y = y;
//    }
//
//    public int getX() {
//        return x;
//    }
//
//    public int getY() {
//        return y;
//    }
//}
