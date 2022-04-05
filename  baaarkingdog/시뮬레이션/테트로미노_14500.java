package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 테트로미노_14500 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int answer;
    private static int[][] map = new int[501][501];
    private static int[][][] tetrominos = {
            {{1, 1, 1, 1}},
            {{1}, {1}, {1}, {1}},
            {{1, 1}, {1, 1}},
            {{1, 0}, {1, 0}, {1, 1}},
            {{0, 1}, {0, 1}, {1, 1}},
            {{0, 0, 1}, {1, 1, 1}},
            {{1, 0, 0}, {1, 1, 1}},
            {{1, 1, 1}, {1, 0, 0}},
            {{1, 1, 1}, {0, 0, 1}},
            {{1, 1}, {0, 1}, {0, 1}},
            {{1, 1}, {1, 0}, {1, 0}},
            {{1, 0}, {1, 1}, {0, 1}},
            {{0, 1}, {1, 1}, {1, 0}},
            {{0, 1, 1}, {1, 1, 0}},
            {{1, 1, 0}, {0, 1, 1}},
            {{1, 1, 1}, {0, 1, 0}},
            {{0, 1, 0}, {1, 1, 1}},
            {{1, 0}, {1, 1}, {1, 0}},
            {{0, 1}, {1, 1}, {0, 1}}
    };

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int t = 0; t < tetrominos.length; t++) {
            int[][] tetromino = tetrominos[t];

            for (int i = 0; i <= n - tetromino.length; i++) {
                for (int j = 0; j <= m - tetromino[0].length; j++) {
                    int score = 0;
                    for (int ti = 0; ti < tetromino.length; ti++) {
                        for (int tj = 0; tj < tetromino[ti].length; tj++) {
                            if (tetromino[ti][tj] == 1) {
                                score += map[i + ti][j + tj];
                            }
                        }
                    }
                    answer = Math.max(answer, score);
                }
            }
        }

        System.out.println(answer);
    }
}
