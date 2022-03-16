package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 톱니바퀴_14891 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int[][] gears = new int[4][8];
    private static boolean[] visited = new boolean[4];
    private static int k;
    private static int answer;

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 4; i++) {
            String s = br.readLine();
            for (int j = 0; j < 8; j++) {
                gears[i][j] = s.charAt(j) - '0';
            }
        }

        StringTokenizer st;
        k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());

            int num = Integer.parseInt(st.nextToken());
            int dir = Integer.parseInt(st.nextToken());

            for (int j = 0; j < 4; j++) {
                visited[j] = false;
            }

            turn(num - 1, dir);
        }

        for (int i = 0; i < 4; i++) {
            if (gears[i][0] == 1) {
                answer += (1 << i);
            }
        }

        System.out.println(answer);
    }

    private static void turn(int index, int dir) {
        visited[index] = true;
        int[] curGear = gears[index];
        int left = curGear[6];
        int right = curGear[2];

        int[] temp = new int[8];
        int curIndex;
        if (dir == 1) {
            curIndex = 7;
        } else {
            curIndex = 1;
        }

        for (int i = 0; i < 8; i++) {
            if (curIndex == 8) {
                curIndex = 0;
            }
            temp[i] =  curGear[curIndex++];
        }

        for (int i = 0; i < 8; i++) {
            gears[index][i] = temp[i];
        }

        if (index - 1 >= 0 && !visited[index - 1]) {
            int[] leftGear = gears[index - 1];

            if (leftGear[2] != left) {
                turn(index - 1, dir * -1);
            }
        }

        if (index + 1 < 4 && !visited[index + 1]) {
            int[] rightGear = gears[index + 1];

            if (rightGear[6] != right) {
                turn(index + 1, dir * -1);
            }
        }
    }
}
