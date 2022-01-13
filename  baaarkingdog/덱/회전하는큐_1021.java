package 덱;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/**
 * Deque를 2개 만들어서 각각 방법으로 덱을 만든 후 최솟값을 더해주는 식으로 품
 * 하나의 Deque을 사용할 경우는 현재 찾는 수의 index를 찾아서 index에 따라서 2번을 수행할지, 3번을 수행할지 정해서 하나만 수행하도록 해도 된다.(코드는 이 방법이 깔끔할듯)
 */

public class 회전하는큐_1021 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);

        Deque<Integer> deque1 = new ArrayDeque<>();
        Deque<Integer> deque2 = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            deque1.addLast(i);
            deque2.addLast(i);
        }

        int sum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());

            if (deque1.peekFirst() == num) {
                deque1.pollFirst();
                deque2.pollFirst();
                continue;
            }

            int count1 = 0;
            while (true) {
                Integer temp = deque1.pollFirst();
                deque1.addLast(temp);
                count1++;

                if (deque1.peekFirst() == num) {
                    deque1.pollFirst();
                    break;
                }
            }

            int count2 = 0;
            while (true) {
                Integer temp = deque2.pollLast();
                deque2.addFirst(temp);
                count2++;

                if (deque2.peekFirst() == num) {
                    deque2.pollFirst();
                    break;
                }
            }

            sum += Math.min(count1, count2);
        }

        System.out.println(sum);
    }
}
