package 기초.수학;

import java.io.*;
import java.util.StringTokenizer;

public class CalculateDate {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();

        StringTokenizer st = new StringTokenizer(input, " ");

        int finalE = Integer.parseInt(st.nextToken());
        int finalS = Integer.parseInt(st.nextToken());
        int finalM = Integer.parseInt(st.nextToken());

        int E = 0;
        int S = 0;
        int M = 0;
        int day = 0;

        while(true) {
            E++;
            S++;
            M++;
            day++;

            if (E > 15) {
                E = 1;
            }

            if (S > 28) {
                S = 1;
            }

            if (M > 19) {
                M = 1;
            }

            if (E == finalE && S == finalS && M == finalM) {
                break;
            }
        }

        bw.write(day + "\n");
        bw.flush();
    }
}
