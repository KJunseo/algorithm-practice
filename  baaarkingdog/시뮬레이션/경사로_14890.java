package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 경사로_14890 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, l;
    private static int[][] map;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int rowBase = setRamp();
        turn();
        int colBase = setRamp();

        System.out.println(rowBase + colBase);
    }

    private static int setRamp() {
        int total = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            boolean flag = true;
            for (int j = 0; j < n - 1; j++) {
                int cur = map[i][j];
                int next = map[i][j + 1];

                if (cur == next) { // 같은 경우
                    count++;
                } else if (cur - next == 1) { // 내림차순인 경우
                    if (j + l >= n) {
                        flag = false;
                        break;
                    }
                    for (int k = 0; k < l; k++) {
                        if (map[i][j + 1 + k] != next) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        j = j + l - 1;
                        count = 0;
                    } else {
                        break;
                    }
                } else if (next - cur == 1) { // 오름차순인 경우
                    if (count < l) {
                        flag = false;
                        break;
                    }
                    count = 1;
                } else { // 차이가 2 이상인 경우
                    flag = false;
                    break;
                }
            }

            if (flag) {
                total++;
            }
        }

        return total;
    }

    private static void turn() {
        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = map[j][n - i - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = temp[i][j];
            }
        }
    }
}
