package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class 색종이만들기_2630 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int[][] paper;
    private static Map<Integer, Integer> count = new HashMap<>();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        paper = new int[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        count.put(0, 0);
        count.put(1, 0);

        calculate(0, 0, n);

        System.out.println(count.get(0));
        System.out.println(count.get(1));
    }

    private static void calculate(int x, int y, int n) {
        if (n == 1) {
            count.put(paper[x][y], count.get(paper[x][y]) + 1);
            return;
        }

        if (isAllSame(x, y, n)) {
            count.put(paper[x][y], count.get(paper[x][y]) + 1);
            return;
        }

        int l = n / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                calculate(x + i * l, y + j * l, l);
            }
        }
    }

    private static boolean isAllSame(int x, int y, int n) {
        int firstColor = paper[x][y];
        for (int i = x; i < x + n; i++){
            for (int j = y; j < y + n; j++) {
                if (firstColor != paper[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
