package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class PuyoPuyo_11559 {
    private static int WIDTH = 6;
    private static int HEIGHT = 12;

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static char[][] map = new char[HEIGHT][WIDTH];
    private static int answer;
    private static boolean flag = false;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < HEIGHT; i++) {
            String input = br.readLine();
            for (int j = 0; j < WIDTH; j++) {
                map[i][j] = input.charAt(j);
            }
        }

        while (true) {
            flag = false;
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (map[i][j] == '.') {
                        continue;
                    }
                    bfs(i, j);
                }
            }
            if (flag) {
                answer++;
                gravity2();
            } else {
                break;
            }
        }

        System.out.println(answer);
    }

    // 처음 풀이
    private static void gravity() {
        for (int j = 0; j < WIDTH; j++) {
            int temp = HEIGHT - 1;
            while (temp >= 0) {
                if (map[temp][j] != '.') {
                    temp--;
                    continue;
                }

                for (int i = temp; i >= 0; i--) {
                    if (map[i][j] != '.') {
                        map[temp][j] = map[i][j];
                        map[i][j] = '.';
                        break;
                    }
                }
                temp--;
            }
        }
    }

    // 다른 풀이
    private static void gravity2() {
        for (int j = 0; j < WIDTH; j++) {
            List<Character> temp = new ArrayList<>();

            for (int i = HEIGHT - 1; i >= 0; i--) {
                if (map[i][j] != '.') {
                    temp.add(map[i][j]);
                }
            }

            while (temp.size() < HEIGHT) {
                temp.add('.');
            }

            for (int i = 0; i < HEIGHT; i++) {
                map[i][j] = temp.get(HEIGHT - 1 - i);
            }
        }
    }

    private static void bfs(int r, int c) {
        boolean[][] visited = new boolean[12][6];
        Queue<Pair> queue = new LinkedList<>();
        visited[r][c] = true;
        queue.add(new Pair(r, c));
        char puyo = map[r][c];
        int count = 0;
        List<Pair> temp = new ArrayList<>();
        while (!queue.isEmpty()) {
            Pair cur = queue.poll();
            count++;
            temp.add(cur);

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= HEIGHT || ny >= WIDTH) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                if (map[nx][ny] != puyo) {
                    continue;
                }

                visited[nx][ny] = true;
                queue.add(new Pair(nx, ny));
            }
        }

        if (count >= 4) {
            flag = true;
            for (Pair pair : temp) {
                map[pair.x][pair.y] = '.';
            }
        }
    }
}

class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
