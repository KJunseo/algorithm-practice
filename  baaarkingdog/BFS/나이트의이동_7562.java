package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 나이트의이동_7562 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int T;
    private static int L;

    private static int[] dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    private static int[] dy = {1, -1, 2, -2, 2, -2, 1, -1};

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            L = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            Pos start = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            st = new StringTokenizer(br.readLine());
            Pos end = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            System.out.println(bfs(start, end));
        }
    }

    private static int bfs(Pos start, Pos end) {
        int[][] visited = new int[L][L];
        Queue<Pos> queue = new LinkedList<>();
        queue.add(start);

        while (!queue.isEmpty()) {
            Pos cur = queue.poll();

            if (cur.same(end)) {
                break;
            }

            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= L || ny >= L) {
                    continue;
                }

                if (visited[nx][ny] > 0) {
                    continue;
                }

                visited[nx][ny] = visited[cur.x][cur.y] + 1;
                queue.add(new Pos(nx, ny));
            }
        }
        return visited[end.x][end.y];
     }
}

class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public boolean same(Pos end) {
        return this.x == end.x && this.y == end.y;
    }
}
