package intern2019;

import java.util.ArrayDeque;
import java.util.Deque;

public class 크레인인형뽑기게임 {

    public int solution(int[][] board, int[] moves) {
        Deque<Integer>[] machine = new Deque[board[0].length];

        for (int j = 0; j < board[0].length; j++) {
            Deque<Integer> deque = new ArrayDeque<>();
            for (int i = board.length - 1; i >= 0; i--) {
                if (board[i][j] != 0) {
                    deque.addLast(board[i][j]);
                }
            }
            machine[j] = deque;
        }

        int count = 0;
        Deque<Integer> bucket = new ArrayDeque<>();
        for (int move : moves) {
            Deque<Integer> line = machine[move - 1];

            if (line.isEmpty()) {
                continue;
            }

            int doll = line.pollLast();

            if (bucket.isEmpty()) {
                bucket.addLast(doll);
            } else if (bucket.peekLast() == doll) {
                bucket.pollLast();
                count++;
            } else {
                bucket.addLast(doll);
            }
        }

        return count * 2;
    }

}
