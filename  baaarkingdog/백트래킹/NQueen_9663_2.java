package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NQueen_9663_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int count;

    private static boolean[] sameCol = new boolean[30];
    private static boolean[] sameDiagonal1 = new boolean[30];
    private static boolean[] sameDiagonal2 = new boolean[30];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        dfs(0);

        System.out.println(count);
    }

    private static void dfs(int row) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (sameCol[col] || sameDiagonal1[row + col] || sameDiagonal2[row - col + n - 1]) {
                continue;
            }

            sameCol[col] = true;
            sameDiagonal1[row + col] = true;
            sameDiagonal2[row - col + n - 1] = true;

            dfs(row + 1);

            sameCol[col] = false;
            sameDiagonal1[row + col] = false;
            sameDiagonal2[row - col + n - 1] = false;
        }
    }
}
