package blind2022;

/**
 * 참고: https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2022-blind/Q7.java
 * 제대로 이해 못해서 나중에 다시 보기
 */

public class 사라지는발판 {
    private int n;
    private int m;
    private int[][] board;
    private boolean[][] visited; // 발판 사라짐 여부 표시

    private int[] dx = {-1, 0, 1, 0};
    private int[] dy = {0, 1, 0, -1};

    public int solution(int[][] board, int[] aloc, int[] bloc) {
        this.n = board.length;
        this.m = board[0].length;
        this.board = board;
        this.visited = new boolean[n][m];
        return dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
    }

    private int dfs(int x, int y, int opx, int opy) {
        if (visited[x][y]) {
            return 0;
        }
        int result = 0; // 현재 저장된 턴

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (visited[nx][ny]) {
                continue;
            }
            if (board[nx][ny] == 0) {
                continue;
            }

            visited[x][y] = true;
            int val = dfs(opx, opy, nx, ny) + 1; // 새로 계산된 턴
            visited[x][y] = false;

            // 반환값이 짝수 = 패배 | 반환값이 홀수 = 승리
            if (result % 2 == 0 && val % 2 == 1) {
                result = val;
            } else if (result % 2 == 0 && val % 2 == 0) {
                result = Math.max(result, val); // 최대한 늦게 지기
            } else if(result % 2 == 1 && val % 2 == 1) {
                result = Math.min(result, val); // 최대한 빨리 이기기
            }
        }

        return result;
    }


}
