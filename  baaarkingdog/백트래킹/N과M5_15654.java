package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class N과M5_15654 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static StringBuilder sb = new StringBuilder();
    private static int[] array;
    private static int[] answer;
    private static boolean[] use;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array);

        use = new boolean[n];
        answer = new int[m];
        makeSequence(0);

        System.out.println(sb.toString());
    }

    private static void makeSequence(int length) {
        if (length == m) {
            for (int num : answer) {
                sb.append(num).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (use[i]) {
                continue;
            }
            use[i] = true;
            answer[length] = array[i];
            makeSequence(length + 1);
            use[i] = false;
        }
    }
}
