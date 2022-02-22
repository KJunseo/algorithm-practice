package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 토마토_7569 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int M, N, H;

    private static int[] dx = {-1, 1, 0, 0, 0, 0};
    private static int[] dy = {0, 0, -1, 1, 0, 0};
    private static int[] dz = {0, 0, 0, 0, 1, -1};

    private static int[][][] map;
    private static int[][][] visited;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        Queue<Position> queue = new LinkedList<>();
        map = new int[N][M][H];
        visited = new int[N][M][H];
        for (int k = 0; k < H; k++) {
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    map[i][j][k] = Integer.parseInt(st.nextToken());
                    if (map[i][j][k] == 1) {
                        visited[i][j][k] = 1;
                        queue.add(new Position(i, j, k));
                    }
                }
            }
        }

        bfs(queue, map);

        int day = 0;
        for (int k = 0; k < H; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (map[i][j][k] == 0 && visited[i][j][k] == 0) {
                        System.out.println(-1);
                        return;
                    }
                    day = Math.max(day, visited[i][j][k]);
                }
            }
        }

        System.out.println(day - 1);
    }

    private static void bfs(Queue<Position> queue, int[][][] map) {
        while (!queue.isEmpty()) {
            Position cur = queue.poll();

            for (int dir = 0; dir < 6; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                int nz = cur.z + dz[dir];

                if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) {
                    continue;
                }

                if (visited[nx][ny][nz] > 0) {
                    continue;
                }

                if (map[nx][ny][nz] == 0) {
                    visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] + 1;
                    queue.add(new Position(nx, ny, nz));
                }
            }
        }
    }
}

class Position {
    int x;
    int y;
    int z;

    public Position(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}
