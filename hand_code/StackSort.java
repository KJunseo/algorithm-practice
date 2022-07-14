import java.util.Stack;

public class StackSort {

    public int[] sort2(int[] array) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        for (int num : array) {
            stack1.add(num);
        }

        while (!stack1.isEmpty()) {
            int num = stack1.pop();
            while (!stack2.isEmpty() && stack2.peek() < num) {
                stack1.add(stack2.pop());
            }
            stack2.add(num);
        }

        int[] result = new int[array.length];
        int index = 0;
        while (!stack2.isEmpty()) {
            result[index++] = stack2.pop();
        }
        return result;
    }

    public int[] sort(int[] array) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        int index = 0;
        while (index < array.length) {
            int value = array[index++];

            if (!stack2.isEmpty()) {
                if (value > stack2.peek()) {
                    value = stack2.pop();
                    index--;
                }
            }

            if (stack1.isEmpty()) {
                stack1.add(value);
                continue;
            }

            while (!stack1.isEmpty() && stack1.peek() < value) {
                int a = stack1.pop();
                stack2.add(a);
            }

            stack1.add(value);
        }

        while (!stack2.isEmpty()) {
            int a = stack2.pop();
            stack1.add(a);
        }

        int[] result = new int[array.length];
        index = 0;
        while (!stack1.isEmpty()) {
            result[index++] = stack1.pop();
        }

        return result;
    }
}
