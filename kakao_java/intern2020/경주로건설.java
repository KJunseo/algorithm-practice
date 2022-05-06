package intern2020;

import java.util.LinkedList;
import java.util.Queue;

public class 경주로건설 {
    private int[] dx = {-1, 0, 1, 0};
    private int[] dy = {0, 1, 0, -1};

    private int n;

    public int solution(int[][] board) {
        this.n = board.length;
        return bfs(board);
    }

    private int bfs(int[][] board) {
        int[][][] cost = new int[4][n][n];
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cost[dir][i][j] = Integer.MAX_VALUE;
                }
            }
        }

        Queue<Car> queue = new LinkedList<>();
        queue.add(new Car(0, 0, 0, 1));
        queue.add(new Car(0, 0, 0, 2));

        while (!queue.isEmpty()) {
            Car car = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = car.x + dx[dir];
                int ny = car.y + dy[dir];
                int c = car.cost + 100;
                if (car.dir != dir) {
                    c += 500;
                }

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }
                if (board[nx][ny] == 1) {
                    continue;
                }
                if (cost[dir][nx][ny] <= c) {
                    continue;
                }

                cost[dir][nx][ny] = c;
                queue.add(new Car(nx, ny, c, dir));
            }
        }

        int answer = Integer.MAX_VALUE;
        for (int dir = 0; dir < 4; dir++) {
            answer = Math.min(answer, cost[dir][n - 1][n - 1]);
        }

        return answer;
    }

    static class Car {
        int x;
        int y;
        int cost;
        int dir;

        public Car(int x, int y, int cost, int dir) {
            this.x = x;
            this.y = y;
            this.cost = cost;
            this.dir = dir;
        }
    }
}
