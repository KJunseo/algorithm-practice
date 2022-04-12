package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class 세수의합_2295_3 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] array;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(array);

        List<Integer> twoSum = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                twoSum.add(array[i] + array[j]);
            }
        }

        Collections.sort(twoSum);

        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (binarySearch(twoSum, array[i] - array[j])) {
                    System.out.println(array[i]);
                    return;
                }
            }
        }
    }

    private static boolean binarySearch(List<Integer> list, int target) {
        int start = 0;
        int end = list.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            int value = list.get(mid);
            if (value == target) {
                return true;
            } else if (value < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
}
