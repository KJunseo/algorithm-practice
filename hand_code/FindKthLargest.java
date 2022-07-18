import java.util.Collections;
import java.util.PriorityQueue;

public class FindKthLargest {

    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : nums) {
            pq.add(num);
        }

        while (k-- > 1) {
            pq.poll();
        }

        return pq.poll();
    }

    public int findKthLargestQuickSelect(int[] nums, int k) {
        int n = nums.length;
        k = n - k;

        int left = 0;
        int right = n - 1;
        while (left < right) {
            int pivot = partition(nums, left, right);

            if (pivot < k) {
                left = pivot + 1;
            } else if (pivot > k) {
                right = pivot - 1;
            } else {
                return nums[pivot];
            }
        }
        return nums[left];
    }

    private int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int lo = left;
        int hi = right;

        while (lo < hi) {

            while (lo < hi && nums[hi] > pivot) {
                hi--;
            }

            while (lo < hi && nums[lo] <= pivot) {
                lo++;
            }

            swap(nums, lo, hi);
        }

        swap(nums, left, lo);
        return lo;
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
