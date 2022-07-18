package sorting;

import java.util.PriorityQueue;

public class KFirstSort {

    public int[] KFirstSort(int[] array, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int[] answer = new int[array.length];
        answer[0] = array[k];
        for (int i = 0; i < array.length; i++) {
            if (i == k) {
                continue;
            }
            pq.add(array[i]);
        }

        for (int i = 1; i < array.length; i++) {
            answer[i] = pq.poll();
        }
        return answer;
    }
}
