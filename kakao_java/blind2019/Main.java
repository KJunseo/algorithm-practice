package blind2019;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //        매칭점수();
        //        실패율();
        //        오픈채팅방();
        //        길찾기게임();
        후보키();
    }

    private static void 후보키() {
        String[][] relation = {
                {"100", "ryan", "music", "2"},
                {"200", "apeach", "math", "2"},
                {"300", "tube", "computer", "3"},
                {"400", "con", "computer", "4"},
                {"500", "muzi", "music", "3"},
                {"600", "apeach", "music", "2"}
        };
        System.out.println(new 후보키().solution(relation));
    }

    private static void 길찾기게임() {
        int[][] nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
        System.out.println(Arrays.deepToString(new 길찾기게임().solution(nodeinfo)));
    }

    private static void 오픈채팅방() {
        String[] record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
        System.out.println(Arrays.toString(new 오픈채팅방().solution(record)));
    }

    private static void 실패율() {
        int n = 5;
        int[] stages = {2, 1, 2, 6, 2, 4, 3, 3};
        System.out.println(Arrays.toString(new 실패율().solution(n, stages)));
    }

    private static void 매칭점수() {
        String word = "Muzi";
        String[] pages = {
                "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
                "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
        };

        System.out.println(new 매칭점수().solution(word, pages));
    }
}
