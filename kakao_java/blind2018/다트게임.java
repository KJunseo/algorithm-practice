package blind2018;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 다트게임 {
    public int solution(String dartResult) {
        Pattern pattern = Pattern.compile("([0-9]+)([SDT])([*#]?)");
        Matcher matcher = pattern.matcher(dartResult);

        int[] scores = new int[3];
        int index = 0;
        while (matcher.find()) {
            int score = Integer.parseInt(matcher.group(1));
            String bonus = matcher.group(2);
            String option = matcher.group(3);

            if ("D".equals(bonus)) {
                score *= score;
            } else if ("T".equals(bonus)) {
                score *= score * score;
            }

            if ("*".equals(option)) {
                score *= 2;
                if (index - 1 >= 0) {
                    scores[index - 1] *= 2;
                }
            } else if ("#".equals(option)) {
                score *= -1;
            }

            scores[index++] = score;
        }

        int answer = 0;
        for (int i = 0; i < 3; i++) {
            answer += scores[i];
        }

        return answer;
    }
}
