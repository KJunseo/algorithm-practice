package blind2020;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        문자열압축();
        //        괄호변환();
        //        자물쇠와열쇠();
        //        기둥과보설치();
        //        외벽점검();
        블록이동하기();
    }

    private static void 블록이동하기() {
        int[][] board = {
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
//        int[][] board = {
//                {0, 0, 0, 1, 1},
//                {0, 0, 0, 1, 0},
//                {0, 1, 0, 1, 1},
//                {1, 1, 0, 0, 1},
//                {0, 0, 0, 0, 0}
//        };
        System.out.println(new 블록이동하기().solution(board));
    }

    private static void 외벽점검() {
        int n = 12;
        int[] weak = {1, 3, 4, 9, 10};
        int[] dist = {3, 5, 7};
        System.out.println(new 외벽점검().solution(n, weak, dist));
    }

    private static void 기둥과보설치() {
        int n = 5;
        int[][] build_frame = {
                {1, 0, 0, 1},
                {1, 1, 1, 1},
                {2, 1, 0, 1},
                {2, 2, 1, 1},
                {5, 0, 0, 1},
                {5, 1, 0, 1},
                {4, 2, 1, 1},
                {3, 2, 1, 1}
        };
        System.out.println(Arrays.deepToString(new 기둥과보설치().solution(n, build_frame)));
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
