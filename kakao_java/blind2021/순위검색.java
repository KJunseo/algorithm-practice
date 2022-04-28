package blind2021;

import java.util.*;

public class 순위검색 {
    private Map<String, List<Integer>> map;

    public int[] solution(String[] infos, String[] queries) {
        map = new HashMap<>();
        for (String info : infos) {
            dfs("", 0, info.split(" "));
        }

        for (String value : map.keySet()) {
            Collections.sort(map.get(value));
        }

        int[] answer = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String query = queries[i].replaceAll(" and ", "");
            String[] s = query.split(" ");
            int score = Integer.parseInt(s[1]);

            answer[i] = lowerBound(map.getOrDefault(s[0], new ArrayList<>()), score);
        }

        return answer;
    }

    private void dfs(String query, int whereCnt, String[] info) {
        if (whereCnt == 4) {
            List<Integer> list = map.getOrDefault(query, new ArrayList<>());
            list.add(Integer.parseInt(info[4]));
            map.put(query, list);
            return;
        }

        dfs(query + info[whereCnt], whereCnt + 1, info); // 고르는 경우
        dfs(query + "-", whereCnt + 1, info); // 고르지 않는 경우
    }

    private int lowerBound(List<Integer> scores, int score) {
        int left = 0;
        int right = scores.size();

        while (left < right) {
            int mid = (left + right) / 2;

            if (score <= scores.get(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return scores.size() - left;
    }
}
