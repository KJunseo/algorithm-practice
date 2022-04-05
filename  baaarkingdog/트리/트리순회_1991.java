package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 트리순회_1991 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] tree = new int[27][2];
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            char node = st.nextToken().charAt(0);

            for (int j = 0; j < 2; j++) {
                char child = st.nextToken().charAt(0);
                if (child != '.') {
                    tree[node - 'A'][j] = child - 'A';
                } else {
                    tree[node - 'A'][j] = -1;
                }
            }
        }

        preOrder(0);
        sb.append("\n");

        inOrder(0);
        sb.append("\n");

        postOrder(0);

        System.out.println(sb.toString());
    }

    private static void preOrder(int node) {
        if (node != -1) {
            sb.append((char)(node + 'A'));
            preOrder(tree[node][0]);
            preOrder(tree[node][1]);
        }
    }

    private static void inOrder(int node) {
        if (node != -1) {
            inOrder(tree[node][0]);
            sb.append((char)(node + 'A'));
            inOrder(tree[node][1]);
        }
    }

    private static void postOrder(int node) {
        if (node != -1) {
            postOrder(tree[node][0]);
            postOrder(tree[node][1]);
            sb.append((char)(node + 'A'));
        }
    }
}
