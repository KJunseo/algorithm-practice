package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class EASY2048_12100_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] map;
    private static int max;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0);

        System.out.println(max);
    }

    private static void dfs(int count) {
        if (count == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    max = Math.max(max, map[i][j]);
                }
            }
            return;
        }

        int[][] original = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                original[i][j] = map[i][j];
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            move(dir);

            dfs(count + 1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = original[i][j];
                }
            }
        }
    }

    private static void move(int dir) {
        while (dir-- > 0) {
            map = rotate();
        }

        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            int[] row = map[i];
            int index = 0;
            for (int j = 0; j < n; j++) {
                if (row[j] == 0) {
                    continue;
                }
                if (temp[i][index] == 0) {
                    temp[i][index] = row[j];
                } else if (temp[i][index] == row[j]){
                    temp[i][index++] *= 2;
                } else {
                    temp[i][++index] = row[j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = temp[i][j];
            }
        }
    }

    private static int[][] rotate() {
        int[][] rotatedMap = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotatedMap[i][j] = map[n - 1 - j][i];
            }
        }

        return rotatedMap;
    }
}
