package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 계단오르기_2579 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] stairs;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        stairs = new int[n];
        for (int i = 0; i < n; i++) {
            stairs[i] = Integer.parseInt(br.readLine());
        }

        dp = new int[n + 1][2];
        dp[1][0] = stairs[0];
        dp[1][1] = stairs[0];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = Math.max(dp[i - 2][0], dp[i - 2][1]) + stairs[i - 1];
            dp[i][1] = dp[i - 1][0] + stairs[i - 1];
        }

        System.out.println(Math.max(dp[n][0], dp[n][1]));
    }
}
