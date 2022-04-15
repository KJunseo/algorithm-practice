package blind2018;

import java.util.*;

public class 뉴스클러스터링 {
    private List<String> a = new ArrayList<>();
    private List<String> b = new ArrayList<>();

    public int solution(String str1, String str2) {
        makeList(str1, a);
        makeList(str2, b);

        if (a.isEmpty() && b.isEmpty()) {
            return 65536;
        }

        List<String> intersection = new ArrayList<>();
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                String aString = a.get(i);
                String bString = b.get(j);
                if (aString.equals(bString)) {
                    intersection.add(aString);
                    a.set(i, "");
                    b.set(j, "");
                    break;
                }
            }
        }

        double j = (double) intersection.size() / (a.size() + b.size() - intersection.size());

        return (int)(j * 65536);
    }

    private void makeList(String str, List<String> list) {
        for (int i = 0; i < str.length() - 1; i++) {
            String sub = str.substring(i, i + 2).toLowerCase();

            if (isAlpha(sub)) {
                list.add(sub);
            }
        }
    }

    private boolean isAlpha(String sub) {
        for (int i = 0; i < sub.length(); i++) {
            char c = sub.charAt(i);
            if ('a' > c || c > 'z') {
                return false;
            }
        }
        return true;
    }
}
