package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 레이저를 쏘는 경우 -> stack.size()
 * 막대가 끝난 경우 -> +1
 */

public class 쇠막대기_10799 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        int sum = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char p = input.charAt(i);

            if (p == '(') {
                stack.add(p);
                continue;
            }

            stack.pop();

            if (input.charAt(i - 1) == '(') {
                sum += stack.size();
            } else {
                sum++;
            }
        }

        System.out.println(sum);
    }
}
