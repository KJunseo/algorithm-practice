package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 스타트와링크_14889_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] ability;
    private static boolean[] check;
    private static int answer = Integer.MAX_VALUE;

    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        ability = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                ability[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        check = new boolean[n];
        dfs(0, 0);

        System.out.println(answer);
    }

    private static void dfs(int player, int numOfMember) {
        if (numOfMember == n / 2) {
            List<Integer> start = new ArrayList<>();
            List<Integer> link = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (check[i]) {
                    start.add(i);
                } else {
                    link.add(i);
                }
            }

            int startTeamAbility = teamAbility(start);
            int linkTeamAbility = teamAbility(link);

            int diff = Math.abs(startTeamAbility - linkTeamAbility);

            answer = Math.min(answer, diff);
            return;
        }

        for (int i = player; i < n; i++) {
            if (check[i]) {
                continue;
            }
            check[i] = true;
            dfs(i + 1, numOfMember + 1);
            check[i] = false;
        }
    }

    private static int teamAbility(List<Integer> team) {
        int teamAbility = 0;
        for (int i = 0; i < team.size(); i++) {
            for (int j = 0; j < team.size(); j++) {
                int player1 = team.get(i);
                int player2 = team.get(j);

                teamAbility += ability[player1][player2];
            }
        }
        return teamAbility;
    }
}
