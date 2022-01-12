package 스택;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class 탑_2493 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        String input = br.readLine();
        int[] heights = Arrays.stream(input.split(" "))
                                 .mapToInt(Integer::parseInt)
                                 .toArray();

        Stack<Tower> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            int height = heights[i];

            while (!stack.isEmpty()) {
                Tower tower = stack.pop();

                if (tower.isHigh(height)) {
                    sb.append(tower.getId() + 1).append(" ");
                    stack.push(tower);
                    break;
                }
            }

            if (stack.isEmpty()) {
                sb.append("0 ");
            }
            stack.push(new Tower(i, height));
        }

        System.out.println(sb);
    }
}

class Tower {
    private int id;
    private int height;

    public Tower(int id, int height) {
        this.id = id;
        this.height = height;
    }

    public boolean isHigh(int height) {
        return this.height >= height;
    }

    public int getId() {
        return id;
    }
}
