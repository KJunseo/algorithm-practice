package intern2021;

import java.util.Map;

public class 숫자문자열과영단어 {
    private Map<String, Integer> map = Map.of(
            "zero", 0,
            "one", 1,
            "two", 2,
            "three", 3,
            "four", 4,
            "five", 5,
            "six", 6,
            "seven", 7,
            "eight", 8,
            "nine", 9
    );

    public int solution(String s) {
        String answer = "";

        String temp = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                answer += c;
                continue;
            }
            temp += c;

            if (map.containsKey(temp)) {
                answer += map.get(temp);
                temp = "";
            }
        }

        return Integer.parseInt(answer);
    }
}
