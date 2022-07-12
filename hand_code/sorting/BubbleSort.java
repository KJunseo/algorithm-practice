package sorting;

public class BubbleSort {
    // 시간복잡도: n - 1, n - 2, n - 3, ..., 1 -> O(n^2)
    // 공간복잡도: array 크기만큼 -> O(n)

    public int[] bubbleSort(int[] array) {
        int n = array.length;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                }
            }
        }
        return array;
    }
}
