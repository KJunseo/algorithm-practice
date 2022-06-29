package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 성냥개비_3687 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        long[] min = new long[101];
        min[2] = 1;
        min[3] = 7;
        min[4] = 4;
        min[5] = 2;
        min[6] = 6;
        min[7] = 8;

        String[] add = {"1", "7", "4", "2", "0", "8"};
        for (int i = 8; i <= 100; i++) {
            for (int j = 2; j <= 7; j++) {
                if (i - j < 2 || j - 2 < 2) {
                    continue;
                }
                String value = min[i - j] + add[j - 2];
                if (min[i] == 0) {
                    min[i] = Long.parseLong(value);
                } else {
                    min[i] = Math.min(min[i], Long.parseLong(value));
                }
            }
        }

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int tc = 1; tc <= t; tc++) {
            int num = Integer.parseInt(br.readLine());
            sb.append(min[num]);
            if (num % 2 == 1) {
                sb.append(" 7").append("1".repeat((num - 3) / 2));
            } else {
                sb.append(" ").append("1".repeat(num / 2));
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
