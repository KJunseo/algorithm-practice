package 기초코드작성요령2;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class LowerX {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input1 = br.readLine();
        String input2 = br.readLine();

        StringTokenizer st = new StringTokenizer(input1, " ");
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(input2, " ");
        List<Integer> array = new ArrayList<>(N);
        while(st.hasMoreTokens()) {
            array.add(Integer.parseInt(st.nextToken()));
        }

        for (Integer num : array) {
            if (num < X) {
                bw.write(num + " ");
            }
        }

        bw.flush();
    }
}
