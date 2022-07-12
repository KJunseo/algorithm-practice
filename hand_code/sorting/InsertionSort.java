package sorting;

public class InsertionSort {
    /*
        시간 복잡도:
            최악의 경우: 역으로 정렬되어 있어서 모든 요소를 검사해야하는 경우 1, 2, 3, ..., n -> O(n^2)
            최선의 경우: 모두 정렬되어 있는 경우 break 문에 바로 걸리기 때문에 O(n)
        공간 복잡도: array 크기 -> O(n)
     */
    public int[] insertionSort(int[] array) {
        int n = array.length;
        for (int i = 1; i < n; i++) {
            int cur = array[i];
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (array[j] <= cur) {
                    break;
                }
                array[j + 1] = array[j];
            }
            array[j + 1] = cur;
        }
        return array;
    }
}
