package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 숫자카드2_10816_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[] array;

    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        array = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array);

        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int target = Integer.parseInt(st.nextToken());
            sb.append(upperBound(target) - lowerBound(target)).append(" ");
        }
        System.out.println(sb.toString());
    }

    private static int upperBound(int target) {
        int start = 0;
        int end = n;

        while (start < end) {
            int mid = (start + end) / 2;

            if (target < array[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    private static int lowerBound(int target) {
        int start = 0;
        int end = n;

        while (start < end) {
            int mid = (start + end) / 2;

            if (target <= array[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}
