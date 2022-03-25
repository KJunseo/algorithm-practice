package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 로봇청소기_14503 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static Robot robot;
    private static int[][] map;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        robot = new Robot(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken())
        );

        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int count = 0;
        while (true) {
            if (map[robot.x][robot.y] == 0) {
                count++;
            }
            map[robot.x][robot.y] = -1;

            boolean canClean = false;
            for (int i = 0; i < 4; i++) {
                robot.turnLeft();

                int nx = robot.x + dx[robot.dir];
                int ny = robot.y + dy[robot.dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (map[nx][ny] == 0) {
                    robot.go();
                    canClean = true;
                    break;
                }
            }

            if (canClean) {
                continue;
            }

            if (map[robot.x - dx[robot.dir]][robot.y - dy[robot.dir]] == 1) {
                break;
            }

            robot.goBack();
        }

        System.out.println(count);
    }

    static class Robot {
        int x;
        int y;
        int dir;

        public Robot(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        public void turnLeft() {
            dir = (dir + 3) % 4;
        }

        public void go() {
            this.x += dx[dir];
            this.y += dy[dir];
        }

        public void goBack() {
            this.x -= dx[dir];
            this.y -= dy[dir];
        }
    }
}
