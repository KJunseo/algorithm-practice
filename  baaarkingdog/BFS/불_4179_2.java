package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 불_4179_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};

    private static int n;
    private static int m;

    public static void main(String[] args) throws IOException {
        String[] size = br.readLine().split(" ");
        n = Integer.parseInt(size[0]);
        m = Integer.parseInt(size[1]);

        char[][] map = new char[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = input.charAt(j);
            }
        }

        // 불 bfs
        int[][] fire = fireBfs(map);
        // 지훈 bfs
        jhBfs(map, fire);
    }

    private static int[][] fireBfs(char[][] map) {
        int[][] visited = new int[n + 1][m + 1];
        Queue<Node> queue = init(map, visited, 'F');

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (map[nx][ny] == '#' || visited[nx][ny] > 0) {
                    continue;
                }

                visited[nx][ny] = visited[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }

        return visited;
    }

    private static Queue<Node> init(char[][] map, int[][] visited, char type) {
        Queue<Node> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == type) {
                    visited[i][j] = 1;
                    queue.add(new Node(i, j));
                }
            }
        }
        return queue;
    }

    private static void jhBfs(char[][] map, int[][] fire) {
        int[][] visited = new int[n + 1][m + 1];
        Queue<Node> queue = init(map, visited, 'J');

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    System.out.println(visited[node.getX()][node.getY()]);
                    return;
                }

                if (map[nx][ny] != '.' || visited[nx][ny] > 0) {
                    continue;
                }
                if (fire[nx][ny] != 0 && fire[nx][ny] <= visited[node.getX()][node.getY()] + 1) {
                    continue;
                }
                visited[nx][ny] = visited[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }
        System.out.println("IMPOSSIBLE");
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
