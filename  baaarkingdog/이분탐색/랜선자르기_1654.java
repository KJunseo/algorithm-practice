package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 랜선자르기_1654 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int k, n;
    private static int[] lan;
    private static long answer;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        lan = new int[k];
        for (int i = 0; i < k; i++) {
            lan[i] = Integer.parseInt(br.readLine());
        }

        binarySearch();

        System.out.println(answer);
    }

    private static void binarySearch() {
        long start = 1;
        long end = (1L << 31) - 1;

        while (start <= end) {
            long mid = (start + end) / 2;

            if (canMake(mid)) {
                start = mid + 1;
                answer = mid;
            } else {
                end = mid - 1;
            }
        }
    }

    private static boolean canMake(long length) {
        int sum = 0;
        for (int l : lan) {
            sum += l / length;
        }
        return sum >= n;
    }
}
