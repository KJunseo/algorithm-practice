package blind2018;

public class N진수게임 {

    public String solution(int n, int t, int m, int p) {
        String answer = "";

        int num = 0;
        int turn = 1;
        while (t > 0) {
            String cur = changeToN(num, n);

            for (int i = 0; i < cur.length(); i++) {
                char c = cur.charAt(i);
                if (turn > m) {
                    turn -= m;
                }
                if (turn == p) {
                    if (t == 0) {
                        break;
                    }
                    answer += c;
                    t--;
                }
                turn++;
            }
            num++;
        }

        return answer;
    }

    private String changeToN(int num, int n) {
        StringBuilder result = new StringBuilder();

        while (num > 0) {
            int temp = num % n;
            if (temp == 10) {
                result.append("A");
            } else if (temp == 11) {
                result.append("B");
            } else if (temp == 12) {
                result.append("C");
            } else if (temp == 13) {
                result.append("D");
            } else if (temp == 14) {
                result.append("E");
            } else if (temp == 15) {
                result.append("F");
            } else {
                result.append(temp);
            }
            num /= n;
        }

        String s = result.reverse().toString();

        if (s.equals("")) {
            return "0";
        }

        return s;
    }
}
