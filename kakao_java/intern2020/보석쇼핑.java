package intern2020;

import java.util.*;

public class 보석쇼핑 {

    public int[] solution(String[] gems) {
        int typeCount = new HashSet<>(Arrays.asList(gems)).size();
        Map<String, Integer> bucket = new HashMap<>();

        int len = gems.length - 1;
        int p1 = 0;
        int p2 = 0;
        int ax = 1;
        int ay = gems.length;

        while (p2 <= gems.length) {
            if (bucket.size() == typeCount) {
                if (bucket.get(gems[p1]) > 1) {
                    bucket.put(gems[p1], bucket.get(gems[p1]) - 1);
                    p1++;
                } else {
                    if (p2 == gems.length) {
                        break;
                    }
                    bucket.put(gems[p2], bucket.getOrDefault(gems[p2], 0) + 1);
                    p2++;
                }
            } else {
                bucket.put(gems[p2], bucket.getOrDefault(gems[p2], 0) + 1);
                p2++;
            }

            if (len > p2 - p1 && bucket.size() == typeCount) {
                len = p2 - p1;
                ax = p1 + 1;
                ay = p2;
            }
        }

        return new int[]{ax, ay};
    }
}
