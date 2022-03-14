package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 치킨배달_15686 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, m;
    private static List<Location> shops;
    private static List<Location> homes;
    private static Location[] selected;

    private static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        shops = new ArrayList<>();
        homes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int temp = Integer.parseInt(st.nextToken());

                if (temp == 1) {
                    homes.add(new Location(i, j));
                }
                if (temp == 2) {
                    shops.add(new Location(i, j));
                }
            }
        }

        selected = new Location[m];
        dfs(0, 0);

        System.out.println(answer);
    }

    private static void dfs(int start, int shopCount) {
        if (shopCount == m) {
            int dist = 0;
            for (Location home : homes) {
                int temp = Integer.MAX_VALUE;
                for (int i = 0; i < m; i++) {
                    Location shop = selected[i];
                    temp = Math.min(temp, Math.abs(home.x - shop.x) + Math.abs(home.y - shop.y));
                }
                dist += temp;
            }

            answer = Math.min(answer, dist);

            return;
        }

        for (int i = start; i < shops.size(); i++) {
            selected[shopCount] = shops.get(i);
            dfs(i + 1, shopCount + 1);
        }
    }
}

class Location {
    int x;
    int y;

    public Location(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
