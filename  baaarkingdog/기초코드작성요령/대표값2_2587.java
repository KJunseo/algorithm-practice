package 기초코드작성요령;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 대표값2_2587 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int sum = 0;
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            int num = Integer.parseInt(br.readLine());
            sum += num;
            numbers.add(num);
        }

        Collections.sort(numbers);

        bw.write(sum / 5 + "\n");
        bw.write(numbers.get(2) + "");
        bw.flush();
        bw.close();
    }
}
