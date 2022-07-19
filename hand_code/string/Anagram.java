package string;

import java.util.HashMap;
import java.util.Map;

public class Anagram {

    public boolean isAnagram(String str1, String str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (int i = 0; i < str1.length(); i++) {
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(i);

            int value1 = map1.getOrDefault(c1, 0);
            int value2 = map2.getOrDefault(c2, 0);

            map1.put(c1, value1 + 1);
            map2.put(c2, value2 + 1);
        }

        for (Map.Entry<Character, Integer> entry : map1.entrySet()) {
            char key = entry.getKey();

            int count1 = map1.get(key);
            int count2 = map2.getOrDefault(key, 0);

            if (count1 != count2) {
                return false;
            }
        }
        return true;
    }
}
