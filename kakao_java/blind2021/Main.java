package blind2021;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        합승택시요금();
        //        신규아이디추천();
        //        메뉴리뉴얼();
        순위검색();
    }

    private static void 순위검색() {
        String[] info = {
                "java backend junior pizza 150",
                "python frontend senior chicken 210",
                "python frontend senior chicken 150",
                "cpp backend senior pizza 260",
                "java backend junior chicken 80",
                "python backend senior chicken 50"
        };

        String[] query = {
                "java and backend and junior and pizza 100",
                "python and frontend and senior and chicken 200",
                "cpp and - and senior and pizza 250",
                "- and backend and senior and - 150",
                "- and - and - and chicken 100",
                "- and - and - and - 150"
        };

        System.out.println(Arrays.toString(new 순위검색().solution(info, query)));
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
