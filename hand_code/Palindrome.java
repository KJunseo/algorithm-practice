import java.util.*;

public class Palindrome {

    public boolean palindrome(int n) {
        Stack<Integer> stack = new Stack<>();
        Queue<Integer> queue = new LinkedList<>();

        while (n > 0) {
            int value = n % 10;
            n /= 10;
            stack.add(value);
            queue.add(value);
        }

        while (!stack.isEmpty()) {
            int a = stack.pop();
            int b = queue.poll();

            if (a != b) {
                return false;
            }
        }

        return true;
    }

    public boolean palindrome2(int n) {
        Deque<Integer> deque = new ArrayDeque<>();

        while (n > 0) {
            int value = n % 10;
            n /= 10;
            deque.add(value);
        }

        while (deque.size() >= 2) {
            int a = deque.pollFirst();
            int b = deque.pollLast();

            if (a != b) {
                return false;
            }
        }
        return true;
    }

}
