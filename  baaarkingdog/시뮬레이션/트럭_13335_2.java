package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 트럭_13335_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, w, l;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Queue<Integer> truck = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            truck.add(Integer.parseInt(st.nextToken()));
        }

        Queue<Integer> bridge = new LinkedList<>();
        for (int i = 0; i < w; i++) {
            bridge.add(0);
        }

        int currentWeight = 0;
        int time = 0;
        while (!bridge.isEmpty()) {
            currentWeight -= bridge.poll();

            if (!truck.isEmpty()) {
                if (currentWeight + truck.peek() <= l) {
                    currentWeight += truck.peek();
                    bridge.add(truck.poll());
                } else {
                    bridge.add(0);
                }
            }
            time++;
        }

        System.out.println(time);
    }
}
