package blind2018;

public class 프렌즈4블록 {
    private char[][] map;
    private boolean[][] remove;

    public int solution(int m, int n, String[] board) {
        map = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = board[i].charAt(j);
            }
        }

        remove = new boolean[m][n];

        int count = 0;
        while (true) {
            boolean isFinish = true;

            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    char block = map[i][j];
                    if (block == '.') {
                        continue;
                    }

                    if (block == map[i][j + 1] && block == map[i + 1][j] && block == map[i + 1][j + 1]) {
                        remove[i][j] = true;
                        remove[i][j + 1] = true;
                        remove[i + 1][j] = true;
                        remove[i + 1][j + 1]= true;
                        isFinish = false;
                    }
                }
            }

            if (isFinish) {
                break;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (remove[i][j]) {
                        map[i][j] = '.';
                        remove[i][j] = false;
                        count++;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = m - 1; j > 0; j--) {
                    if (map[j][i] == '.') {
                        int k = j;
                        while (map[k][i] == '.') {
                            k--;
                            if (k < 0) {
                                k = 0;
                                break;
                            }
                        }

                        map[j][i] = map[k][i];
                        map[k][i] = '.';
                    }
                }
            }

        }


        return count;
    }
}
