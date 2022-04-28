package blind2021;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        합승택시요금();
        //        신규아이디추천();
        메뉴리뉴얼();
    }

    private static void 메뉴리뉴얼() {
        String[] orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
        int[] course = {2, 3, 5};
        System.out.println(Arrays.toString(new 메뉴리뉴얼().solution(orders, course)));
    }

    private static void 신규아이디추천() {
        String new_id = "...!@BaT#*..y.abcdefghijklm";
        System.out.println(new 신규아이디추천().solution(new_id));
    }

    private static void 합승택시요금() {
        int n = 6;
        int s = 4;
        int a = 6;
        int b = 2;
        int[][] fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
        System.out.println(new 합승택시요금().solution(n, s, a, b, fares));
    }
}
