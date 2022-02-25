package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NQueen_9663 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int count = 0;

    private static boolean[] isUsed1 = new boolean[30];
    private static boolean[] isUsed2 = new boolean[30];
    private static boolean[] isUsed3 = new boolean[30];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        dfs(0);

        System.out.println(count);
    }

    // 재귀 depth = 세로줄
    private static void dfs(int cur) {
        if (cur == n) {
            count++;
            return;
        }

        for (int i = 0; i < n; i++) { // 현재 세로줄의 몇 번째 가로줄
            if (isUsed1[i] || isUsed2[cur + i] || isUsed3[cur - i + n - 1]) {
                continue;
            }
            isUsed1[i] = true;
            isUsed2[cur + i] = true;
            isUsed3[cur - i + n - 1] = true;

            dfs(cur + 1);

            isUsed1[i] = false;
            isUsed2[cur + i] = false;
            isUsed3[cur - i + n - 1] = false;
        }

    }
}
