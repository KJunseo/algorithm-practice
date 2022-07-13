package sorting;

public class QuickSort {
    /*
        시간 복잡도:
            평균: 파티션 n * 순환 깊이 logN -> O(nlogn)
            최악: 정렬된 상태. 파티션 n * 순환 깊이가 n -> O(n^2)
        공간 복잡도: 배열 크기 O(n), 재귀스택(logn) -> O(n)
     */
    public void quickSort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }

    private int partition(int[] array, int left, int right) {
        int pivot = array[left];
        int lo = left;
        int hi = right;

        while (lo < hi) {

            while (lo < hi && array[hi] > pivot) {
                hi--;
            }

            while (lo < hi && array[lo] <= pivot) {
                lo++;
            }

            swap(array, lo, hi);
        }

        swap(array, left, lo);
        return lo;
    }

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
