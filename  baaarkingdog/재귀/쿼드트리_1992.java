package 재귀;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 쿼드트리_1992 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int[][] array;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        array = new int[n][n];
        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < n; j++) {
                array[i][j] = input.charAt(j) - '0';
            }
        }

        compress(0, 0, n);

        System.out.println(sb.toString());
    }

    private static void compress(int x, int y, int n) {
        if (n == 1) {
            sb.append(array[x][y]);
            return;
        }

        if (canCompress(x, y, n)) {
            sb.append(array[x][y]);
            return;
        }

        int l = n / 2;
        sb.append("(");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                compress(x + i * l, y + j * l , l);
            }
        }
        sb.append(")");
    }

    private static boolean canCompress(int x, int y, int n) {
        int firstColor = array[x][y];
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (firstColor != array[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
