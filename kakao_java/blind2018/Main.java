package blind2018;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
//        비밀지도();
        다트게임();
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
