package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 감시_15683_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[][] map;
    private static List<CCTV> cctvs;

    private static int min;

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        cctvs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if (map[i][j] != 0 && map[i][j] != 6) {
                    cctvs.add(new CCTV(i, j, map[i][j]));
                }
                if (map[i][j] == 0) {
                    min++;
                }
            }
        }

        dfs(0);

        System.out.println(min);
    }

    private static void dfs(int cctvIndex) {
        if (cctvIndex == cctvs.size()) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) {
                        count++;
                    }
                }
            }
            min = Math.min(min, count);
            return;
        }

        int[][] temp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = map[i][j];
            }
        }

        CCTV cctv = cctvs.get(cctvIndex);

        if (cctv.type == 1) {
            for (int dir = 0; dir < 4; dir++) {
                search(cctv.x, cctv.y, dir);
                dfs(cctvIndex + 1);
                previousState(temp);
            }
        }
        if (cctv.type == 2) {
            for (int dir = 0; dir < 2; dir++) {
                search(cctv.x, cctv.y, dir);
                search(cctv.x, cctv.y, dir + 2);
                dfs(cctvIndex + 1);
                previousState(temp);
            }
        }
        if (cctv.type == 3) {
            for (int dir = 0; dir < 4; dir++) {
                search(cctv.x, cctv.y, dir);
                search(cctv.x, cctv.y, dir + 1);
                dfs(cctvIndex + 1);
                previousState(temp);
            }
        }
        if (cctv.type == 4) {
            for (int dir = 0; dir < 4; dir++) {
                search(cctv.x, cctv.y, dir);
                search(cctv.x, cctv.y, dir + 1);
                search(cctv.x, cctv.y, dir + 2);
                dfs(cctvIndex + 1);
                previousState(temp);
            }
        }
        if (cctv.type == 5) {
            for (int dir = 0; dir < 4; dir++) {
                search(cctv.x, cctv.y, dir);
            }
            dfs(cctvIndex + 1);
            previousState(temp);
        }
    }

    private static void previousState(int[][] temp) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = temp[i][j];
            }
        }
    }

    private static void search(int x, int y, int dir) {
        dir %= 4;
        while (true) {
            x += dx[dir];
            y += dy[dir];

            if (x < 0 || y < 0 || x >= n || y >= m) {
                return;
            }
            if (map[x][y] == 6) {
                return;
            }
            if (map[x][y] != 0) {
                continue;
            }
            map[x][y] = 7;
        }
    }
}
