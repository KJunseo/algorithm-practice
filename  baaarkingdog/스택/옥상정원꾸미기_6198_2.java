package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 옥상정원꾸미기_6198_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long sum = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            int height = Integer.parseInt(br.readLine());

            while (!stack.isEmpty()) {
                if (stack.peek() <= height) { // peek되는 빌딩들은 현재 빌딩에 가려서 다음 빌딩을 보지 못한다.
                    stack.pop();
                } else {
                   break;
                }
            }

            sum += stack.size(); // 현재 빌딩을 볼 수 있는 빌딩의 수
            stack.push(height);
        }

        System.out.println(sum);
    }
}
