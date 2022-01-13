package 덱;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/**
 * R 명령어인 경우 실제로 배열을 뒤집는 것이 아니라 바라보는 방향만 변경해주면 된다는 점이 핵심
 */

public class AC_5430 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            String[] commands = br.readLine().split("");
            int n = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine(), "[],");

            Deque<Integer> deque = new ArrayDeque<>();
            for (int j = 0; j < n; j++) {
                deque.add(Integer.parseInt(st.nextToken()));
            }

            boolean isLeft = true;
            boolean isError = false;
            for (String command : commands) {
                if ("R".equals(command)) {
                    isLeft = !isLeft;
                }
                if ("D".equals(command)) {
                    if (deque.isEmpty()) {
                        isError = true;
                        bw.write("error\n");
                        break;
                    }
                    if (isLeft) {
                        deque.pollFirst();
                    } else {
                        deque.pollLast();
                    }
                }
            }

            if (!isError) {
                bw.write("[");
                while (!deque.isEmpty()) {
                    if (isLeft) {
                        bw.write(deque.pollFirst() + "");
                    } else {
                        bw.write(deque.pollLast() + "");
                    }
                    if (!deque.isEmpty()) {
                        bw.write(",");
                    }
                }
                bw.write("]\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
