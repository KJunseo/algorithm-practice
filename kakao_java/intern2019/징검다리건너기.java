package intern2019;

public class 징검다리건너기 {

    public int solution(int[] stones, int k) {
        int left = 1;
        int right = 200_000_000;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canCross(stones, k, mid)) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

    private boolean canCross(int[] stones, int k, int person) {
        int max = 0;
        int count = 0;
        for (int i = 0; i < stones.length; i++) {
            if (stones[i] - person < 0) {
                count++;
            } else {
                max = Math.max(max, count);
                count = 0;
            }
        }

        max = Math.max(max, count);

        return max < k;
    }
}
