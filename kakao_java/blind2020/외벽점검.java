package blind2020;

public class 외벽점검 {
    private int n;
    private int[] weak;
    private int[] dist;
    private int[] linear;

    private int answer = Integer.MAX_VALUE;
    private boolean finish = false;

    public int solution(int n, int[] weak, int[] dist) {
        this.n = n;
        this.weak = weak;
        this.dist = dist;
        circleToLinear();

        for (int i = 1; i <= dist.length; i++) {
            permutation(0, i, new boolean[dist.length], new int[i]);
        }

        if (answer == Integer.MAX_VALUE) {
            answer = -1;
        }
        return answer;
    }

    private void permutation(int depth, int count, boolean[] visited, int[] result) {
        if (finish) {
            return;
        }

        if (depth == count) {
            checkInspectionOver(result);
            return;
        }

        for (int i = 0; i < dist.length; i++) {
            if (visited[i]) {
                continue;
            }
            result[depth] = dist[i];
            visited[i] = true;
            permutation(depth + 1, count, visited, result);
            visited[i] = false;
        }
    }

    private void checkInspectionOver(int[] friends) {
        for (int start = 0; start < weak.length; start++) {
            int cur = start;
            boolean flag = true;

            for (int i = 0; i < friends.length; i++) {
                for (int j = start; j < start + weak.length; j++) {

                    if (linear[j] - linear[cur] > friends[i]) {
                        cur = j;
                        i++;

                        if (i == friends.length) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag) {
                    answer = i + 1;
                    finish = true;
                    return;
                }
            }
        }
    }

    private void circleToLinear() {
        linear = new int[weak.length * 2];
        for (int i = 0; i < weak.length; i++) {
            linear[i] = weak[i];
            linear[i + weak.length] = weak[i] + n;
        }
    }
}
