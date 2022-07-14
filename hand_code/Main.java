import java.util.Arrays;

import sorting.*;

public class Main {

    public static void main(String[] args) {
//        bubbleSort();
//        insertionSort();
//        selectionSort();
//        quickSort();
//        mergeSort();
        palindrome();
    }

    private static void palindrome() {
        int n = 1123543211;
        System.out.println(new Palindrome().palindrome(n));
    }

    private static void bubbleSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new BubbleSort().bubbleSort(array)));
    }

    private static void insertionSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new InsertionSort().insertionSort(array)));
    }

    private static void selectionSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new SelectionSort().selectionSort(array)));
    }

    private static void quickSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        new QuickSort().quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }

    private static void mergeSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        new MergeSort().mergeSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }
}
