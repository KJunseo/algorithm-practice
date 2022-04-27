package blind2020;

public class 자물쇠와열쇠 {
    private static int n;
    private static int keySize;

    public boolean solution(int[][] key, int[][] lock) {
        keySize = key.length - 1;
        n = lock.length + 2 * keySize;

        int[][] board = new int[n][n];
        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock.length; j++) {
                board[i + keySize][j + keySize] = lock[i][j];
            }
        }

        for (int l = 0; l < 4; l++) {
            key = rotate(key);

            for (int i = 0; i < n - keySize; i++) {
                for (int j = 0; j < n - keySize; j++) {
                    if (canUnlock(board, key, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private boolean canUnlock(int[][] board, int[][] key, int r, int c) {
        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < key.length; i++) {
            for (int j = 0; j < key[i].length; j++) {
                temp[r + i][c + j] += key[i][j];
            }
        }

        for (int i = keySize; i < n - keySize; i++) {
            for (int j = keySize; j < n - keySize; j++) {
                if (temp[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    private static int[][] rotate(int[][] key) {
        int[][] rotated = new int[key.length][key.length];

        for (int i = 0; i < key.length; i++) {
            for (int j = 0; j < key.length; j++) {
                rotated[i][j] = key[key.length - 1 - j][i];
            }
        }

        return rotated;
    }
}
