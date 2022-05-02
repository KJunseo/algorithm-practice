package blind2022;

import java.util.Objects;

public class 양과늑대 {
    private Node[] tree;
    private boolean[] visited = new boolean[1 << 17];

    private int n;
    private int answer = 1;

    public int solution(int[] info, int[][] edges) {
        n = info.length;
        tree = new Node[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new Node(i, info[i]);
        }

        for (int[] edge : edges) {
            int parent = edge[0];
            int child = edge[1];
            tree[parent].addChild(tree[child]);
        }

        dfs(1);

        return answer;
    }

    private void dfs(int cur) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;

        int wolf = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if ((cur & (1 << i)) != 0) {
                num++;
                wolf += tree[i].type;
            }
        }

        if (wolf * 2 >= num) {
            return;
        }

        answer = Math.max(answer, num - wolf);

        for (int i = 0; i < n; i++) {
            if ((cur & (1 << i)) == 0) {
                continue;
            }
            Node node = tree[i];

            if (node.existLeft()) {
                dfs(cur | (1 << node.left.id));
            }
            if (node.existRight()) {
                dfs(cur | (1 << node.right.id));
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

        public void addChild(Node child) {
            if (Objects.isNull(left)) {
                left = child;
            } else {
                right = child;
            }
        }

        public boolean existLeft() {
            return !Objects.isNull(left);
        }

        public boolean existRight() {
            return !Objects.isNull(right);
        }
    }
}
