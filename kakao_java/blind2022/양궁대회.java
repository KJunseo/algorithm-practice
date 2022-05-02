package blind2022;

import java.util.Arrays;

public class 양궁대회 {
    private int[] arrows = new int[12];
    private int[] min = new int[12];

    // 백트래킹
    public int[] solution(int n, int[] info) {
        Arrays.fill(min, -1);
        dfs(0, n, info);

        if (min[0] == -1) {
            return new int[]{-1};
        }

        int[] answer = new int[11];
        for (int i = 0; i < 11; i++) {
            answer[i] = min[i];
        }

        return answer;
    }

    private void dfs(int index, int remain, int[] info) {
        if (index == 10) {
            arrows[index] = remain;
            int score = 0;

            for (int i = 0; i <= 10; i++) {
                if (arrows[i] > info[i]) {
                    score += (10 - i);
                } else if (info[i] != 0) {
                    score -= (10 - i);
                }
            }

            if (score <= 0) {
                return;
            }

            arrows[11] = score;

            if (cmp(arrows, min)) {
                for (int i = 0; i < 12; i++) {
                    min[i] = arrows[i];
                }
            }
            return;
        }

        for (int i = 0; i <= remain; i++) {
            arrows[index] = i;
            dfs(index + 1, remain - i, info);
        }
    }

    // 그리디
    public int[] solution2(int n, int[] info) {
        int[] min = new int[12];
        Arrays.fill(min, -1);

        for (int i = 0; i < (1 << 10); i++) {
            int[] arrows = new int[12];
            int score = 0;
            int remain = n;

            for (int j = 0; j < 10; j++) {
                if ((i & (1 << j)) != 0) {
                    score += (10 - j);
                    remain -= (info[j] + 1);
                    arrows[j] = info[j] + 1;
                } else if (info[j] != 0) {
                    score -= (10 - j);
                }
            }

            if (score <= 0 || remain < 0) {
                continue;
            }

            arrows[10] = remain;
            arrows[11] = score;

            if (cmp(arrows, min)) {
                for (int j = 0; j < 12; j++) {
                    min[j] = arrows[j];
                }
            }
        }

        if (min[0] == -1) {
            return new int[]{-1};
        }

        int[] answer = new int[11];
        for (int i = 0; i < 11; i++) {
            answer[i] = min[i];
        }

        return answer;
    }

    private boolean cmp(int[] arrows, int[] answer) {
        for (int i = 11; i >= 0; i--) {
            if (arrows[i] != answer[i]) {
                return arrows[i] > answer[i];
            }
        }
        return false;
    }
}
