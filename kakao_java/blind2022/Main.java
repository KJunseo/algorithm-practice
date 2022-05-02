package blind2022;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        주차요금계산();
        //        k진수에서소수개수구하기();
        //        신고결과받기();
        양궁대회();
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
