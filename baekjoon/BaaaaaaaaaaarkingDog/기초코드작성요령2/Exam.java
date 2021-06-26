package 기초코드작성요령2;

import java.io.*;
import java.util.Arrays;
import java.util.function.Predicate;

public class Exam {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int score = Integer.parseInt(br.readLine());

        bw.write(Score.check(score));
        bw.flush();
    }

    enum Score {
        A(score -> 90 <= score && 100 >= score),
        B(score -> 80 <= score && 89 >= score),
        C(score -> 70 <= score && 79 >= score),
        D(score -> 60 <= score && 69 >= score),
        F(score -> 59 >= score);

        private final Predicate<Integer> p;

        Score(Predicate<Integer> p) {
            this.p = p;
        }

        public static String check(int score) {
            return Arrays.stream(values())
                    .filter(s -> s.p.test(score))
                    .findFirst()
                    .orElseThrow(IllegalArgumentException::new)
                    .name();
        }
    }
}
