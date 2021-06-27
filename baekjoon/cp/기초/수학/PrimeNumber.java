package 기초.수학;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 에라토스테네스의 체
 *
 * 2의 배수 다 지우고, 3의 배수 다 지우고...
 */

public class PrimeNumber {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        List<Integer> array = new ArrayList<>(1001);
        for (int i = 0; i <= 1000; i++) {
            array.add(i);
        }

        array.set(1, 0);

        for (int i = 2; i <= 1000; i++) {
            if (array.get(i) == 0) {
                continue;
            }

            for (int j = 2 * i; j <= 1000; j+=i) {
                array.set(j, 0);
            }
        }

        String input = br.readLine();

        int count = 0;
        StringTokenizer st = new StringTokenizer(input, " ");
        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());
            if (array.get(num) != 0) {
                count++;
            }
        }

        bw.write(count + "\n");
        bw.flush();
    }
}
