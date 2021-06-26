package 기초코드작성요령2;

import java.io.*;
import java.util.StringTokenizer;

/**
    Scanner와 System.out.println을 사용하는 것 보다
    BufferedReader, BufferedWriter를 쓰는게 훨씬 빠르다고 한다.
    BufferedReader readLine()로 입력받은 후에는 StringTokenizer를 통해 값을 잘라 받을 수 있다.
    BufferedWriter는 int형을 출력하려고 하면 제대로 출력되지 않으므로, String 형태로 바꿔줘야한다.
    또 write()로 쓰고, 꼭 flush()를 해주자.
    다쓰고나면 close()해주기
 */

public class AplusB {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        bw.write(a + b + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}