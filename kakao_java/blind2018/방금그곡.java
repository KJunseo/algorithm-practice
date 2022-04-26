package blind2018;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class 방금그곡 {
    private static final Pattern PATTERN = Pattern.compile("[CDEFGAB]#?");

    public String solution(String m, String[] musicinfos) {
        StringTokenizer st;

        List<Music> music = new ArrayList<>();
        for (int i = 0; i < musicinfos.length; i++) {
            st = new StringTokenizer(musicinfos[i], ",");
            int start = toSec(st.nextToken());
            int end = toSec(st.nextToken());
            String name = st.nextToken();
            List<String> score = getScore(st.nextToken());

            String melody = makeMelody(start, end, score);
            music.add(new Music(i, name, melody, end - start));
        }

        List<Music> result = music.stream()
                                  .filter(mu -> mu.match(m))
                                  .collect(Collectors.toList());

        if (result.isEmpty()) {
            return "(None)";
        }

        Collections.sort(result);

        return result.get(0).name;
    }

    private String makeMelody(int start, int end, List<String> score) {
        String melody = "";
        int playTime = end - start;
        if (playTime > score.size()) {
            int index = 0;
            for (int i = 0; i < playTime; i++) {
                if (index == score.size()) {
                    index = 0;
                }
                melody += score.get(index++);
            }
        } else {
            for (int i = 0; i < playTime; i++) {
                melody += score.get(i);
            }
        }
        return melody;
    }

    private List<String> getScore(String score) {
        Matcher matcher = PATTERN.matcher(score);

        List<String> result = new ArrayList<>();
        while (matcher.find()) {
            result.add(matcher.group());
        }

        return result;
    }

    private int toSec(String time) {
        int result = 0;
        String[] t = time.split(":");
        result += 60 * Integer.parseInt(t[0]);
        result += Integer.parseInt(t[1]);
        return result;
    }

    static class Music implements Comparable<Music> {
        int id;
        String name;
        String melody;
        int playTime;

        public Music(int id, String name, String melody, int playTime) {
            this.id = id;
            this.name = name;
            this.melody = melody;
            this.playTime = playTime;
        }

        public boolean match(String m) {
            for (int i = 0; i < melody.length() - m.length() + 1; i++) {
                String sub = melody.substring(i, i + m.length());
                if (m.equals(sub)) {
                    if (i + m.length() == melody.length()) {
                        return true;
                    }
                    char c = melody.charAt(i + m.length());
                    if (c != '#') {
                        return true;
                    }
                }
            }
            return false;
        }

        @Override
        public int compareTo(Music o) {
            if (o.playTime == this.playTime) {
                return Integer.compare(this.id, o.id);
            }
            return Integer.compare(o.playTime, this.playTime);
        }
    }
}
