package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 스타트와링크_14889 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static int[][] ability;
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

        List<Integer> startTeam = new ArrayList<>();
        List<Integer> linkTeam = new ArrayList<>();
        dfs(0, startTeam, linkTeam);

        System.out.println(answer);
    }

    private static void dfs(int player, List<Integer> startTeam, List<Integer> linkTeam) {
        if (player == n) {
            if (startTeam.size() == n / 2 && linkTeam.size() == n / 2) {
                int startTeamAbility = 0;
                int linkTeamAbility = 0;
                for (int i = 0; i < n / 2; i++) {
                    for (int j = i + 1; j < n / 2; j++) {
                        int s1 = startTeam.get(i);
                        int s2 = startTeam.get(j);
                        int l1 = linkTeam.get(i);
                        int l2 = linkTeam.get(j);

                        startTeamAbility += ability[s1][s2];
                        startTeamAbility += ability[s2][s1];
                        linkTeamAbility += ability[l1][l2];
                        linkTeamAbility += ability[l2][l1];
                    }
                }

                int diff = Math.abs(startTeamAbility - linkTeamAbility);

                answer = Math.min(answer, diff);
            }
            return;
        }

        startTeam.add(player);
        dfs(player + 1, startTeam, linkTeam);
        startTeam.remove(new Integer(player));

        linkTeam.add(player);
        dfs(player + 1, startTeam, linkTeam);
        linkTeam.remove(new Integer(player));
    }
}
