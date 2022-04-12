package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ATM_11399 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array);

        int sum = 0;
        int wait = 0;
        for (int i = 0; i < n; i++) {
            wait += array[i];
            sum += wait;
        }

        System.out.println(sum);
    }
}
