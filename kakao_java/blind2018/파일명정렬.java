package blind2018;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 파일명정렬 {
    private static final Pattern PATTERN = Pattern.compile("([^0-9]+)([0-9]+)([a-zA-Z0-9.-]*)?");

    public String[] solution(String[] files) {
        List<File> result = new ArrayList<>();
        for (int i = 0; i < files.length; i++) {
            Matcher matcher = PATTERN.matcher(files[i]);
            if (matcher.find()) {
                String head = matcher.group(1);
                int number = Integer.parseInt(matcher.group(2));
                String tail = matcher.group(3);

                result.add(new File(i + 1, head, number, tail, files[i]));
            }
        }

        Collections.sort(result);
        String[] answer = new String[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i).original;
        }

        return answer;
    }

    static class File implements Comparable<File> {
        int id;
        String head;
        int number;
        String tail;
        String original;

        public File(int id, String head, int number, String tail, String original) {
            this.id = id;
            this.head = head.toLowerCase();
            this.number = number;
            this.tail = tail;
            this.original = original;
        }

        @Override
        public int compareTo(File o) {
            if (this.head.equals(o.head)) {
                if (this.number == o.number) {
                    return Integer.compare(this.id, o.id);
                }
                return Integer.compare(this.number, o.number);
            }
            return this.head.compareTo(o.head);
        }
    }
}
