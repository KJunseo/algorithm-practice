package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 구슬탈출2_13460 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static char[][] map;
    private static Marble red;
    private static Marble blue;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                map[i][j] = input[j].charAt(0);

                if (map[i][j] == 'R') {
                    red = new Marble(i, j, 0);
                }
                if (map[i][j] == 'B') {
                    blue = new Marble(i, j, 0);
                }
            }
        }

        bfs();

    }

    private static void bfs() {
        Queue<Marble> queue = new LinkedList<>();
        boolean[][][][] visited = new boolean[n][m][n][m];
        queue.add(red);
        queue.add(blue);
        visited[red.x][red.y][blue.x][blue.y] = true;

        while (!queue.isEmpty()) {
            Marble rMarble = queue.poll();
            Marble bMarble = queue.poll();

            if (rMarble.moveCount >= 10) {
                break;
            }

            for (int dir = 0; dir < 4; dir++) {
                int rx = rMarble.x;
                int ry = rMarble.y;
                int bx = bMarble.x;
                int by = bMarble.y;
                int rDist = 0;
                int bDist = 0;

                while (map[rx + dx[dir]][ry + dy[dir]] != '#' && map[rx][ry] != 'O') {
                    rx += dx[dir];
                    ry += dy[dir];
                    rDist++;
                }

                while (map[bx + dx[dir]][by + dy[dir]] != '#' && map[bx][by] != 'O') {
                    bx += dx[dir];
                    by += dy[dir];
                    bDist++;
                }

                if (map[bx][by] == 'O') {
                    continue;
                }

                if (map[rx][ry] == 'O') {
                    System.out.println(rMarble.moveCount + 1);
                    return;
                }

                if (rx == bx && ry == by) {
                    if (rDist > bDist) {
                        rx -= dx[dir];
                        ry -= dy[dir];
                    } else {
                        bx -= dx[dir];
                        by -= dy[dir];
                    }
                }

                if (visited[rx][ry][bx][by]) {
                    continue;
                }
                visited[rx][ry][bx][by] = true;

                queue.add(new Marble(rx, ry, rMarble.moveCount + 1));
                queue.add(new Marble(bx, by, bMarble.moveCount + 1));

            }
        }
        System.out.println(-1);
    }

    static class Marble {
        int x;
        int y;
        int moveCount;

        public Marble(int x, int y, int moveCount) {
            this.x = x;
            this.y = y;
            this.moveCount = moveCount;
        }
    }

//    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//    private static int n, m;
//    private static char[][] map;
//    private static Bead red;
//    private static Bead blue;
//
//    private static int answer = Integer.MAX_VALUE;
//
//    private static int[] dx = {-1, 0, 1, 0};
//    private static int[] dy = {0, 1, 0, -1};
//
//    public static void main(String[] args) throws IOException {
//        StringTokenizer st = new StringTokenizer(br.readLine());
//        n = Integer.parseInt(st.nextToken());
//        m = Integer.parseInt(st.nextToken());
//
//        map = new char[n][m];
//        for (int i = 0; i < n; i++) {
//            String[] input = br.readLine().split("");
//            for (int j = 0; j < m; j++) {
//                map[i][j] = input[j].charAt(0);
//
//                if (map[i][j] == 'R') {
//                    red = new Bead(i, j, 'R');
//                }
//
//                if (map[i][j] == 'B') {
//                    blue = new Bead(i, j, 'B');
//                }
//            }
//        }
//
//        dfs(1, -1);
//
//        if (answer == Integer.MAX_VALUE) {
//            answer = -1;
//        }
//
//        System.out.println(answer);
//    }
//
//    private static void dfs(int count, int prevDir) {
//        if (count > 10 || count >= answer) {
//            return;
//        }
//
//        if (red.escape || blue.escape) {
//            return;
//        }
//
//        Bead originalRed = new Bead(red.x, red.y, red.type);
//        Bead originalBlue = new Bead(blue.x, blue.y, blue.type);
//
//        char[][] originalMap = new char[n][m];
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                originalMap[i][j] = map[i][j];
//            }
//        }
//
//        for (int dir = 0; dir < 4; dir++) {
//            if (dir == prevDir) {
//                continue;
//            }
//
//            boolean flag = isReadAhead(dir);
//
//            if (flag) {
//                red.move(dir);
//                blue.move(dir);
//            } else {
//                blue.move(dir);
//                red.move(dir);
//            }
//
//            if (red.escape && !blue.escape) {
//                answer = Math.min(answer, count);
//                return;
//            }
//
//            if (blue.escape) {
//                return;
//            }
//
//            dfs(count + 1, dir);
//            restore(originalRed, originalBlue, originalMap);
//        }
//    }
//
//    private static boolean isReadAhead(int dir) {
//        if (dir == 0) {
//            return red.x < blue.x;
//        } else if (dir == 1) {
//            return red.y > blue.y;
//        } else if (dir == 2) {
//            return red.x > blue.x;
//        } else {
//            return red.y < blue.y;
//        }
//    }
//
//    private static void restore(Bead originalRed, Bead originalBlue, char[][] originalMap) {
//        red = new Bead(originalRed.x, originalRed.y, originalRed.type);
//        blue = new Bead(originalBlue.x, originalBlue.y, originalBlue.type);
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                map[i][j] = originalMap[i][j];
//            }
//        }
//    }
//
//    static class Bead {
//        int x;
//        int y;
//        char type;
//        boolean escape;
//
//        public Bead(int x, int y, char type) {
//            this.x = x;
//            this.y = y;
//            this.type = type;
//            this.escape = false;
//        }
//
//        public void move(int dir) {
//            int nx;
//            int ny;
//
//            while (true) {
//                nx = x + dx[dir];
//                ny = y + dy[dir];
//
//                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
//                    break;
//                }
//
//                if (map[nx][ny] == '#') {
//                    break;
//                }
//
//                if (map[nx][ny] == 'R' || map[nx][ny] == 'B') {
//                    break;
//                }
//
//                if (map[nx][ny] == 'O') {
//                    map[x][y] = '.';
//                    this.x = -1;
//                    this.y = -1;
//                    escape = true;
//                    break;
//                }
//
//                map[x][y] = '.';
//                this.x = nx;
//                this.y = ny;
//                map[x][y] = this.type;
//            }
//        }
//    }
}
