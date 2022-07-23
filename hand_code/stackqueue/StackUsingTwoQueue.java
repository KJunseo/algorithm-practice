package stackqueue;

import java.util.LinkedList;
import java.util.Queue;

public class StackUsingTwoQueue<T> {
    private Queue<T> queue1 = new LinkedList<>();
    private Queue<T> queue2 = new LinkedList<>();

    public void add(T t) {
        if (queue1.isEmpty() && queue2.isEmpty()) {
            queue1.add(t);
        } else if (!queue1.isEmpty()) {
            queue1.add(t);
        } else {
            queue2.add(t);
        }
    }

    public T pop() {
        if (!queue1.isEmpty()) {
            while (queue1.size() > 1) {
                queue2.add(queue1.poll());
            }
            return queue1.poll();
        } else {
            while (queue2.size() > 1) {
                queue1.add(queue2.poll());
            }
            return queue2.poll();
        }
    }
}
