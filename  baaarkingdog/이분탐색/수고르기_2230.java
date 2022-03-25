package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 수고르기_2230 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static int[] array;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(array);

        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int start = i;
            int end = n;
            while (start != n) {
                int mid = (start + end) / 2;

                if (array[mid] - array[i] == m) {
                    answer = m;
                    break;
                }

                if (array[mid] - array[i] < m) {
                    start = mid + 1;
                } else if (start == mid) {
                    answer = Math.min(answer, array[mid] - array[i]);
                    break;
                } else {
                    end = mid;
                }
            }
        }

        System.out.println(answer);
    }

}
