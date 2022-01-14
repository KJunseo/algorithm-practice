package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 균형잡힌세상_4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String sentence;
        while (!(sentence = br.readLine()).equals(".")) {
            boolean isRight = true;
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < sentence.length(); i++) {
                char c = sentence.charAt(i);

                if (c == '(' || c == '[') {
                    stack.add(c);
                }
                if (c == ')') {
                    if (stack.isEmpty() || stack.peek() != '(') {
                        isRight = false;
                        break;
                    }
                    stack.pop();
                }
                if (c == ']') {
                    if (stack.isEmpty() || stack.peek() != '[') {
                        isRight = false;
                        break;
                    }
                    stack.pop();
                }
            }

            if (!stack.isEmpty()) {
                isRight = false;
            }

            if (isRight) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
