package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RGB거리_1149 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        dp = new int[n][3];

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int rCost = Integer.parseInt(st.nextToken());
            int gCost = Integer.parseInt(st.nextToken());
            int bCost = Integer.parseInt(st.nextToken());

            if (i == 0) {
                dp[i][0] = rCost;
                dp[i][1] = gCost;
                dp[i][2] = bCost;
            } else {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + rCost;
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + gCost;
                dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + bCost;
            }
        }

        System.out.println(Math.min(Math.min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]));
    }
}
