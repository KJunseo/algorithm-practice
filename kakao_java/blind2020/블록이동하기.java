package blind2020;

import java.util.LinkedList;
import java.util.Queue;

public class 블록이동하기 {
    private int[][] board;
    private int n;

    private int answer = 0;

    private int[] dx = {1, 0, -1, 0};
    private int[] dy = {0, 1, 0, -1};

    public int solution(int[][] board) {
        this.board = board;
        n = board.length;

        bfs();

        return answer;
    }

    private void bfs() {
        boolean[][][] visited = new boolean[n][n][2];
        Queue<Robot> queue = new LinkedList<>();
        queue.add(new Robot(0, 0, 0, 1));

        while (!queue.isEmpty()) {
            Robot robot = queue.poll();

            if (robot.x1 < 0 || robot.y1 < 0 || robot.x1 >= n || robot.y1 >= n) {
                continue;
            }
            if (robot.x2 < 0 || robot.y2 < 0 || robot.x2 >= n || robot.y2 >= n) {
                continue;
            }
            if (board[robot.x1][robot.y1] == 1 || board[robot.x2][robot.y2] == 1) {
                continue;
            }
            if (visited[robot.x1][robot.y1][robot.dir] && visited[robot.x2][robot.y2][robot.dir]) {
                continue;
            }

            if ((robot.x1 == n - 1 && robot.y1 == n - 1) || (robot.x2 == n - 1 && robot.y2 == n - 1)) {
                answer = robot.time;
                return;
            }

            visited[robot.x1][robot.y1][robot.dir] = true;
            visited[robot.x2][robot.y2][robot.dir] = true;

            for (int dir = 0; dir < 4; dir++) {
                int nx1 = robot.x1 + dx[dir];
                int ny1 = robot.y1 + dy[dir];
                int nx2 = robot.x2 + dx[dir];
                int ny2 = robot.y2 + dy[dir];

                queue.add(new Robot(nx1, ny1, nx2, ny2, robot.dir, robot.time + 1));
            }

            if (robot.dir == 0) { // 가로
                if (robot.x1 - 1 >= 0 && board[robot.x1 - 1][robot.y1] == 0 && board[robot.x2 - 1][robot.y2] == 0) {
                    queue.add(new Robot(robot.x1, robot.y1, robot.x1 - 1, robot.y1, 1, robot.time + 1));
                    queue.add(new Robot(robot.x2, robot.y2, robot.x2 - 1, robot.y2, 1, robot.time + 1));
                }
                if (robot.x1 + 1 <= (board.length - 1) && board[robot.x1 + 1][robot.y1] == 0 && board[robot.x2 + 1][robot.y2] == 0) {
                    queue.add(new Robot(robot.x1, robot.y1, robot.x1 + 1, robot.y1, 1, robot.time + 1));
                    queue.add(new Robot(robot.x2, robot.y2, robot.x2 + 1, robot.y2, 1, robot.time + 1));
                }
            } else {
                if (robot.y1 - 1 >= 0 && board[robot.x1][robot.y1 - 1] == 0 && board[robot.x2][robot.y2 - 1] == 0) {
                    queue.add(new Robot(robot.x1, robot.y1, robot.x1, robot.y1 - 1, 0, robot.time + 1));
                    queue.add(new Robot(robot.x2, robot.y2, robot.x2, robot.y2 - 1, 0, robot.time + 1));
                }
                if (robot.y1 + 1 <= (board.length - 1) && board[robot.x1][robot.y1 + 1] == 0 && board[robot.x2][robot.y2 + 1] == 0) {
                    queue.add(new Robot(robot.x1, robot.y1, robot.x1, robot.y1 + 1, 0, robot.time + 1));
                    queue.add(new Robot(robot.x2, robot.y2, robot.x2, robot.y2 + 1, 0, robot.time + 1));
                }
            }
        }
    }

    static class Robot {
        int x1;
        int y1;
        int x2;
        int y2;
        int dir;
        int time;

        public Robot(int x1, int y1, int x2, int y2) {
            this(x1, y1, x2, y2, 0, 0);
        }

        public Robot(int x1, int y1, int x2, int y2, int dir, int time) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.dir = dir;
            this.time = time;
        }
    }
}
