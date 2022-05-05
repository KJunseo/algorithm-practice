package intern2021;

import java.util.LinkedList;
import java.util.Queue;

public class 거리두기확인하기 {
    private int[] dx = {-1, 0, 1, 0};
    private int[] dy = {0, 1, 0, -1};

    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for (int i = 0; i < 5; i++) {
            char[][] map = makeMap(places[i]);
            answer[i] = checkDistancing(map);
        }

        return answer;
    }

    private int checkDistancing(char[][] map) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i][j] == 'P') {
                    if (!bfs(map, i, j)) {
                        return 0;
                    }
                }
            }
        }

        return 1;
    }

    private boolean bfs(char[][] map, int x, int y) {
        boolean[][] visited = new boolean[5][5];
        Queue<Node> queue = new LinkedList<>();
        visited[x][y] = true;
        queue.add(new Node(x, y));

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.x + dx[dir];
                int ny = node.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                int dist = Math.abs(x - nx) + Math.abs(y - ny);
                if (dist > 2) {
                    continue;
                }

                if (map[nx][ny] == 'P') {
                    return false;
                }
                if (map[nx][ny] == 'O') {
                    visited[nx][ny] = true;
                    queue.add(new Node(nx, ny));
                }
            }

        }

        return true;
    }

    private char[][] makeMap(String[] place) {
        char[][] map = new char[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = place[i].charAt(j);
            }
        }
        return map;
    }

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
