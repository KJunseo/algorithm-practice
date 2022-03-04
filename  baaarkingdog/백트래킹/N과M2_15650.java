package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class N과M2_15650 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static StringBuilder sb = new StringBuilder();
    private static boolean[] use;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        use = new boolean[n + 1];

        makeSequence(1, 0);

        System.out.println(sb.toString());
    }

    private static void makeSequence(int start, int length) {
        if (length == m) {
            for (int i = 1; i <= n; i++) {
                if (use[i]) {
                    sb.append(i).append(" ");
                }
            }
            sb.append("\n");
            return;
        }

        for (int i = start; i <= n; i++) {
            if (use[i]) {
                continue;
            }

            use[i] = true;
            makeSequence(i + 1, length + 1);
            use[i] = false;
        }
    }
}
