package blind2022;

public class 양과늑대2 {
    private Node[] tree;
    private boolean[] check;

    private int n;
    private int answer = 1;

    public int solution(int[] info, int[][] edges) {
        n = info.length;
        tree = new Node[n];

        for (int i = 0; i < n; i++) {
            tree[i] = new Node(i, info[i]);
        }

        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];

            tree[from].addChild(tree[to]);
        }

        check = new boolean[1 << 17];
        dfs(1);

        return answer;
    }

    private void dfs(int state) {
        if (check[state]) {
            return;
        }
        check[state] = true;

        int total = 0;
        int wolf = 0;
        for (int i = 0; i < n; i++) {
            if ((state & (1 << i)) != 0) {
                total++;
                wolf += tree[i].type;
            }
        }

        if (2 * wolf >= total) {
            return;
        }

        answer = Math.max(answer, total - wolf);

        for (int i = 0; i < n; i++) {
            if ((state & (1 << i)) != 0) {
                Node node = tree[i];

                if (node.left != null) {
                    dfs(state | (1 << node.left.id));
                }
                if (node.right != null) {
                    dfs(state | (1 << node.right.id));
                }
            }
        }
    }

    static class Node {
        int id;
        int type;
        Node left;
        Node right;

        public Node(int id, int type) {
            this.id = id;
            this.type = type;
            this.left = null;
            this.right = null;
        }

        public void addChild(Node node) {
            if (left == null) {
                left = node;
            } else {
                right = node;
            }
        }
    }
}
