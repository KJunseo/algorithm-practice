package blind2021;

import java.util.*;

import static java.util.stream.Collectors.groupingBy;

public class 메뉴리뉴얼 {
    private Map<String, Integer> map;

    public String[] solution(String[] orders, int[] course) {
        map = new HashMap<>();

        for (String order : orders) {
            char[] chars = order.toCharArray();
            Arrays.sort(chars);
            order = new String(chars);
            for (int num : course) {
                boolean[] check = new boolean[order.length()];
                combination(check, order, 0, num, 0);
            }
        }

        Map<Integer, List<String>> collect = map.entrySet().stream()
                                                .filter(map -> map.getValue() >= 2)
                                                .sorted(Comparator.comparing(Map.Entry<String, Integer>::getValue).reversed())
                                                .map(Map.Entry::getKey)
                                                .collect(groupingBy(String::length));

        List<String> result = new ArrayList<>();
        for (int num : course) {
            List<String> list = collect.get(num);
            if (list == null) {
                continue;
            }
            int max = map.get(list.get(0));
            result.add(list.get(0));
            for (int i = 1; i < list.size(); i++) {
                String cur = list.get(i);
                if (map.get(cur).equals(max)) {
                    result.add(cur);
                } else {
                    break;
                }
            }
        }

        return result.stream()
                     .sorted()
                     .toArray(String[]::new);
    }

    private void combination(boolean[] check, String order, int start, int num, int count) {
        if (count == num) {
            String menus = "";
            for (int i = 0; i < check.length; i++) {
                if (check[i]) {
                    menus += order.charAt(i);
                }
            }

            Integer cnt = map.getOrDefault(menus, 0);
            map.put(menus, cnt + 1);
            return;
        }

        for (int i = start; i < order.length(); i++) {
            if (check[i]) {
                continue;
            }
            check[i] = true;
            combination(check, order, i + 1, num, count + 1);
            check[i] = false;
        }
    }
}
