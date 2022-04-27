package blind2020;

import java.util.ArrayList;
import java.util.List;

public class 문자열압축 {

    public int solution(String s) {
        int answer = s.length();
        for (int i = 1; i <= s.length() / 2; i++) {
            int length = compression(s, i).length();
            answer = Math.min(answer, length);
        }

        return answer;
    }

    private String compression(String s, int unit) {
        List<String> split = new ArrayList<>();
        int i;
        for (i = 0; i <= s.length() - unit; i += unit) {
            String sub = s.substring(i, i + unit);
            split.add(sub);
        }

        String remain = s.substring(i);
        if (!remain.isBlank()) {
            split.add(remain);
        }

        String result = "";
        for (i = 0; i < split.size(); i++) {
            String cur = split.get(i);
            int j;
            for (j = i + 1; j < split.size(); j++) {
                if (!cur.equals(split.get(j))) {
                    break;
                }
            }
            int diff = j - i;
            if (diff > 1) {
                result += diff;
            }
            result += cur;
            i = j - 1;
        }

        return result;
    }
}

