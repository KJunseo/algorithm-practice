package string;

import java.util.LinkedHashMap;
import java.util.Map;

public class Compression {

    public String compress(char[] array) {
        Map<Character, Integer> map = new LinkedHashMap<>();

        for (char c : array) {
            int value = map.getOrDefault(c, 0);
            map.put(c, value + 1);
        }

        String answer = "";
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            char c = entry.getKey();
            int value = entry.getValue();

            answer += c;
            if (value > 1) {
                answer += value;
            }
        }
        return answer;
    }

    // 초기 문자 배열의 요소들이 연속적으로만 나타난다고 했을 때 별도의 공간을 사용하지 않고 풀이해라
    public String compressConsecutiveRepeatChar(char[] array) {
        String answer = "";
        char prev = array[0];
        int count = 1;
        for (int i = 1; i < array.length; i++) {
            if (prev == array[i]) {
                count++;
            } else {
                answer += prev;
                if (count > 1) {
                    answer += count;
                }
                prev = array[i];
                count = 1;
            }
        }
        answer += prev;
        if (count > 1) {
            answer += count;
        }

        return answer;
    }
}
