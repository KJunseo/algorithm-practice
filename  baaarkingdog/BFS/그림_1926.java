package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 그림_1926 {
    private static int[][] board;
    private static boolean[][] visited;

    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};

    private static int n;
    private static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        board = new int[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            String[] piece = br.readLine().split(" ");
            for (int j = 0; j < piece.length; j++) {
                board[i][j] = Integer.parseInt(piece[j]);
            }
        }

        int count = 0;
        int width = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    count++;
                    width = Math.max(width, bfs(i, j));
                }
            }
        }

        System.out.println(count);
        System.out.println(width);
    }

    private static int bfs(int x, int y) {
        int width = 1;
        Queue<Node> queue = new LinkedList<>();
        visited[x][y] = true;
        queue.add(new Node(x, y));
        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny] || board[nx][ny] != 1) {
                    continue;
                }
                visited[nx][ny] = true;
                width++;
                queue.add(new Node(nx, ny));
            }
        }
        return width;
    }
}

class Node {
    private int x;
    private int y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
