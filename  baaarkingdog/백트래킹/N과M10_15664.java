package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class N과M10_15664 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[] array;
    private static boolean[] select;
    private static int[] answer;
    private static Set<String> result = new LinkedHashSet<>();

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

        answer = new int[m];
        select = new boolean[n];
        dfs(0, 0);

        for (String s : result) {
            sb.append(s).append("\n");
        }

        System.out.println(sb.toString());
    }

    private static void dfs(int start, int length) {
        if (length == m) {
            StringBuilder temp = new StringBuilder();
            for (int num : answer) {
                temp.append(num).append(" ");
            }
            result.add(temp.toString());
            return;
        }

        for (int i = start; i < n; i++) {
            if (select[i]) {
                continue;
            }
            select[i] = true;
            answer[length] = array[i];
            dfs(i, length + 1);
            select[i] = false;
        }
    }
}
