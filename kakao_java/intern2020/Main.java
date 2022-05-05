package intern2020;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        키패드누르기();
        //        수식최대화();
        보석쇼핑();
    }

    private static void 보석쇼핑() {
        String[] gems = {"DIA", "EM", "EM", "RUB", "DIA"};
        System.out.println(Arrays.toString(new 보석쇼핑().solution(gems)));
    }

    private static void 수식최대화() {
        String expression = "100-200*300-500+20";
        System.out.println(new 수식최대화().solution(expression));
    }

    private static void 키패드누르기() {
        int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
        String hand = "right";
        System.out.println(new 키패드누르기().solution(numbers, hand));
    }
}
