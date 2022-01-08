package 배열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 개수세기_10807 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        br.readLine();
        String input = br.readLine();
        int v = Integer.parseInt(br.readLine());

        String[] numbers = input.split(" ");
        int[] negative = new int[101];
        int[] positive = new int[101];

        for (String number : numbers) {
            int index = Integer.parseInt(number);

            if (index < 0) {
                index *= -1;
                negative[index]++;
            } else {
                positive[index]++;
            }
        }

        if (v < 0) {
            v *= -1;
            System.out.println(negative[v]);
        } else {
            System.out.println(positive[v]);
        }
    }
}
