package 기초코드작성요령;

import java.io.*;
import java.util.StringTokenizer;

public class 카드역배치_10804 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        for (int i = 0; i < 10; i++) {
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input, " ");
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            cards = reverse(cards, start - 1, end - 1);
        }

        for (int card : cards) {
            bw.write(card + " ");
        }

        bw.flush();
        bw.close();
    }

    private static int[] reverse(int[] cards, int start, int end) {
        int[] newCards = new int[cards.length];

        for (int i = 0; i < start; i++) {
            newCards[i] = cards[i];
        }

        for (int i = end + 1; i < cards.length; i++) {
            newCards[i] = cards[i];
        }

        for (int i = start, cnt = 0; i <= end; i++, cnt++) {
            newCards[i] = cards[end - cnt];
        }

        return newCards;
    }
}
