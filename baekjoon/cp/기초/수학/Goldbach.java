package 기초.수학;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * 숫자의 제곱근까지만 확인해주면 된다.(대칭이기 때문)
 * i + (num - i) = num 이라는 성질을 이용
 *
 * 배열과 List 사용시, 배열이 메모리도 적게 쓰고 빠르다
 * 배열 사용 : 메모리 - 24088KB / 시간 432ms
 * List 사용 : 메모리 - 46548KB / 시간 504ms
 *
 * 알고리즘 풀때는 배열을 써야하나.. 싶다.
 */

public class Goldbach {
    private static final int RANGE = 1000001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

//        List<Integer> sieve = makeEratosthenes();
        boolean[] isPrime = new boolean[RANGE];
        makeEratosthenes(isPrime);

        int num;
        while ((num = Integer.parseInt(br.readLine())) != 0) {
            int p1 = -1;
            int p2 = -1;

            for (int i = 2; i <= num / 2; i++) {
                if (isPrime[i] && isPrime[num - i]) {
                    p1 = i;
                    p2 = num - i;
                    break;
                }
//                if (sieve.get(i) != 0 && sieve.get(num - i) != 0) {
//                    p1 = sieve.get(i);
//                    p2 = sieve.get(num - i);
//                    break;
//                }
            }

            if (p1 == -1 || p2 == -1) {
                bw.write("Goldbach's conjecture is wrong." + "\n");
            } else {
                bw.write(num + " = " + p1 + " + " + p2 + "\n");
            }
        }
        bw.flush();
    }

    private static void makeEratosthenes(boolean[] isPrime) {
        for (int i = 2; i < RANGE; i++) {
            isPrime[i] = true;
        }

        for (int i = 2; i < RANGE; i++) {
            for (int j = i * 2; j < RANGE; j += i) {
                if (!isPrime[j]) {
                    continue;
                }
                isPrime[j] = false;
            }
        }
    }

    private static List<Integer> makeEratosthenes() {
        List<Integer> array = new ArrayList<>(RANGE);
        for (int i = 0; i < RANGE; i++) {
            array.add(i);
        }

        for (int i = 2; i < RANGE; i++) {
            if (array.get(i) == 0) {
                continue;
            }
            for (int j = i * 2; j < RANGE; j += i) {
                array.set(j, 0);
            }
        }

        return array;
    }
}
