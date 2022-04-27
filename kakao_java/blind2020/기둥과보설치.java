package blind2020;

import java.util.ArrayList;
import java.util.List;

public class 기둥과보설치 {
    private boolean[][] pillar;
    private boolean[][] bo;
    private int n;

    public int[][] solution(int n, int[][] build_frame) {
        this.n = n;
        pillar = new boolean[n + 3][n + 3];
        bo = new boolean[n + 3][n + 3];

        for (int[] command : build_frame) {
            int x = command[0] + 1;
            int y = command[1] + 1;
            int type = command[2]; // 0: 기둥 | 1: 보
            int method = command[3];

            if (method == 0) { // 삭제
                delete(x, y, type);
            } else if (method == 1) { // 설치
                create(x, y, type);
            }
        }

        return getResult(n);
    }

    private void delete(int x, int y, int type) {
        if (type == 0) {
            pillar[x][y] = false;
        } else if (type == 1) {
            bo[x][y] = false;
        }

        if (!canDelete()) {
            if (type == 0) {
                pillar[x][y] = true;
            } else if (type == 1) {
                bo[x][y] = true;
            }
        }
    }

    private boolean canDelete() {
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                if (pillar[i][j] && !canBuildPillar(i, j)) {
                    return false;
                }
                if (bo[i][j] && !canBuildBo(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    private void create(int x, int y, int type) {
        if (type == 0) { // 기둥
            if (canBuildPillar(x, y)) {
                pillar[x][y] = true;
            }
        } else if (type == 1) { // 보
            if (canBuildBo(x, y)) {
                bo[x][y] = true;
            }
        }
    }

    private boolean canBuildPillar(int x, int y) {
        if (y == 1) {
            return true;
        } else if (bo[x][y] || bo[x - 1][y]) {
            return true;
        }
        return pillar[x][y - 1];
    }

    private boolean canBuildBo(int x, int y) {
        if (pillar[x][y - 1] || pillar[x + 1][y - 1]) {
            return true;
        }
        return bo[x + 1][y] && bo[x - 1][y];
    }
    
    private int[][] getResult(int n) {
        List<int[]> result = new ArrayList<>();
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                if (pillar[i][j]) {
                    result.add(new int[]{i - 1, j - 1, 0});
                }

                if (bo[i][j]) {
                    result.add(new int[]{i - 1, j - 1, 1});
                }
            }
        }

        int[][] answer = new int[result.size()][3];
        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < 3; j++) {
                answer[i][j] = result.get(i)[j];
            }
        }
        return answer;
    }
}
