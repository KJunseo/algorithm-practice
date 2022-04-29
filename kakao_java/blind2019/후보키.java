package blind2019;

import java.util.*;

public class 후보키 {
    private String[][] relation;
    private boolean[] check;
    private int col;
    private int answer;
    private Set<String> result;

    public int solution(String[][] relation) {
        this.relation = relation;
        this.col = relation[0].length;
        this.check = new boolean[col];
        this.result = new HashSet<>();

        for (int i = 1; i <= col; i++) {
            Arrays.fill(check, false);
            dfs(0, i);
        }

        List<String> list = new ArrayList<>(result);
        list.sort(Comparator.comparingInt(String::length));
        boolean[] remove = new boolean[list.size()];
        for (int i = 0; i < list.size(); i++) {
            if (remove[i]) {
                continue;
            }
            String key = list.get(i);
            int[] keys = Arrays.stream(key.split(""))
                               .mapToInt(Integer::parseInt)
                               .toArray();

            for (int j = i + 1; j < list.size(); j++) {
                if (remove[j]) {
                    continue;
                }
                String comp = list.get(j);
                if (key.length() < comp.length()) {
                    boolean containAll = true;
                    for (int k : keys) {
                        if (!comp.contains(String.valueOf(k))) {
                            containAll = false;
                            break;
                        }
                    }
                    if (containAll) {
                        remove[j] = true;
                    }
                }
            }
            answer++;
        }

        return answer;
    }

    private void dfs(int num, int goal) {
        if (num == goal) {
            Set<String> set = new HashSet<>();
            for (String[] strings : relation) {
                String key = "";
                for (int j = 0; j < col; j++) {
                    if (check[j]) {
                        key += strings[j];
                    }
                }
                if (!key.isEmpty()) {
                    set.add(key);
                }
            }

            if (set.size() == relation.length) {
                String k = "";
                for (int i = 0; i < col; i++) {
                    if (check[i]) {
                        k += i;
                    }
                }
                result.add(k);
            }
            return;
        }

        for (int i = 0; i < col; i++) {
            if (check[i]) {
                continue;
            }
            check[i] = true;
            dfs(num + 1, goal);
            check[i] = false;
        }
    }
}
