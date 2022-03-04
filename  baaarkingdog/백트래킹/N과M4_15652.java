package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class N과M4_15652 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static StringBuilder sb = new StringBuilder();
    private static int[] answer;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        answer = new int[m];
        makeSequence(1, 0);

        System.out.println(sb.toString());
    }

    private static void makeSequence(int start, int length) {
        if (length == m) {
            for (int num : answer) {
                sb.append(num).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = start; i <= n; i++) {
            answer[length] = i;
            makeSequence(i, length + 1);
        }
    }
}
