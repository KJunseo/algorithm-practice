package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 자료형 조심해야함.
 * 빌딩 높이 입력에 따라 해당 빌딩을 볼 수 있는 기존 빌딩 수를 더하는 식
 */

public class 옥상정원꾸미기_6198 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long sum = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            int height = Integer.parseInt(br.readLine());

            while (!stack.isEmpty()) {
                if (stack.peek() <= height) {
                    stack.pop();
                } else {
                    break;
                }
            }

            sum += stack.size();
            stack.push(height);
        }

        System.out.println(sum);
    }
}
