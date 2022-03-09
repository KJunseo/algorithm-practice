package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 스티커붙이기_18808 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m, k;
    private static int[][] paper;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        paper = new int[n][m];

        for (int gp = 0; gp < k; gp++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            int[][] graphPaper = new int[r][c];
            for (int i = 0; i < r; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < c; j++) {
                    graphPaper[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int dir = 0; dir < 4; dir++) {
                if (attach(graphPaper)) {
                    break;
                }
                graphPaper = rotate(graphPaper);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (paper[i][j] == 1) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }

    private static boolean attach(int[][] graphPaper) {
        for (int i = 0; i <= n - graphPaper.length; i++) {
            for (int j = 0; j <= m - graphPaper[0].length; j++) {
                if (canAttach(graphPaper, i, j)) {
                    attach(graphPaper, i, j);
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean canAttach(int[][] graphPaper, int x, int y) {
        for (int i = 0; i < graphPaper.length; i++) {
            for (int j = 0; j < graphPaper[i].length; j++) {
                if (paper[x + i][y + j] == 1 && graphPaper[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void attach(int[][] graphPaper, int x, int y) {
        for (int i = 0; i < graphPaper.length; i++) {
            for (int j = 0; j < graphPaper[i].length; j++) {
                if (graphPaper[i][j] == 1) {
                    paper[x + i][y + j] = 1;
                }
            }
        }
    }

    private static int[][] rotate(int[][] graphPaper) {
        int n = graphPaper.length;
        int m = graphPaper[0].length;
        int[][] temp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = graphPaper[n - 1 - j][i];
            }
        }

        return temp;
    }
}
