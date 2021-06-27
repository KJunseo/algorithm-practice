package 기초.수학;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * sum을 long으로 줘야한다..
 */

public class GCDSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int tc = 0; tc < T; tc++) {
            String input = br.readLine();
            st = new StringTokenizer(input, " ");
            int n = Integer.parseInt(st.nextToken());

            List<Integer> array = inputSetting(st, n);

            long sum = calculateSum(array);
            bw.write(sum + "\n");
        }
        bw.flush();
    }

    private static List<Integer> inputSetting(StringTokenizer st, int n) {
        List<Integer> array = new ArrayList<>(n);
        while (st.hasMoreTokens()) {
            array.add(Integer.parseInt(st.nextToken()));
        }
        return array;
    }

    private static long calculateSum(List<Integer> array) {
        long sum = 0;
        for (int i = 0; i < array.size() - 1; i++) {
            int num1 = array.get(i);
            for (int j = i + 1; j < array.size(); j++) {
                int num2 = array.get(j);

                if (num1 >= num2) {
                    sum += gcd(num1, num2);
                }
                if (num2 > num1) {
                    sum += gcd(num2, num1);
                }
            }
        }
        return sum;
    }

    private static int gcd(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return gcd(num2, num1 % num2);
    }
}
