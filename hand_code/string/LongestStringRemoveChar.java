package string;

import java.util.*;

public class LongestStringRemoveChar {

    public String solutionVer1(String base, String[] candidates) {
        int n = candidates.length;
        char[] baseArray = base.toCharArray();
        Arrays.sort(baseArray);

        Map<char[], String> originalName = new HashMap<>();
        char[][] candidatesArray = new char[n][base.length()];
        for (int i = 0; i < n; i++) {
            candidatesArray[i] = candidates[i].toCharArray();
            Arrays.sort(candidatesArray[i]);
            originalName.put(candidatesArray[i], candidates[i]);
        }

        List<char[]> result = new ArrayList<>();
        for (char[] candidate : candidatesArray) {
            int j = 0;
            for (int i = 0; i < baseArray.length; i++) {
                if (j == candidate.length) {
                    result.add(candidate);
                    break;
                }
                if (baseArray[i] != candidate[j]) {
                    continue;
                }
                j++;
            }
        }

        result.sort((c1, c2) -> Integer.compare(c2.length, c1.length));

        return originalName.get(result.get(0));
    }

    // 순서도 유지되어야 한다면 사용할 수 없음.
    public String solutionVer2(String base, String[] candidates) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < base.length(); i++) {
            char c = base.charAt(i);
            int count = map.getOrDefault(c, 0);
            map.put(c, count + 1);
        }

        String answer = "";
        Map<Character, Integer> temp;
        for (String candidate : candidates) {
            temp = new HashMap<>(map);
            int i;
            for (i = 0; i < candidate.length(); i++) {
                char c = candidate.charAt(i);
                if (!temp.containsKey(c)) {
                    break;
                }
                int count = map.get(c);
                if (count == 0) {
                    break;
                }
                temp.put(c, count - 1);
            }
            if (i == candidate.length()) {
                if (answer.length() < candidate.length()) {
                    answer = candidate;
                }
            }
        }

        return answer;
    }
}
