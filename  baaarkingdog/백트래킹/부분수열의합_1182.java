package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 부분수열의합_1182 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, s;
    private static int[] array;
    private static boolean[] visited;
    private static int count = 0;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        array = new int[n];
        visited = new boolean[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0, 0);
//        dfs(0,0);
        System.out.println(count);
    }

    private static void dfs(int cur, int sum) {
        if (cur == n) {
            return;
        }
        if (sum + array[cur] == s) {
            count++;
        }

        dfs(cur + 1, sum);
        dfs(cur + 1, sum + array[cur]);
    }

    private static void dfs(int cnt, int sum, int cur) {
        if (cnt > 0 && sum == s) {
            count++;
        }

        for (int i = cur; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            sum += array[i];

            dfs(cnt + 1, sum, i);

            visited[i] = false;
            sum -= array[i];
        }
    }
}
