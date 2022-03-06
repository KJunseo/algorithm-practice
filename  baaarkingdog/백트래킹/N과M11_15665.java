package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class N과M11_15665 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[] array;
    private static int[] sequence;
    private static Set<String> answer = new LinkedHashSet<>();

    private static StringBuilder sb = new StringBuilder();

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

        sequence = new int[m];
        dfs(0);

        for (String s : answer) {
            sb.append(s).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dfs(int length) {
        if (length == m) {
            StringBuilder temp = new StringBuilder();
            for (int num : sequence) {
                temp.append(num).append(" ");
            }
            answer.add(temp.toString());
            return;
        }

        for (int i = 0; i < n; i++) {
            sequence[length] = array[i];
            dfs(length + 1);
        }
    }
}
