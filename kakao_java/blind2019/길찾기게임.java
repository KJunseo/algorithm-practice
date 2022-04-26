package blind2019;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 길찾기게임 {
    private static int n;

    public int[][] solution(int[][] nodeinfo) {
        n = nodeinfo.length;

        List<Node> list = new ArrayList<>();
        for (int i = 0; i < nodeinfo.length; i++) {
            list.add(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
        }

        Collections.sort(list);

        Node root = list.get(0);
        Tree tree = new Tree(root);
        for (int i = 1; i < list.size(); i++) {
            tree.insert(list.get(i));
        }

        List<Integer> preorder = new ArrayList<>();
        tree.preorder(root, preorder);

        List<Integer> postorder = new ArrayList<>();
        tree.postorder(root, postorder);

        int[][] answer = new int[2][n];
        for (int i = 0; i < n; i++) {
            answer[0][i] = preorder.get(i);
            answer[1][i] = postorder.get(i);
        }
        return answer;
    }

    static class Tree {
        Node root;

        public Tree(Node root) {
            this.root = root;
        }

        public void insert(Node node) {
            Node head = root;
            Node cur;

            while (true) {
                cur = head;

                if (head.x > node.x) {
                    head = head.left;
                    if (head == null) {
                        cur.left = node;
                        break;
                    }
                } else {
                    head = head.right;
                    if (head == null) {
                        cur.right = node;
                        break;
                    }
                }
            }
        }

        public void preorder(Node cur, List<Integer> result) {
            if (cur != null) {
                result.add(cur.id);
                preorder(cur.left, result);
                preorder(cur.right, result);
            }
        }

        public void postorder(Node cur, List<Integer> result) {
            if (cur != null) {
                postorder(cur.left, result);
                postorder(cur.right, result);
                result.add(cur.id);
            }
        }
    }

    static class Node implements Comparable<Node> {
        int id;
        int x;
        int y;
        Node left;
        Node right;

        public Node(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Node o) {
            if (this.y == o.y) {
                return Integer.compare(this.x, o.x);
            }
            return Integer.compare(o.y, this.y);
        }
    }
}
