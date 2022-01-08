package 배열;

import java.io.*;

public class 숫자의개수_2577 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int number = Integer.parseInt(br.readLine());
        for (int i = 0; i < 2; i++) {
            number *= Integer.parseInt(br.readLine());
        }

        int[] nums = new int[10];
        String numberString = String.valueOf(number);
        
        for (int i = 0; i < numberString.length(); i++) {
            int index = numberString.charAt(i) - '0';
            nums[index]++;
        }

        for (int num : nums) {
            bw.write(num + "\n");
        }
        bw.flush();
        bw.close();
    }
}
