package blind2022;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        주차요금계산();
        //        k진수에서소수개수구하기();
        //        신고결과받기();
        //        양궁대회();
        //        양과늑대();
        //        파괴되지않은건물();
        사라지는발판();
    }

    private static void 사라지는발판() {
        int[][] board = {
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}
        };
        int[] aloc = {1, 0};
        int[] bloc = {1, 2};
        System.out.println(new 사라지는발판().solution(board, aloc, bloc));
    }

    private static void 파괴되지않은건물() {
        int[][] board = {
                {5, 5, 5, 5, 5},
                {5, 5, 5, 5, 5},
                {5, 5, 5, 5, 5},
                {5, 5, 5, 5, 5}
        };
        int[][] skill = {
                {1, 0, 0, 3, 4, 4},
                {1, 2, 0, 2, 3, 2},
                {2, 1, 0, 3, 1, 2},
                {1, 0, 1, 3, 3, 1}
        };
        System.out.println(new 파괴되지않은건물().solution(board, skill));
    }

    private static void 양과늑대() {
        int[] info = {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1};
        int[][] edges = {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 1}, {9, 1}, {4, 3}, {6, 5}, {4, 6}, {8, 9}};
        System.out.println(new 양과늑대().solution(info, edges));
    }

    private static void 양궁대회() {
        int n = 5;
        int[] info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
        System.out.println(Arrays.toString(new 양궁대회().solution(n, info)));
    }

    private static void 신고결과받기() {
        String[] id_list = {"muzi", "frodo", "apeach", "neo"};
        String[] report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
        int k = 2;
        System.out.println(Arrays.toString(new 신고결과받기().solution(id_list, report, k)));
    }

    private static void k진수에서소수개수구하기() {
        int n = 110011;
        int k = 10;
        System.out.println(new k진수에서소수개수구하기().solution(n, k));
    }

    private static void 주차요금계산() {
        int[] fees = {180, 5000, 10, 600};
        String[] records = {
                "05:34 5961 IN",
                "06:00 0000 IN",
                "06:34 0000 OUT",
                "07:59 5961 OUT",
                "07:59 0148 IN",
                "18:59 0000 IN",
                "19:09 0148 OUT",
                "22:59 5961 IN",
                "23:00 5961 OUT"
        };
        System.out.println(Arrays.toString(new 주차요금계산().solution(fees, records)));
    }
}
