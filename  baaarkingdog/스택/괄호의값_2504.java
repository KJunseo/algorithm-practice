package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 계산하는 방법을 떠올리지 못해 힘들었다.
 * 분배 법칙을 생각하면 된다.
 *
 * ex) (()[[]])
 * 2 * (2 + 3 * (3)))
 * = (2 * 2) + (2 * 3 * 3)
 *
 * 1로 초기화 된 임수변수를 두고 스택에 남아있는 괄호에 맞게 곱하기와 나누기를 해준다.
 * 스택에 남아있는 '(' 하나당 * 2, 스택에 남아있는 '[' 하나당 * 3 이 남아있으므로 분배 법칙이 성립된다.
 * 닫는 괄호가 나온 경우 바로 직전 괄호가 자신과 짝이 맞는 열린 괄호인 경우 result에 더하기를 해준다. 그 후 괄호에 맞게 /2 또는 /3을 수행한다.
 *
 * ( -> temp * 2
 * [ -> temp * 3
 *
 * 1) stack: (  | temp = 1 * 2
 * 2) stack: ((  | temp = 1 * 2 * 2
 * 3) stack: (  | temp = 1 * 2 * 2 / 2  | result = 0 + (1 * 2 * 2)
 *
 */

public class 괄호의값_2504 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        int result = 0;
        int temp = 1;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char p = input.charAt(i);

            if (p == '(' || p == '[') {
                if (p == '(') {
                    temp *= 2;
                } else {
                    temp *= 3;
                }
                stack.add(p);
            }

            if (p == ')') {
                if (stack.isEmpty() || stack.peek() == '[') {
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
                if (stack.isEmpty() || stack.peek() == '(') {
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
