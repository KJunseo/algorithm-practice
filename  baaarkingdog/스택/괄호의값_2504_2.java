package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 괄호의값_2504_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        int result = 0;
        int temp = 1;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char p = input.charAt(i);

            if (p == '(') {
                stack.add(p);
                temp *= 2;
            }
            if (p == '[') {
                stack.add(p);
                temp *= 3;
            }
            if (p == ')') {
                if (stack.isEmpty() || stack.peek() != '(') {
                    result = 0;
                    break;
                }
                stack.pop();
                if (input.charAt(i - 1) == '(') {
                    result += temp;
                }
                temp /= 2;
            }
            if (p == ']') {
                if (stack.isEmpty() || stack.peek() != '[') {
                    result = 0;
                    break;
                }
                stack.pop();
                if (input.charAt(i - 1) == '[') {
                    result += temp;
                }
                temp /= 3;
            }
        }

        if (!stack.isEmpty()) {
            result = 0;
        }
        System.out.println(result);
    }
}
