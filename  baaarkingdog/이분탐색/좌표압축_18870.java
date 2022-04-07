package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 좌표압축_18870 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static List<Node> list = new ArrayList<>();
    private static Map<Integer, Integer> map = new HashMap<>();
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            list.add(new Node(Integer.parseInt(st.nextToken()), i));
        }

        list.sort(Comparator.comparingInt(o -> o.position));

        int count = 0;
        map.put(list.get(0).id, count);
        for (int i = 1; i < list.size(); i++) {
            Node prev = list.get(i - 1);
            Node node = list.get(i);

            if (prev.position != node.position) {
                count++;
            }

            map.put(node.id, count);
        }

        for (int i = 0; i < n; i++) {
            sb.append(map.get(i)).append(" ");
        }
        System.out.println(sb.toString());
    }

    static class Node {
        int position;
        int id;

        public Node(int position, int id) {
            this.position = position;
            this.id = id;
        }
    }
}
