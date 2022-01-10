package 연결리스트;

import java.io.*;
import java.util.LinkedList;
import java.util.List;

public class 요세푸스문제_1158 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        String[] s = input.split(" ");

        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);

        List<Integer> circle = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            circle.add(i);
        }

        int index = k - 1;
        System.out.print("<");
        while (!circle.isEmpty()) {
            while (index >= circle.size()) {
                index = index - circle.size();
            }
            Integer removedPerson = circle.remove(index);
            System.out.print(removedPerson);

            index = index + k - 1;
            if (!circle.isEmpty()) {
                System.out.print(", ");
            }
        }
        System.out.print(">");
    }
}
