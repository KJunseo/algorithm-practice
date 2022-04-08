package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 트리와쿼리_15681 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, root, q;
    private static List<Integer>[] tree;
    private static int[] subSize;

    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        root = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        tree = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }

        subSize = new int[n + 1];
        calculateSubSize(root, -1);

        for (int i = 0; i < q; i++) {
            int query = Integer.parseInt(br.readLine());
            sb.append(subSize[query]).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int calculateSubSize(int cur, int parent) {
        subSize[cur] = 1;

        for (int i = 0; i < tree[cur].size(); i++) {
            Integer child = tree[cur].get(i);
            if (child == parent) {
                continue;
            }
            subSize[cur] += calculateSubSize(child, cur);
        }
        return subSize[cur];
    }
}
