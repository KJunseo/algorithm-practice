import java.util.Arrays;

import sorting.BubbleSort;
import sorting.InsertionSort;

public class Main {

    public static void main(String[] args) {
//        bubbleSort();
        insertionSort();
    }

    private static void bubbleSort() {
        int[] array = {1, 4, 2, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new BubbleSort().bubbleSort(array)));
    }

    private static void insertionSort() {
        int[] array = {1, 4, 2, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new InsertionSort().insertionSort(array)));
    }
}
