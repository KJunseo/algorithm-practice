package sorting;

import java.util.Arrays;

public class MergeSort {
    /*
        시간 복잡도:
            평균: merge n * 순환 깊이 logN -> O(nlogn)
        공간 복잡도: 배열 크기 O(n), 임시 배열 O(n), 재귀스택(logn) -> O(n) (임시 배열 메모리 해제 되지 않으면 nlogn)
     */
    public void mergeSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(array, 0, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }

    private void merge(int[] array, int left, int mid, int right) {
        int[] l = Arrays.copyOfRange(array, left, mid + 1);
        int[] r = Arrays.copyOfRange(array, mid + 1, right + 1);

        int lIndex = 0;
        int rIndex = 0;
        int Index = left;

        while (lIndex < l.length && rIndex < r.length) {
            if (l[lIndex] <= r[rIndex]) {
                array[Index++] = l[lIndex++];
            } else {
                array[Index++] = r[rIndex++];
            }
        }

        while (lIndex < l.length) {
            array[Index++] = l[lIndex++];
        }

        while (rIndex < r.length) {
            array[Index++] = r[rIndex++];
        }
    }
}
