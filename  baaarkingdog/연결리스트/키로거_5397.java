package 연결리스트;

import java.io.*;
import java.util.*;

public class 키로거_5397 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            String input = br.readLine();
            String[] commands = input.split("");

            List<String> inputBox = new LinkedList<>();
            ListIterator<String> cursor = inputBox.listIterator();

            for (String c : commands) {
                if ("<".equals(c)) {
                    if (cursor.hasPrevious()) {
                        cursor.previous();
                    }
                } else if (">".equals(c)) {
                    if (cursor.hasNext()) {
                        cursor.next();
                    }
                } else if ("-".equals(c)) {
                    if (cursor.hasPrevious()) {
                        cursor.previous();
                        cursor.remove();
                    }
                } else {
                    cursor.add(c);
                }
            }

            for (String s : inputBox) {
                bw.write(s);
            }
            bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
}
