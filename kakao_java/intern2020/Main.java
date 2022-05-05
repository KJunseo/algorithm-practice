package intern2020;

public class Main {

    public static void main(String[] args) {
        키패드누르기();
    }

    private static void 키패드누르기() {
        int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
        String hand = "right";
        System.out.println(new 키패드누르기().solution(numbers, hand));
    }
}
