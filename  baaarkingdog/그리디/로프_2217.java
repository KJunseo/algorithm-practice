package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 로프_2217 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] ropes;
    private static int answer;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        ropes = new int[n];
        for (int i = 0; i < n; i++) {
            ropes[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(ropes);

        int count = 1;
        answer = ropes[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            count++;
            answer = Math.max(answer, count * ropes[i]);
        }

        System.out.println(answer);
    }
}
