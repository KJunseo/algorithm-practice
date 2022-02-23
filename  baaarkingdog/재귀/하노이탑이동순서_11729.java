package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 하노이탑이동순서_11729 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        sb.append((1 << n) - 1).append("\n");
        hanoi(1, 3, n);
        System.out.println(sb.toString());
    }

    private static void hanoi(int start, int end, int n) {
        if (n == 1) {
            sb.append(start).append(" ").append(end).append("\n");
            return;
        }

        int mid = 6 - start - end;
        hanoi(start, mid, n - 1);
        sb.append(start).append(" ").append(end).append("\n");
        hanoi(mid, end, n - 1);
    }
}
