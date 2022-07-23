package sum;

import java.util.*;

public class TwoSum {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int num = target - nums[i];

            if (map.containsKey(num)) {
                return new int[] {map.get(num), i};
            }
            map.put(nums[i], i);
        }

        return new int[] {-1, -1};
    }

    public int[] twoSumBR(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i == j) {
                    continue;
                }
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }

    public int[] twoSumBS(int[] nums, int target) {
        List<Num> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(new Num(nums[i], i));
        }

        Collections.sort(list);

        for (int i = 0; i < nums.length; i++) {
            int j = binarySearch(list, i, target);

            if (j != -1) {
                return new int[] {list.get(i).index, list.get(j).index};
            }
        }
        return new int[] {-1, -1};
    }

    private int binarySearch(List<Num> nums, int i, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (i == mid) {
                mid++;
            }

            Num num1 = nums.get(i);
            Num num2 = nums.get(mid);

            if (num1.value + num2.value == target) {
                return mid;
            } else if (num1.value + num2.value < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    static class Num implements Comparable<Num> {
        int value;
        int index;

        public Num(int value, int index) {
            this.value = value;
            this.index = index;
        }

        @Override
        public int compareTo(Num o) {
            return Integer.compare(this.value, o.value);
        }
    }
}
