package 큐;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class 큐2_18258 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
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
                    bw.write(-1 + "\n");
                    continue;
                }
                bw.write(queue.poll() + "\n");
            }
            if ("size".equals(command)) {
                bw.write(queue.size() + "\n");
            }
            if ("empty".equals(command)) {
                if (queue.isEmpty()) {
                    bw.write(1 + "\n");
                    continue;
                }
                bw.write(0 + "\n");
            }
            if ("front".equals(command)) {
                if (queue.isEmpty()) {
                    bw.write(-1 + "\n");
                    continue;
                }
                bw.write(queue.peek() + "\n");
            }
            if ("back".equals(command)) {
                if (queue.isEmpty()) {
                    bw.write(-1 + "\n");
                    continue;
                }
                bw.write(back + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
