package sorting;

public class SelectionSort {
    /*
        시간 복잡도: n - 1, n - 2, ..., 1 -> O(n^2)
        공간 복잡도: array 크기 -> O(n)
     */
    public int[] selectionSort(int[] array) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
        return array;
    }
}
