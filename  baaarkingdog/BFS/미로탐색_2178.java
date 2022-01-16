package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 미로탐색_2178 {
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        int[][] visited = new int[n + 1][m + 1];
        int[][] board = new int[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            String[] piece = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(piece[j]);
            }
        }

        Queue<Node> queue = new LinkedList<>();
        visited[0][0] = 1;
        queue.add(new Node(0, 0));

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny] != 0 || board[nx][ny] != 1) {
                    continue;
                }
                visited[nx][ny] = visited[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }

        System.out.println(visited[n - 1][m - 1]);
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
