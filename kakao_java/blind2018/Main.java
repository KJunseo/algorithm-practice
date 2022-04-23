package blind2018;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
//        비밀지도();
//        다트게임();
//        캐시();
//        뉴스클러스터링();
        셔틀버스();
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
