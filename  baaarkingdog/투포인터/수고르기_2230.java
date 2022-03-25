package 투포인터;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 이분 탐색을 이용한 풀이: ../이분탐색/수고르기_2230.java
 */

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

        int p1 = 0;
        int p2 = 0;
        int answer = Integer.MAX_VALUE;

        while (p1 < n) {
            if (array[p1] - array[p2] < m) {
                p1++;
                continue;
            }

            if (array[p1] - array[p2] == m) {
                answer = m;
                break;
            }

            answer = Math.min(answer, array[p1] - array[p2]);
            p2++;
        }

        System.out.println(answer);
    }

}
