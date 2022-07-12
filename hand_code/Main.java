import java.util.Arrays;

import sorting.bubbleSort;

public class Main {

    public static void main(String[] args) {
        bubbleSort();
    }

    private static void bubbleSort() {
        int[] array = {1, 4, 2, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new bubbleSort().bubbleSort(array)));
    }
}
