package intern2019;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        //        크레인인형뽑기게임();
        //        튜플();
        불량사용자();
    }

    private static void 불량사용자() {
        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        String[] banned_id = {"fr*d*", "*rodo", "******", "******"};
        System.out.println(new 불량사용자().solution(user_id, banned_id));
    }

    private static void 튜플() {
        String s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
        System.out.println(Arrays.toString(new 튜플().solution(s)));
    }

    private static void 크레인인형뽑기게임() {
        int[][] board = {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 3},
                {0, 2, 5, 0, 1},
                {4, 2, 4, 4, 2},
                {3, 5, 1, 3, 1}
        };
        int[] moves = {1, 5, 3, 5, 1, 2, 1, 4};
        System.out.println(new 크레인인형뽑기게임().solution(board, moves));
    }
}
