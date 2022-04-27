package blind2020;

public class Main {

    public static void main(String[] args) {
        //        문자열압축();
        //        괄호변환();
        자물쇠와열쇠();
    }

    private static void 자물쇠와열쇠() {
        int[][] key = {
                {0, 0, 0},
                {1, 0, 0},
                {0, 1, 1}
        };
        int[][] lock = {
                {1, 1, 1},
                {1, 1, 0},
                {1, 0, 1}
        };
        System.out.println(new 자물쇠와열쇠().solution(key, lock));
    }

    private static void 괄호변환() {
        String p = "()))((()";
        System.out.println(new 괄호변환().solution(p));
    }

    private static void 문자열압축() {
        String s = "ababcdcdababcdcd";
        System.out.println(new 문자열압축().solution(s));
    }
}
