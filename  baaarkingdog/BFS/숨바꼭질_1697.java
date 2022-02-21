package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 숨바꼭질_1697 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int MAX = 100000;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        System.out.println(bfs(N, K));
    }

    private static int bfs(int start, int goal) {
        int[] position = new int[MAX + 1];
        Arrays.fill(position, MAX + 1);
        Queue<Integer> queue = new LinkedList<>();
        position[start] = 0;
        queue.add(start);

        while (!queue.isEmpty()) {
            Integer cur = queue.poll();

            if (cur == goal) {
                return position[cur];
            }

            if (cur + 1 <= MAX) {
                if (position[cur] + 1 < position[cur + 1]) {
                    position[cur + 1] = position[cur] + 1;
                    queue.add(cur + 1);
                }
            }
            if (cur - 1 >= 0) {
                if (position[cur] + 1 < position[cur - 1]) {
                    position[cur - 1] = position[cur] + 1;
                    queue.add(cur - 1);
                }
            }
            if (cur * 2 <= MAX) {
                if (position[cur] + 1 < position[cur * 2]) {
                    position[cur * 2] = position[cur] + 1;
                    queue.add(cur * 2);
                }
            }
        }
        return -1;
    }
}
