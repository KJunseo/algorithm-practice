package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class 세수의합_2295_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] nums;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        nums = new int[n];
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            nums[i] = num;
        }

        Arrays.sort(nums);

        List<Integer> sumOfTwoNum = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                sumOfTwoNum.add(nums[i] + nums[j]);
            }
        }

        Collections.sort(sumOfTwoNum);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int value = nums[i] - nums[j];
                if (binarySearch(sumOfTwoNum, value)) {
                    System.out.println(nums[i]);
                    return;
                }
            }
        }
    }

    private static boolean binarySearch(List<Integer> array, int value) {
        int start = 0;
        int end = array.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            Integer cur = array.get(mid);
            if (cur > value) {
                end = mid - 1;
            } else if (cur < value) {
                start = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
}
