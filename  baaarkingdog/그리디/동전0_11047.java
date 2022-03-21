package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 동전0_11047 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, k;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] coin = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            coin[i] = Integer.parseInt(br.readLine());
        }

        int coinIndex = 0;
        int count = 0;
        while (k > 0) {
            if (k >= coin[coinIndex]) {
                count += k / coin[coinIndex];
                k %= coin[coinIndex];
            }
            coinIndex++;
        }

        System.out.println(count);
    }
}
