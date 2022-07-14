import java.util.Stack;

public class QueueUsingTwoStack<T> {
    private Stack<T> stack1 = new Stack<>();
    private Stack<T> stack2 = new Stack<>();

    public void add(T num) {
        stack1.add(num);
    }

    public T poll() {
        if (!stack2.isEmpty()) {
            return stack2.pop();
        }

        while (!stack1.isEmpty()) {
            stack2.add(stack1.pop());
        }
        return stack2.pop();
    }
}
