package blind2022;

import java.util.*;
import java.util.stream.Collectors;

public class 신고결과받기 {
    private Map<String, User> map;
    private Map<String, Integer> reportCount;

    public int[] solution(String[] id_list, String[] reports, int k) {
        map = new HashMap<>();
        for (String id : id_list) {
            map.put(id, new User(id));
        }

        reportCount = new HashMap<>();
        for (String report : reports) {
            String[] split = report.split(" ");
            String from = split[0];
            String to = split[1];

            User user = map.get(from);
            user.report(to);
        }

        for (Map.Entry<String, User> entry : map.entrySet()) {
            User user = entry.getValue();
            user.calculateReportCount(reportCount);
        }

        List<String> collect = reportCount.entrySet().stream()
                                          .filter(entry -> entry.getValue() >= k)
                                          .map(Map.Entry::getKey)
                                          .collect(Collectors.toList());

        int[] answer = new int[id_list.length];
        for (int i = 0; i < id_list.length; i++) {
            String id = id_list[i];
            User user = map.get(id);
            answer[i] = user.getMailCount(collect);
        }

        return answer;
    }

    static class User {
        String id;
        Set<String> reports;

        public User(String id) {
            this.id = id;
            this.reports = new HashSet<>();
        }

        public void report(String id) {
            reports.add(id);
        }

        public int getMailCount(List<String> collect) {
            int count = 0;
            for (String id : collect) {
                if (reports.contains(id)) {
                    count++;
                }
            }
            return count;
        }

        public void calculateReportCount(Map<String, Integer> reportCount) {
            reports.forEach(report -> {
                Integer count = reportCount.getOrDefault(report, 0);
                reportCount.put(report, count + 1);
            });
        }
    }
}
