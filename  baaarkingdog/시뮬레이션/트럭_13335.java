package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 트럭_13335 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, w, l;
    private static int[] truck;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        truck = new int[n];
        for (int i = 0; i < n; i++) {
            truck[i] = Integer.parseInt(st.nextToken());
        }

        Bridge bridge = new Bridge();

        int time = 0;
        int truckIndex = 0;
        while (truckIndex < n || !bridge.isEmpty()) {
            if (truckIndex >= n) {
                bridge.go();
                time++;
                continue;
            }

            if (bridge.canMount(truck[truckIndex])) {
                bridge.mount(truck[truckIndex++]);
            } else {
                bridge.go();
            }
            time++;
        }

        System.out.println(time);
    }

    static class Bridge {
        int[] space;
        int currentWeight;
        int L;

        public Bridge() {
            this.space = new int[w];
            this.currentWeight = 0;
            this.L = l;
        }

        public boolean canMount(int truck) {
            return currentWeight - space[w - 1] + truck <= L;
        }

        public void mount(int truck) {
            go();
            space[0] = truck;
            currentWeight += truck;
        }

        public void go() {
            currentWeight -= space[w - 1];
            for (int i = w - 1; i > 0; i--){
                space[i] = space[i - 1];
            }
            space[0] = 0;
        }

        public boolean isEmpty() {
            return currentWeight == 0;
        }
    }
}
