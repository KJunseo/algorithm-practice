package blind2018;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 압축 {
    private Map<String, Integer> dic = new HashMap<>();

    public int[] solution(String msg) {
        dic = new HashMap<>();
        char c = 'A';
        for (int i = 1; i <= 26; i++, c++) {
            dic.put(String.valueOf(c), i);
        }

        int index = 27;
        int lastIndex = 0;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < msg.length(); i++) {
            for (int j = i; j < msg.length(); j++) {
                String temp = msg.substring(i, j + 1);
                if (!dic.containsKey(temp)) {
                    String sub = temp.substring(0, temp.length() - 1);
                    result.add(dic.get(sub));
                    dic.put(temp, index++);
                    i += sub.length() - 1;
                    lastIndex = j;
                    break;
                }
            }
        }

        String remain = msg.substring(lastIndex);
        result.add(dic.get(remain));

        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        return answer;
    }
}
