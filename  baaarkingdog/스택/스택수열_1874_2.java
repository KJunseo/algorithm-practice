package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 스택수열_1874_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        for (int i = 0; i < n; i++) {
            int cur = Integer.parseInt(br.readLine());

            if (stack.isEmpty() || stack.peek() != cur) {
                for (int j = num; j < cur; j++) {
                    stack.add(j + 1);
                    sb.append("+\n");
                    num++;
                }
            }
            if (stack.peek() != cur) {
                System.out.println("NO");
                return;
            }

            stack.pop();
            sb.append("-\n");
        }

        System.out.println(sb);
    }
}
