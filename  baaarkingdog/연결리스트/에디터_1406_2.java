package 연결리스트;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

public class 에디터_1406_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        List<Character> editor = Arrays.stream(input.split(""))
                                              .map(s -> s.charAt(0))
                                              .collect(Collectors.toCollection(LinkedList::new));

        ListIterator<Character> cursor = editor.listIterator();

        while (cursor.hasNext()) {
            cursor.next();
        }

        int count = Integer.parseInt(br.readLine());
        for (int i = 0; i < count; i++) {
            String command = br.readLine();

            if (command.contains("P")) {
                String c = command.split(" ")[1];
                cursor.add(c.charAt(0));
            }
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
        }

        for (Character c : editor) {
            bw.write(c);
        }
        bw.flush();
        bw.close();

    }
}
