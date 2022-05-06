package intern2021;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class 표편집 {
    private int nodeCnt;
    private Node[] nodes;
    private Node head;
    private Node tail;
    private Deque<Node> garbage;

    public String solution(int n, int k, String[] commands) {
        nodes = new Node[n];
        head = new Node(-1);
        tail = new Node(-1);
        garbage = new ArrayDeque<>();

        init(n);

        Node cursor = nodes[k];

        StringBuilder answer = new StringBuilder("O".repeat(n));
        StringTokenizer st;
        for (String command : commands) {
            st = new StringTokenizer(command);
            String cmd = st.nextToken();

            if ("U".equals(cmd)) {
                int count = Integer.parseInt(st.nextToken());
                while (count-- > 0) {
                    cursor = cursor.prev;
                }
            } else if ("D".equals(cmd)) {
                int count = Integer.parseInt(st.nextToken());
                while (count-- > 0) {
                    cursor = cursor.next;
                }
            } else if ("C".equals(cmd)) {
                garbage.addLast(cursor);
                Node prev = cursor.prev;
                Node next = cursor.next;
                prev.next = next;
                next.prev = prev;

                answer.setCharAt(cursor.id, 'X');
                if (next.id == -1) {
                    cursor = prev;
                } else {
                    cursor = next;
                }
            } else {
                Node node = garbage.pollLast();
                Node prev = node.prev;
                Node next = node.next;
                next.prev = node;
                prev.next = node;
                answer.setCharAt(node.id, 'O');
            }
        }

        return answer.toString();
    }

    private void init(int n) {
        head.next = tail;
        tail.prev = head;

        for (int i = 0; i < n; i++) {
            addNode(i);
        }
    }

    private void addNode(int id) {
        Node node = getNode(id);
        Node prev = tail.prev;

        prev.next = node;
        node.prev = prev;

        tail.prev = node;
        node.next = tail;
    }

    private Node getNode(int id) {
        nodes[nodeCnt] = new Node(id);
        return nodes[nodeCnt++];
    }

    static class Node {
        int id;
        Node prev;
        Node next;

        public Node(int id) {
            this.id = id;
            this.prev = null;
            this.next = null;
        }
    }
}
