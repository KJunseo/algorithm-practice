package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 트리순회_22856 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] tree;
    private static boolean[] visited;
    private static int end;
    private static int number;
    private static int answer;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        tree = new int[n + 1][3];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int node = Integer.parseInt(st.nextToken());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            tree[node][0] = left;
            tree[node][1] = right;

            if (left != -1) {
                tree[left][2] = node;
            }
            if (right != -1) {
                tree[right][2] = node;
            }
        }

        inOrder(1);

        visited = new boolean[n + 1];
        similarInOrder(1);

        System.out.println(answer);
    }

    private static void inOrder(int cur) {
        if (cur != -1) {
            inOrder(tree[cur][0]);
            end = cur;
            inOrder(tree[cur][1]);
        }
    }

    private static void similarInOrder(int cur) {
        visited[cur] = true;
        int left = tree[cur][0];
        int right = tree[cur][1];
        number++;

        if (left != -1 && !visited[left]) {
            similarInOrder(left);
        } else if (right != -1 && !visited[right]) {
            similarInOrder(right);
        } else if (cur == end) {
            answer = number - 1;
        } else if (tree[cur][2] != 0) {
            similarInOrder(tree[cur][2]);
        }
    }
}
