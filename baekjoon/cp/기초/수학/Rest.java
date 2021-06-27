package 기초.수학;

import java.io.*;
import java.util.StringTokenizer;

public class Rest {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();

        StringTokenizer st = new StringTokenizer(input, " ");
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        bw.write((A+B) % C + "\n");
        bw.write(((A % C) + (B % C)) % C + "\n");
        bw.write((A * B) % C + "\n");
        bw.write(((A % C) * (B % C)) % C + "\n");
        bw.flush();
    }
}
