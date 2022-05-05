package intern2020;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class 키패드누르기 {
    private Hand left;
    private Hand right;
    private Set<Integer> leftHands = new HashSet<>(List.of(1, 4, 7));
    private Set<Integer> rightHands = new HashSet<>(List.of(3, 6, 9));

    private int[] x = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    private int[] y = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

    private StringBuilder sb = new StringBuilder();

    public String solution(int[] numbers, String hand) {
        this.left = new Hand(3, 0, 'L');
        this.right = new Hand(3, 2, 'R');

        for (int num : numbers) {
            if (leftHands.contains(num)) {
                sb.append(left.type);
                left.move(x[num], y[num]);
            } else if (rightHands.contains(num)) {
                sb.append(right.type);
                right.move(x[num], y[num]);
            } else {
                appendResult(hand, x[num], y[num]);
            }
        }

        return sb.toString();
    }

    private void appendResult(String hand, int x, int y) {
        int ld = getDistance(left, x, y);
        int rd = getDistance(right, x, y);
        if (ld > rd) {
            sb.append(right.type);
            right.move(x, y);
        } else if (ld < rd) {
            sb.append(left.type);
            left.move(x, y);
        } else {
            if ("right".equals(hand)) {
                sb.append(right.type);
                right.move(x, y);
            } else {
                sb.append(left.type);
                left.move(x, y);
            }
        }
    }

    private int getDistance(Hand hand, int x, int y) {
        return Math.abs(hand.x - x) + Math.abs(hand.y - y);
    }

    static class Hand {
        int x;
        int y;
        char type;

        public Hand(int x, int y, char type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }

        public void move(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
