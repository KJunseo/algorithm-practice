package 배열;

import java.io.*;

public class 알파벳개수_10808 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String string = br.readLine();

        int[] alphabet = new int[26];

        for (int i = 0; i < string.length(); i++) {
            int index = string.charAt(i) - 'a';
            alphabet[index]++;
        }

        for (int count : alphabet) {
            bw.write(count + " ");
        }
        bw.flush();
        bw.close();
    }
}
