package 배열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 숫자 6과 9는 같은 거라 볼 수 있기 때문에 (6의 개수 + 9의 개수) / 2 를 해준다.
 * 6의 개수 + 9의 개수가 홀수인 경우 올림을 해줘야하는데 int / int 는 소수점이 나오지 않으므로 (double)로 형변환을 해준다.
 */

public class 방번호_1475 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String roomNumber = br.readLine();

        int[] numbers = new int[10];

        for (int i = 0; i < roomNumber.length(); i++) {
            numbers[roomNumber.charAt(i) - '0']++;
        }

        int max = (int) Math.ceil((double) (numbers[6] + numbers[9]) / 2);
        for (int i = 0; i < numbers.length; i++) {
            if (i == 6 || i == 9) {
                continue;
            }
            if (max <= numbers[i]) {
                max = numbers[i];
            }
        }

        System.out.println(max);
    }
}
