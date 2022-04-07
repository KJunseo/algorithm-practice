package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 일로만들기2_12852 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] dp = new int[1000001];
    private static int[][] cache = new int[1000001][1];

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        dp[1] = 0;
        cache[1][0] = 1;

        dp[2] = 1;
        cache[2][0] = 1;

        dp[3] = 1;
        cache[3][0] = 1;

        for (int i = 3; i <= n; i++) {
            int value = i - 1;
            dp[i] = dp[i - 1] + 1;
            if (i % 3 == 0) {
                if (dp[i] > dp[i / 3] + 1) {
                    dp[i] = dp[i / 3] + 1;
                    value = i / 3;
                }
            }
            if (i % 2 == 0) {
                if (dp[i] > dp[i / 2] + 1) {
                    dp[i] = dp[i / 2] + 1;
                    value = i / 2;
                }
            }
            cache[i][0] = value;
        }

        sb.append(dp[n]).append("\n");
        recursive(n);

        System.out.println(sb.toString());
    }

    private static void recursive(int n) {
        if (n == 1) {
            sb.append(1);
            return;
        }

        sb.append(n).append(" ");
        recursive(cache[n][0]);
    }
}
