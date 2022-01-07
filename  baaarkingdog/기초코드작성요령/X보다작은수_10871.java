package 기초코드작성요령;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class X보다작은수_10871 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input1 = br.readLine();
        String input2 = br.readLine();

        StringTokenizer st = new StringTokenizer(input1, " ");
        st.nextToken();
        int X = Integer.parseInt(st.nextToken());

        int[] array = Arrays.stream(input2.split(" "))
                            .mapToInt(Integer::parseInt)
                            .toArray();

        for(int num : array) {
            if (num < X) {
                bw.write(num + " ");
            }
        }

        bw.flush();
    }
}
