package 연결리스트;

import java.io.*;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

/**
 * 처음에는 cursor 값을 직접 조작하여 LinkedList의 add, remove를 실행하였으나
 * add, remove를 하기위한 탐색과정이 O(N)이 걸리므로 시간초과
 *
 * ListIterator를 사용하여 해결
 * Iterator의 위치를 양방향으로 알 수 있다.
 * 따라서 위치를 기억해둬서 add, remove 시 처음부터 탐색하느라 O(N)의 시간을 쓸 필요없다.
 */

public class 에디터_1406 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();

        List<Character> editor = new LinkedList<>();
        for (int i = 0; i < input.length(); i++) {
            editor.add(input.charAt(i));
        }

        int count = Integer.parseInt(br.readLine());

        ListIterator<Character> cursor = editor.listIterator();
        while (cursor.hasNext()) {
            cursor.next();
        }

        for (int i = 0; i < count; i++) {
            String command = br.readLine();

            if ("L".equals(command)) {
                if (cursor.hasPrevious()) {
                    cursor.previous();
                }
            }
            if ("D".equals(command)) {
                if (cursor.hasNext()) {
                    cursor.next();
                }
            }
            if ("B".equals(command)) {
                if (cursor.hasPrevious()) {
                    cursor.previous();
                    cursor.remove();
                }
            }
            if (command.contains("P")) {
                String[] s = command.split(" ");
                cursor.add(s[1].charAt(0));
            }
        }

        for (Character c : editor) {
            bw.write(c);
        }
        bw.flush();
        bw.close();
    }
}
