package 기초코드작성요령2;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

/**
 * `\` 이 문자를 출력하려면 `\\` 두 번 써주기
 */

public class Cat {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write("\\    /\\" + "\n");
        bw.write(" )  ( ')" + "\n");
        bw.write("(  /  )" + "\n");
        bw.write(" \\(__)|" + "\n");
        bw.flush();
        bw.close();
    }
}
