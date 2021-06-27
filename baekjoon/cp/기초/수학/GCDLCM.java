package 기초.수학;

import java.io.*;
import java.util.StringTokenizer;

/**
 * 유클리드 호제법
 *
 * a 와 b의 최대공약수를 (a, b)라고 할 때 (a, b)의 최대공약수는 (b, r)의 최대공약수와 같다(r = a % b)
 */

public class GCDLCM {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();

        StringTokenizer st = new StringTokenizer(input, " ");
        int num1 = Integer.parseInt(st.nextToken());
        int num2 = Integer.parseInt(st.nextToken());

        if (num1 >= num2) {
            bw.write(GCD(num1, num2) + "\n");
            bw.write(LCM(num1, num2) + "\n");
        }

        if (num2 > num1) {
            bw.write(GCD(num2, num1) + "\n");
            bw.write(LCM(num2, num1) + "\n");
        }

        bw.flush();
    }

    private static int GCD(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return GCD(num2, num1 % num2);
    }

    private static int LCM(int num1, int num2) {
        return num1 * num2 / GCD(num1, num2);
    }
}
