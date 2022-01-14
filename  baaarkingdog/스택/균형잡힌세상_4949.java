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

                if (canIgnoreLetter(c)) {
                    continue;
                }

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

    private static boolean canIgnoreLetter(char c) {
        if ('a' <= c && c <= 'z') {
            return true;
        }
        if ('A' <= c && c <= 'Z') {
            return true;
        }
        return c == ' ' || c == '.';
    }
}
