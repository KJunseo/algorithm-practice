package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 불_5427 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int T;
    private static int W, H;

    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};

    private static char[][] map;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            map = new char[H][W];
            Queue<Pos> sg = new LinkedList<>();
            Queue<Pos> fire = new LinkedList<>();
            int[][] sgVisited = new int[H][W];
            int[][] fireVisited = new int[H][W];
            for (int i = 0; i < H; i++) {
                String input = br.readLine();
                for (int j = 0; j < W; j++) {
                    map[i][j] = input.charAt(j);
                    if (map[i][j] == '@') {
                        sg.add(new Pos(i, j));
                    }
                    if (map[i][j] == '*') {
                        fire.add(new Pos(i, j));
                    }
                }
            }

            fireBfs(fire, fireVisited);
            int answer = sgBfs(sg, sgVisited, fireVisited);

            if (answer == -1) {
                System.out.println("IMPOSSIBLE");
            } else {
                System.out.println(answer);
            }
        }
    }

    private static void fireBfs(Queue<Pos> queue, int[][] visited) {
        while (!queue.isEmpty()) {
            Pos cur = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                    continue;
                }

                if (visited[nx][ny] > 0) {
                    continue;
                }

                if (map[nx][ny] == '#' || map[nx][ny] == '*') {
                    continue;
                }

                visited[nx][ny] = visited[cur.x][cur.y] + 1;
                queue.add(new Pos(nx, ny));
            }
        }
    }

    private static int sgBfs(Queue<Pos> queue, int[][] visited, int[][] fireVisited) {
        Pos sg = queue.peek();
        if (sg.x == 0 || sg.x == H - 1 || sg.y == 0 || sg.y == W - 1) {
            return 1;
        }

        while (!queue.isEmpty()) {
            Pos cur = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= H|| ny >= W) {
                    return visited[cur.x][cur.y] + 1;
                }

                if (visited[nx][ny] > 0) {
                    continue;
                }

                if (map[nx][ny] == '#' || map[nx][ny] == '*') {
                    continue;
                }

                if (fireVisited[nx][ny] == 0 || fireVisited[nx][ny] > visited[cur.x][cur.y] + 1) {
                    visited[nx][ny] = visited[cur.x][cur.y] + 1;
                    queue.add(new Pos(nx, ny));
                }
            }
        }
        return -1;
    }
}
