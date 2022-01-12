package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 스택_10828 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Stack<String> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            String command = br.readLine();

            if (command.contains("push")) {
                String data = command.split(" ")[1];
                stack.push(data);
            }
            if ("pop".equals(command)) {
                if (stack.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                String data = stack.pop();
                System.out.println(data);
            }
            if ("size".equals(command)) {
                System.out.println(stack.size());
            }
            if ("empty".equals(command)) {
                if (stack.isEmpty()) {
                    System.out.println(1);
                    continue;
                }
                System.out.println(0);
            }
            if ("top".equals(command)) {
                if (stack.isEmpty()) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(stack.peek());
            }
        }
    }
}
