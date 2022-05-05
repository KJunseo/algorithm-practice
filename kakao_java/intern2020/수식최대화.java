package intern2020;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 수식최대화 {
    private static final Pattern NUM = Pattern.compile("[0-9]+|[^0-9]");
    private static Matcher MATCHER;

    private long answer;
    private List<String> nums;
    private char[] operators = {'+', '-', '*'};

    public long solution(String expression) {
        MATCHER = NUM.matcher(expression);
        nums = new ArrayList<>();
        while (MATCHER.find()) {
            nums.add(MATCHER.group());
        }
        dfs(0, new ArrayList<>());

        return answer;
    }

    private void dfs(int index, List<Character> order) {
        if (index == 3) {
            List<String> list = new ArrayList<>(nums);
            for (char op : order) {
                for (int i = 0; i < list.size(); i++) {
                    String s = list.get(i);
                    if (s.charAt(0) == op) {
                        long n1 = Long.parseLong(list.get(i - 1));
                        long n2 = Long.parseLong(list.get(i + 1));
                        list.remove(i - 1);
                        list.remove(i - 1);
                        list.remove(i - 1);
                        if (op == '+') {
                            list.add(i - 1, String.valueOf(n1 + n2));
                        } else if (op == '-') {
                            list.add(i - 1, String.valueOf(n1 - n2));
                        } else if (op == '*') {
                            list.add(i - 1, String.valueOf(n1 * n2));
                        }
                        i--;
                    }
                }
            }

            answer = Math.max(answer, Math.abs(Long.parseLong(list.get(0))));
            return;
        }

        for (char operator : operators) {
            if (order.contains(operator)) {
                continue;
            }
            order.add(operator);
            dfs(index + 1, order);
            order.remove(Character.valueOf(operator));
        }
    }
}
