package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 연산자끼워넣기_14888 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[] array;
    private static char[] op = {'+', '-', '*', '/'};
    private static List<Character> operators;
    private static boolean[] visited;

    private static int max = Integer.MIN_VALUE;
    private static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        operators = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int num = Integer.parseInt(st.nextToken());
            for (int j = 0; j < num; j++) {
                operators.add(op[i]);
            }
        }

        visited = new boolean[operators.size()];
        dfs(array[0], 1);

        System.out.println(max);
        System.out.println(min);
    }

    private static void dfs(int num, int numIndex) {
        if (numIndex >= array.length) {
            max = Math.max(max, num);
            min = Math.min(min, num);
            return;
        }

        for (int i = 0; i < operators.size(); i++) {
            if (visited[i]) {
                continue;
            }
            Character c = operators.get(i);

            visited[i] = true;
            dfs(calculate(num, c, array[numIndex]), numIndex + 1);
            visited[i] = false;
        }
    }

    private static int calculate(int cur, Character op, int next) {
        if (op == '+') {
            return cur + next;
        } else if (op == '-') {
            return cur - next;
        } else if (op == '*') {
            return cur * next;
        } else {
            return cur / next;
        }
    }
}
