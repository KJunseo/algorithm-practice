package 백트래킹;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 로또_6603 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int k;
    private static int[] array;
    private static int[] lotto;

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        while ((k = Integer.parseInt(st.nextToken())) != 0) {
            array = new int[k];
            for (int i = 0; i < k; i++) {
                array[i] = Integer.parseInt(st.nextToken());
            }

            lotto = new int[6];
            makeLotto(0, 0);

            sb.append("\n");

            st = new StringTokenizer(br.readLine());
        }

        System.out.println(sb.toString());
    }

    private static void makeLotto(int start, int num) {
        if (num == 6) {
            for (int n : lotto) {
                sb.append(n).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = start; i < k; i++) {
            lotto[num] = array[i];
            makeLotto(i + 1, num + 1);
        }
    }
}
