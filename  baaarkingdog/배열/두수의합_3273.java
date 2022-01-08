package 배열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * array의 인덱스를 수열에 포함된 수와 일치시켜 확인.
 * (x - 수열에 포함된 수)가 음수인 경우 예외처리.
 * 투포인터로도 풀 수 있다고 함
 */

public class 두수의합_3273 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        br.readLine();
        String input = br.readLine();
        int x = Integer.parseInt(br.readLine());

        int[] numbers = new int[2000001];
        String[] sequence = input.split(" ");

        int count = 0;
        for (String s : sequence) {
            int num = Integer.parseInt(s);

            if (x - num < 0) {
                continue;
            }

            if (numbers[x - num] != 0) {
                count++;
            }

            numbers[num]++;
        }

        System.out.println(count);

    }
}
