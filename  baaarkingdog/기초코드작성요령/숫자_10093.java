package 기초코드작성요령;

import java.util.Scanner;

/**
    자료형 주의 long으로 받아야한다.
    A == B 인 경우 예외 처리
 */
public class 숫자_10093 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long A = sc.nextLong();
        long B = sc.nextLong();

        long min = Math.min(A, B);
        long max = Math.max(A, B);

        long num = max - min - 1;
        if (num < 0) {
            num = 0;
        }

        System.out.println(num);
        for (long i = min + 1; i < max; i++) {
            System.out.print(i + " ");
        }
    }
}
