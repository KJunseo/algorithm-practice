package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 결혼식_5567 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static List<Integer>[] relation;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        relation = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            relation[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            relation[u].add(v);
            relation[v].add(u);
        }

        List<Integer> friends = relation[1];
        Set<Integer> set = new HashSet<>(friends);

        for (Integer friend : friends) {
            set.addAll(relation[friend]);
        }

        set.remove(1);

        System.out.println(set.size());

    }
}
