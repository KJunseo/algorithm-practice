package intern2021;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        숫자문자열과영단어();
        //        거리두기확인하기();
        표편집();
    }

    private static void 표편집() {
        int n = 8;
        int k = 2;
        String[] cmd = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"};
        System.out.println(new 표편집().solution(n, k, cmd));
    }

    private static void 거리두기확인하기() {
        String[][] places = {
                {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        };
        System.out.println(Arrays.toString(new 거리두기확인하기().solution(places)));
    }

    private static void 숫자문자열과영단어() {
        String s = "one4seveneight";
        System.out.println(new 숫자문자열과영단어().solution(s));
    }
}
