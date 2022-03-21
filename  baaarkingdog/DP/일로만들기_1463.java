package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 일로만들기_1463 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            int value = dp[i - 1];
            if (i % 2 == 0) {
                value = Math.min(value, dp[i / 2]);
            }
            if (i % 3 == 0) {
                value = Math.min(value, dp[i / 3]);
            }

            dp[i] = value + 1;
        }

        System.out.println(dp[n]);
    }
}
