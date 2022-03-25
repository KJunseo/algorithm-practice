package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 계단오르기_2579_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] stairs = new int[300];
    private static int[] dp = new int[300];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            stairs[i] = Integer.parseInt(br.readLine());
        }

        dp[0] = stairs[0];
        dp[1] = stairs[0] + stairs[1];
        dp[2] = Math.max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

        for (int i = 3; i < n; i++) {
            dp[i] = Math.max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
        }

        System.out.println(dp[n - 1]);
    }
}
