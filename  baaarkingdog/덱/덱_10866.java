package 덱;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class 덱_10866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Deque<Integer> deque = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if ("push_front".equals(command)) {
                int data = Integer.parseInt(st.nextToken());
                deque.addFirst(data);
            }
            if ("push_back".equals(command)) {
                int data = Integer.parseInt(st.nextToken());
                deque.addLast(data);
            }
            if ("pop_front".equals(command)) {
                if (deque.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(deque.pollFirst());
            }
            if ("pop_back".equals(command)) {
                if (deque.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(deque.pollLast());
            }
            if ("size".equals(command)) {
                System.out.println(deque.size());
            }
            if ("empty".equals(command)) {
                if (deque.isEmpty()) {
                    System.out.println(1);
                    continue;
                }
                System.out.println(0);
            }
            if ("front".equals(command)) {
                if (deque.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(deque.peekFirst());
            }
            if ("back".equals(command)) {
                if (deque.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(deque.peekLast());
            }
        }
    }
}
