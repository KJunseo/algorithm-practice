package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 괄호_9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < tc; i++) {
            String[] ps = br.readLine().split("");

            Stack<String> stack = new Stack<>();
            boolean isError = false;
            for (String s : ps) {
                if ("(".equals(s)) {
                    stack.add(s);
                } else {
                    if (stack.isEmpty()) {
                        isError = true;
                        sb.append("NO\n");
                        break;
                    }
                    if ("(".equals(stack.peek())) {
                        stack.pop();
                    }
                }
            }

            if (!isError) {
                if (stack.isEmpty()) {
                    sb.append("YES\n");
                } else {
                    sb.append("NO\n");
                }
            }

        }
        System.out.println(sb);
    }
}
