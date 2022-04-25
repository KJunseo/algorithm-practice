package blind2018;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 추석트래픽 {
    private static final Pattern PATTERN = Pattern.compile("2016-09-15 ([0-9]+):([0-9]+):([0-9]+).([0-9]+) ([0-9]+).?([0-9]+)?s");

    public int solution(String[] lines) {
        List<Time> times = new ArrayList<>();
        for (int i = 0; i < lines.length; i++) {

            Matcher matcher = PATTERN.matcher(lines[i]);

            while (matcher.find()) {
                ResponseTime responseTime = new ResponseTime(
                        Integer.parseInt(matcher.group(1)),
                        Integer.parseInt(matcher.group(2)),
                        Integer.parseInt(matcher.group(3)),
                        Integer.parseInt(matcher.group(4))
                );
                String s = matcher.group(5);
                String sss = matcher.group(6);
                if (sss == null) {
                    sss = "0";
                }

                ProcessTime processTime = new ProcessTime(Integer.parseInt(s), Integer.parseInt(sss));

                int endTime = responseTime.toInt();
                int startTime = endTime - processTime.toInt() + 1;

                times.add(new Time(startTime, endTime));
            }
        }

        int answer = 0;
        for (Time t : times) {
            int cur = t.end;
            int count = (int) times.stream()
                                   .filter(time -> time.include(cur))
                                   .count();
            answer = Math.max(answer, count);
        }

        return answer;
    }

    static class ResponseTime {
        int hh;
        int mm;
        int ss;
        int sss;

        public ResponseTime(int hh, int mm, int ss, int sss) {
            this.hh = hh;
            this.mm = mm;
            this.ss = ss;
            this.sss = sss;
        }

        public int toInt() {
            int result = sss;
            result += ss * 1000;
            result += mm * 60 * 1000;
            result += hh * 60 * 60 * 1000;
            return result;
        }
    }

    static class ProcessTime {
        int s;
        int sss;

        public ProcessTime(int s, int sss) {
            this.s = s;
            this.sss = sss;
        }

        public int toInt() {
            int result = sss;
            result += s * 1000;
            return result;
        }
    }

    static class Time {
        int start;
        int end;

        public Time(int startTime, int endTime) {
            this.start = startTime;
            this.end = endTime;
        }

        public boolean include(int t) {
            return (t <= end && end < t + 1000) || (t <= start && start < t + 1000) || (start <= t && t <= end);
        }
    }
}
