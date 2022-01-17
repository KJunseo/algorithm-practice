package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 예전에는 풀었었는데 이번에 풀려니 실패했다..
 * 시작점을 모두 큐에 넣고 bfs를 실행하는 것이 포인트
 */

public class 토마토_7576 {
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[1]);
        int m = Integer.parseInt(input[0]);

        int[][] result = new int[n + 1][m + 1];
        int[][] board = new int[n + 1][m + 1];
        Queue<Node> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String[] tomatoes = br.readLine().split(" ");
            for (int j = 0; j < tomatoes.length; j++) {
                int tomato = Integer.parseInt(tomatoes[j]);
                board[i][j] = tomato;
                if (tomato == 1) {
                    result[i][j] = 1;
                    queue.add(new Node(i, j));
                }
                if (tomato == -1) {
                    result[i][j] = -1;
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
                if (result[nx][ny] > 0 || board[nx][ny] != 0) {
                    continue;
                }
                result[nx][ny] = result[node.getX()][node.getY()] + 1;
                queue.add(new Node(nx, ny));
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (result[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                ans = Math.max(ans, result[i][j]);
            }
        }
        System.out.println(ans - 1);
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
