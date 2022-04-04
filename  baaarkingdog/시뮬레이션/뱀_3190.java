package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;

public class 뱀_3190 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, k, l;
    private static int[][] map;
    private static Map<Integer, String> command;

    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        map = new int[n][n];
        StringTokenizer st;
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            map[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = 2;
        }

        command = new HashMap<>();
        l = Integer.parseInt(br.readLine());
        for (int i = 0; i < l; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            String dir = st.nextToken();
            command.put(t, dir);
        }

        LinkedList<Position> list = new LinkedList<>();
        list.add(new Position(0, 0));
        int dir = 0;
        int t = 1;
        while (true) {
            Position head = list.getLast();
            int nx = head.x + dx[dir];
            int ny = head.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                break;
            }

            if (map[nx][ny] == 1) {
                break;
            }

            if (map[nx][ny] != 2) {
                Position tail = list.removeFirst();
                map[tail.x][tail.y] = 0;
            }
            map[nx][ny] = 1;
            list.add(new Position(nx, ny));

            if (command.containsKey(t)) {
                String d = command.get(t);
                if ("D".equals(d)) {
                    dir = (dir + 1) % 4;
                } else {
                    dir = (dir + 3) % 4;
                }
            }
            t++;
        }

        System.out.println(t);
    }

    static class Position {
        int x;
        int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
