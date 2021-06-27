package 기초.수학;

import java.io.*;
import java.util.StringTokenizer;

public class LCM {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < T; i++) {
            String input = br.readLine();
            st = new StringTokenizer(input, " ");
            int num1 = Integer.parseInt(st.nextToken());
            int num2 = Integer.parseInt(st.nextToken());

            if (num1 >= num2) {
                bw.write(lcm(num1, num2) + "\n");
            }

            if (num2 > num1) {
                bw.write(lcm(num2, num1) + "\n");
            }
        }
        bw.flush();
    }

    private static int lcm(int num1, int num2) {
        return num1 * num2 / gcd(num1, num2);
    }

    private static int gcd(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return gcd(num2, num1 % num2);
    }
}
