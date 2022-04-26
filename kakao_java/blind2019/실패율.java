package blind2019;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 실패율 {
    private int[] clear;
    private int[] stage;

    public int[] solution(int N, int[] stages) {
        clear = new int[N];
        stage = new int[N];

        for (int s : stages) {
            if (s == N + 1) {
                for (int i = 0; i < N; i++) {
                    stage[i]++;
                    clear[i]++;
                }
            } else {
                for (int i = 0; i < s; i++) {
                    stage[i]++;
                    if (i >= 1) {
                        clear[i - 1]++;
                    }
                }
            }
        }

        List<Stage> stageList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            stageList.add(new Stage(i + 1, clear[i], stage[i]));
        }

        Collections.sort(stageList);

        int[] answer = new int[N];
        for (int i = 0; i < N; i++) {
            answer[i] = stageList.get(i).id;
        }

        return answer;
    }

    static class Stage implements Comparable<Stage> {
        int id;
        int clear;
        int stage;
        double failureRate;

        public Stage(int id, int clear, int stage) {
            this.id = id;
            this.clear = clear;
            this.stage = stage;
            if (stage == 0) {
                this.failureRate = 0;
            } else {
                this.failureRate = (double) (stage - clear) / stage;
            }
        }

        @Override
        public int compareTo(Stage o) {
            return Double.compare(o.failureRate, this.failureRate);
        }
    }
}
