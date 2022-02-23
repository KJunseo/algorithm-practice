package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 곱셈_1629 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(calculate(a, b, c));
    }

    private static long calculate(int a, int b, int c) {
        if (b == 1) {
            return a % c;
        }

        long value = calculate(a, b / 2, c);
        value = value * value % c;

        if (b % 2 == 0) {
            return value;
        }

        return value * a % c;
    }
}
