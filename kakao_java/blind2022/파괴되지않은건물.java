package blind2022;

public class 파괴되지않은건물 {

    public int solution(int[][] board, int[][] skill) {
        int n = board.length;
        int m = board[0].length;
        int[][] psum = new int[1003][1003];
        for (int i = 0; i < skill.length; i++) {
            int type = skill[i][0];
            int r1 = skill[i][1];
            int c1 = skill[i][2];
            int r2 = skill[i][3];
            int c2 = skill[i][4];
            int degree = skill[i][5];

            if (type == 1) {
                degree *= -1;
            }

            // 각 꼭지점에 표시해주고 오른쪽 + 아래쪽으로 누적합 돌리면 총 누적해야하는 양이 나옴
            psum[r1][c1] += degree;
            psum[r1][c2 + 1] -= degree;
            psum[r2 + 1][c1] -= degree;
            psum[r2 + 1][c2 + 1] += degree;
        }

        // 오른쪽으로 누적합
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                psum[i][j] += psum[i - 1][j];
            }
        }

        // 아래쪽으로 누적합
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                psum[i][j] += psum[i][j - 1];
            }
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] + psum[i][j] > 0) {
                    answer++;
                }
            }
        }

        return answer;
    }
}
