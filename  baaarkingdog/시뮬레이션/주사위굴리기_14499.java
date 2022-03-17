package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 주사위굴리기_14499 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m, x, y, k;
    private static int[][] map;
    private static Dice dice;

    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dice = new Dice(x, y);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            int command = Integer.parseInt(st.nextToken());

            if (command == 1) {
                dice.moveRight();
            } else if (command == 2) {
                dice.moveLeft();
            } else if (command == 3) {
                dice.moveUp();
            } else if (command == 4) {
                dice.moveDown();
            }
        }

        System.out.println(sb.toString());
    }

    static class Dice {
        private int x;
        private int y;
        private int top;
        private int bottom;
        private int back;
        private int front;
        private int left;
        private int right;

        public Dice(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public void moveRight() {
            int nx = x + dx[0];
            int ny = y + dy[0];

            if (canMove(nx, ny)) {
                x = nx;
                y = ny;

                int temp1 = top;
                int temp2 = bottom;
                this.top = this.left;
                this.bottom = this.right;
                this.left = temp2;
                this.right = temp1;

                copyBottom();
            }
        }

        public void moveLeft() {
            int nx = x + dx[2];
            int ny = y + dy[2];

            if (canMove(nx, ny)) {
                x = nx;
                y = ny;

                int temp1 = top;
                int temp2 = bottom;
                this.top = this.right;
                this.bottom = this.left;
                this.left = temp1;
                this.right = temp2;

                copyBottom();
            }
        }

        public void moveUp() {
            int nx = x + dx[3];
            int ny = y + dy[3];

            if (canMove(nx, ny)) {
                x = nx;
                y = ny;

                int temp1 = top;
                int temp2 = bottom;
                this.top = this.front;
                this.bottom = this.back;
                this.back = temp1;
                this.front = temp2;

                copyBottom();
            }
        }

        public void moveDown() {
            int nx = x + dx[1];
            int ny = y + dy[1];
            
            if (canMove(nx, ny)) {
                x = nx;
                y = ny;

                int temp1 = top;
                int temp2 = bottom;
                this.top = this.back;
                this.bottom = this.front;
                this.back = temp2;
                this.front = temp1;

                copyBottom();
            }
        }

        private boolean canMove(int nx, int ny) {
            return nx >= 0 && ny >= 0 && nx < n && ny < m;
        }

        private void copyBottom() {
            if (map[x][y] == 0) {
                map[x][y] = this.bottom;
            } else {
                this.bottom = map[x][y];
                map[x][y] = 0;
            }

            sb.append(top).append("\n");
        }
    }

}
