package 덱;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class AC_5430_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < tc; i++) {
            String[] commands = br.readLine().split("");
            br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine(), "[],");

            Deque<Integer> deque = new ArrayDeque<>();
            while (st.hasMoreTokens()) {
                deque.addLast(Integer.parseInt(st.nextToken()));
            }

            boolean isError = false;
            boolean isLeft = true;
            for (String command : commands) {
                if ("D".equals(command)) {
                    if (deque.isEmpty()) {
                        isError = true;
                        sb.append("error\n");
                        break;
                    }
                    if (isLeft) {
                        deque.pollFirst();
                    } else {
                        deque.pollLast();
                    }
                }
                if ("R".equals(command)) {
                    isLeft = !isLeft;
                }
            }

            if (isError) {
                continue;
            }

            sb.append("[");
            if (!deque.isEmpty()) {
                if (isLeft) {
                    sb.append(deque.pollFirst());
                    while (!deque.isEmpty()) {
                        sb.append(",").append(deque.pollFirst());
                    }
                } else {
                    sb.append(deque.pollLast());
                    while (!deque.isEmpty()) {
                        sb.append(",").append(deque.pollLast());
                    }
                }
            }
            sb.append("]\n");
        }
        System.out.println(sb);
    }
}
