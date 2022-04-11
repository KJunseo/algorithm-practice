import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class 그룹단어체커_1316 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        int count = 0;
        for (int i = 0; i < n; i++) {
            String word = br.readLine();

            if (isGroupWord(word)) {
                count++;
            }
        }

        System.out.println(count);
    }

    private static boolean isGroupWord(String word) {
        Set<Character> set = new HashSet<>();

        char c = word.charAt(0);
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) != c) {
                if (set.contains(c)) {
                    return false;
                }
                set.add(c);
                c = word.charAt(i);
            }
        }

        return !set.contains(c);
    }
}
