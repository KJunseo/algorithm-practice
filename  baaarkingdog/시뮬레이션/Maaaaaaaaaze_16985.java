package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Maaaaaaaaaze_16985 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int[][][] map = new int[5][5][5]; // i = 판(5x5), j = i판의 row, k = i판의 col
    private static int answer = -1;

    private static int[] di = {0, 1, 0, -1, 0, 0};
    private static int[] dj = {1, 0, -1, 0, 0, 0};
    private static int[] dk = {0, 0, 0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 5; k++) {
                    map[i][j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }

        int[][][] newMap = new int[5][5][5];
        boolean[] visited = new boolean[5];
        dfs(0, newMap, visited);

        System.out.println(answer);
    }

    private static void dfs(int index, int[][][] newMap, boolean[] visited) {
        if (index == 5) {
            dfsRotate(0, newMap);
            return;
        }

        for (int i = 0; i < 5; i++) {
            if (visited[i]) {
                continue;
            }

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    newMap[index][j][k] = map[i][j][k];
                }
            }

            visited[i] = true;
            dfs(index + 1, newMap, visited);
            visited[i] = false;
        }
    }

    private static void dfsRotate(int index, int[][][] newMap) {
        if (index == 5) {
            if (newMap[0][0][0] == 1 && newMap[4][4][4] == 1) {
                bfs(newMap);
            }
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            rotate(newMap[index]);
            dfsRotate(index + 1, newMap);
        }
    }

    private static void rotate(int[][] piece) {
        int[][] temp = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                temp[i][j] = piece[5 - 1 - j][i];
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                piece[i][j] = temp[i][j];
            }
        }
    }


    private static void bfs(int[][][] newMap) {
        int[][][] visited = new int[5][5][5];
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0, 0, 0));
        visited[0][0][0] = 0;

        while (!queue.isEmpty()) {
            Node cur = queue.poll();

            for (int dir = 0; dir < 6; dir++) {
                int ni = cur.i + di[dir];
                int nj = cur.j + dj[dir];
                int nk = cur.k + dk[dir];

                if (ni < 0 || nj < 0 || nk < 0 || ni >= 5 || nj >= 5 || nk >= 5) {
                    continue;
                }

                if (newMap[ni][nj][nk] == 0) {
                    continue;
                }

                if (visited[ni][nj][nk] > 0) {
                    continue;
                }

                queue.add(new Node(ni, nj, nk));
                visited[ni][nj][nk] = visited[cur.i][cur.j][cur.k] + 1;
            }
        }

        if (visited[4][4][4] > 0) {
            if (answer == -1) {
                answer = visited[4][4][4];
            } else {
                answer = Math.min(answer, visited[4][4][4]);
            }
        }
    }

    static class Node {
        int i;
        int j;
        int k;

        public Node(int i, int j, int k) {
            this.i = i;
            this.j = j;
            this.k = k;
        }
    }
}
