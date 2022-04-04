package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 로봇청소기_14503_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[][] map;
    private static int answer;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Robot robot = new Robot(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            robot.clean();

            boolean flag = false;
            for (int i = 0; i < 4; i++) {
                robot.turnLeft();

                int nx = robot.x + dx[robot.dir];
                int ny = robot.y + dy[robot.dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (map[nx][ny] == 0) {
                    flag = true;
                    robot.go();
                    break;
                }
            }

            if (flag) {
                continue;
            }

            if (map[robot.x - dx[robot.dir]][robot.y - dy[robot.dir]] == 1) {
                break;
            }
            robot.back();
        }

        System.out.println(answer);
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

        public void clean() {
            if (map[x][y] == 0) {
                answer++;
            }
            map[x][y] = -1;
        }

        public void turnLeft() {
            dir = (4 + dir - 1) % 4;
        }

        public void go() {
            x += dx[dir];
            y += dy[dir];
        }

        public void back() {
            x -= dx[dir];
            y -= dy[dir];
        }
    }
}
