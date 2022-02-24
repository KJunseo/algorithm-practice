package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class 종이의개수_1780 {
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

        count.put(-1, 0);
        count.put(0, 0);
        count.put(1, 0);

        calculate(0, 0, n);
        System.out.println(count.get(-1));
        System.out.println(count.get(0));
        System.out.println(count.get(1));
    }

    private static void calculate(int x1, int y1, int n) {
        if (n == 1) {
            count.put(paper[x1][y1], count.get(paper[x1][y1]) + 1);
            return;
        }

        boolean allSame = true;
        int firstValue = paper[x1][y1];
        for (int x = x1; x < x1 + n; x++) {
            for (int y = y1; y < y1 + n; y++) {
                if (paper[x][y] != firstValue) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) {
                break;
            }
        }

        if (allSame) {
            count.put(firstValue, count.get(firstValue) + 1);
            return;
        }

        int l = n / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                calculate(x1 + i * l, y1 + j * l, l);
            }
        }
    }
}
