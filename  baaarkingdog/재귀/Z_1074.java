package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Z_1074 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(calculate(n, r, c));
    }

    private static int calculate(int n, int r, int c) {
        if (n == 0) {
            return 0;
        }
        int half = 1 << (n - 1);

        if (r < half && c < half) {
            return calculate(n - 1, r, c);
        }
        if (r < half && c >= half) {
            return half * half + calculate(n - 1, r, c - half);
        }
        if (r >= half && c < half) {
            return 2 * half * half + calculate(n - 1, r - half, c);
        }
        return 3 * half * half + calculate(n - 1, r - half, c - half);
    }
}
