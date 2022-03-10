package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class EASY2048_12100 {
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
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0);

        System.out.println(max);
    }

    private static void dfs(int num) {
        if (num == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    max = Math.max(max, map[i][j]);
                }
            }
            return;
        }

        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = map[i][j];
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            move(dir);

            dfs(num + 1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = temp[i][j];
                }
            }
        }
    }

    private static void move(int dir) {
        // map을 원래 방향으로 돌려주지 않아도 되는 이유는 백트래킹으로 모든 경우를 다 확인하기 때문임
        while (dir > 0) {
            map = rotate();
            dir--;
        }

        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            int[] arr = map[i];

            int index = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == 0) {
                    continue;
                }
                if (temp[i][index] == 0) {
                    temp[i][index] = arr[j];
                } else if (temp[i][index] == arr[j]) {
                    temp[i][index] *= 2;
                    index++;
                } else {
                    index++;
                    temp[i][index] = arr[j];
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
        int[][] rotated = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[i][j] = map[n - 1 - j][i];
            }
        }

        return rotated;
    }
}
