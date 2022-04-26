package blind2018;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //        비밀지도();
        //        다트게임();
        //        캐시();
        //        뉴스클러스터링();
        //        셔틀버스();
        //        프렌즈4블록();
        //        N진수게임();
        //        압축();
        //        추석트래픽();
        방금그곡();
    }

    private static void 방금그곡() {
        String m = "ABCDEFG";
        String[] musicinfos = {
                "12:00,12:14,HELLO,CDEFGAB",
                "13:00,13:05,WORLD,ABCDEF"
        };
        System.out.println(new 방금그곡().solution(m, musicinfos));
    }

    private static void 추석트래픽() {
        String[] lines = {
                "2016-09-15 01:00:04.001 2.0s",
                "2016-09-15 01:00:07.000 2s"
        };
        System.out.println(new 추석트래픽().solution(lines));
    }

    private static void 압축() {
        String msg = "ABABABABABABABAB";
        System.out.println(Arrays.toString(new 압축().solution(msg)));
    }

    private static void N진수게임() {
        int n = 2;
        int t = 4;
        int m = 2;
        int p = 1;
        System.out.println(new N진수게임().solution(n, t, m, p));
    }

    private static void 프렌즈4블록() {
        int m = 4;
        int n = 5;
        String[] board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
        System.out.println(new 프렌즈4블록().solution(m, n, board));
    }

    private static void 셔틀버스() {
        int n = 10;
        int t = 25;
        int m = 1;
        String[] timeTables = {"09:00", "09:10", "09:20", "09:30", "09:40", "09:50", "10:00", "10:10", "10:20", "10:30", "10:40", "10:50"};
        System.out.println(new 셔틀버스().solution(n, t, m, timeTables));
    }

    private static void 뉴스클러스터링() {
        String str1 = "handshake";
        String str2 = "shake hands";
        System.out.println(new 뉴스클러스터링().solution(str1, str2));
    }

    private static void 캐시() {
        int cacheSize = 3;
        String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        System.out.println(new 캐시().solution(cacheSize, cities));
    }

    private static void 다트게임() {
        String dartResult = "1D2S3T*";
        System.out.println(new 다트게임().solution(dartResult));
    }

    private static void 비밀지도() {
        int n = 5;
        int[] arr1 = {9, 20, 28, 18, 11};
        int[] arr2 = {30, 1, 21, 17, 28};
        //        int n = 6;
        //        int[] arr1 = {46, 33, 33 ,22, 31, 50};
        //        int[] arr2 = {27 ,56, 19, 14, 14, 10};
        System.out.println(Arrays.toString(new 비밀지도().solution(n, arr1, arr2)));
    }
}
