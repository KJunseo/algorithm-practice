package 기초코드작성요령2;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.function.BiFunction;

public class PSMD {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();

        StringTokenizer st = new StringTokenizer(input, " ");

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        bw.write(Operator.calculate("+", a, b) + "\n");
        bw.write(Operator.calculate("-", a, b) + "\n");
        bw.write(Operator.calculate("*", a, b) + "\n");
        bw.write(Operator.calculate("/", a, b) + "\n");
        bw.write(Operator.calculate("%", a, b) + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    enum Operator {
        PLUS("+", Integer::sum),
        MINUS("-", (num1, num2) -> num1 - num2),
        MULTIPLY("*", (num1, num2) -> num1 * num2),
        DIVIDE("/", (num1, num2) -> num1 / num2),
        MODULE("%", (num1, num2) -> num1 % num2);

        String operator;
        BiFunction<Integer, Integer, Integer> expression;

        Operator(String operator, BiFunction<Integer, Integer, Integer> expression) {
            this.operator = operator;
            this.expression = expression;
        }

        public static Integer calculate(String operator, int a, int b) {
            return Arrays.stream(values())
                    .filter(op -> op.operator.equals(operator))
                    .findFirst()
                    .orElseThrow(IllegalArgumentException::new)
                    .expression.apply(a, b);
        }
    }
}
