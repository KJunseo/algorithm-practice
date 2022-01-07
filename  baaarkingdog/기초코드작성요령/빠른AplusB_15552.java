package 기초코드작성요령;

import java.io.*;
import java.util.StringTokenizer;

/**
 * 입력 -> BufferedReader
 * 출력 -> BufferedWriter or StringBuilder(데이터 양이 많아질수록 BufferedWriter가 더 빠르다고 함)
 */

public class 빠른AplusB_15552 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input, " ");

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            bw.write(A + B + "\n");
        }

        bw.flush();
        bw.close();
    }
}
