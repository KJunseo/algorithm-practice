package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 좋은단어_3986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int count = 0;
        for (int i = 0; i < n; i++) {
            String word = br.readLine();

            Stack<Character> stack = new Stack<>();
            for (int j = 0; j < word.length(); j++) {
                char letter = word.charAt(j);

                if (stack.isEmpty()) {
                    stack.add(letter);
                    continue;
                }

                if (stack.peek() == letter) {
                    stack.pop();
                } else {
                    stack.add(letter);
                }
            }

            if (stack.isEmpty()) {
                count++;
            }
        }
        System.out.println(count);
    }
}
