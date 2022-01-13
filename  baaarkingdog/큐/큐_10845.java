package 큐;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 큐_10845 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int back = -1;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String command = br.readLine();

            if (command.contains("push")) {
                back = Integer.parseInt(command.split(" ")[1]);
                queue.add(back);
            }
            if ("pop".equals(command)) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(queue.poll());
            }
            if ("size".equals(command)) {
                System.out.println(queue.size());
            }
            if ("empty".equals(command)) {
                if (queue.isEmpty()) {
                    System.out.println(1);
                    continue;
                }
                System.out.println(0);
            }
            if ("front".equals(command)) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(queue.peek());
            }
            if ("back".equals(command)) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(back);
            }
        }
    }
}
