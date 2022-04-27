package blind2020;

import java.util.ArrayDeque;
import java.util.Deque;

public class 괄호변환 {

    public String solution(String p) {
        if (p.isBlank()) {
            return "";
        }

        String u = "";
        String v = "";

        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '(') {
                count1++;
            } else {
                count2++;
            }

            if (count1 == count2) {
                u = p.substring(0, i + 1);
                v = p.substring(i + 1);
                break;
            }
        }

        if (isRight(u)) {
            u += solution(v);
        } else {
            String temp = "(";
            temp += solution(v);
            temp += ")";
            u = u.substring(1, u.length() - 1);
            temp += reverse(u);
            u = temp;
        }

        return u;
    }

    private boolean isRight(String str) {
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '(') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.isEmpty();
    }

    private String reverse(String str) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == ')') {
                result.append('(');
            } else {
                result.append(')');
            }
        }
        return result.toString();
    }
}
