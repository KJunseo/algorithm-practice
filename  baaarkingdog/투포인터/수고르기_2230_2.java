package 투포인터;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 수고르기_2230_2 {
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

        long answer = array[n - 1] - array[0];
        int p1 = 0;
        int p2 = 0;
        while (p2 < n) {
            long diff = array[p2] - array[p1];

            if (diff < m) {
                p2++;
                continue;
            }

            if (diff == m) {
                answer = m;
                break;
            }

            answer = Math.min(answer, diff);
            p1++;
        }


//        for (p1 = 0; p1 < n; p1++) {
//            p2 = p1;
//            while (p2 < n) {
//                long diff = array[p2] - array[p1];
//                if (diff >= m) {
//                    if (diff >= answer) {
//                        break;
//                    } else {
//                        answer = diff;
//                    }
//                }
//                p2++;
//            }
//        }

        System.out.println(answer);
    }
}
