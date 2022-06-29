public class Main {

    public static void main(String[] args) {
        상호평가 상호평가 = new 상호평가();
        int[][] scores = {
                {100, 90, 98, 88, 65},
                {50, 45, 99, 85, 77},
                {47, 88, 95, 80, 67},
                {61, 57, 100, 85, 65},
                {24, 90, 94, 75, 65}
        };
        int[][] scores2 = {
                {50, 90},
                {50, 87}
        };
        int[][] scores3 = {
                {70, 49, 90},
                {68, 50, 38},
                {73, 31, 100}
        };
        System.out.println(상호평가.solution(scores));
        System.out.println(상호평가.solution(scores2));
        System.out.println(상호평가.solution(scores3));
    }
}
