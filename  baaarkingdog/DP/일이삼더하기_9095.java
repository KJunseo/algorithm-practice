package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 일이삼더하기_9095 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int t, n;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());

        int[] dp = new int[12];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= 11; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        StringBuilder sb = new StringBuilder();
        for (int tc = 0; tc < t; tc++) {
            n = Integer.parseInt(br.readLine());

            sb.append(dp[n]).append("\n");
        }

        System.out.println(sb);
    }
}
