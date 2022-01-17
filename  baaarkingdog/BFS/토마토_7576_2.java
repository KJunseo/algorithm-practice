package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 토마토_7576_2 {
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] size = br.readLine().split(" ");
        int n = Integer.parseInt(size[1]);
        int m = Integer.parseInt(size[0]);

        int[][] visited = new int[n + 1][m + 1];
        int[][] storage = new int[n + 1][m + 1];
        Queue<Node> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                int tomato = Integer.parseInt(input[j]);
                storage[i][j] = tomato;
                if (tomato == 1) {
                    visited[i][j] = 1;
                    queue.add(new Node(i, j));
                }
                if (tomato == -1) {
                    visited[i][j] = -1;
                }
            }
        }

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.getX() + dx[dir];
                int ny = node.getY() + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny] > 0 || storage[nx][ny] != 0) {
                    continue;
                }
                visited[nx][ny] = visited[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }

        int date = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                date = Math.max(date, visited[i][j]);
            }
        }

        System.out.println(date - 1);
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
