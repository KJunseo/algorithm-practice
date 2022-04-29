package blind2021;

import java.util.*;

public class 카드짝맞추기 {
    private static final int SIZE = 4;

    private int[] dx = {-1, 0, 1, 0};
    private int[] dy = {0, 1, 0, -1};

    private List<String> orders;
    private Set<Integer> characters;
    private int count;

    public int solution(int[][] board, int r, int c) {
        this.characters = new HashSet<>();
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 0) {
                    characters.add(board[i][j]);
                }
            }
        }

        orders = new ArrayList<>();
        permutation("", 0);

        int answer = Integer.MAX_VALUE;
        int originalR = r;
        int originalC = c;
        for (String order : orders) {
            count = 0;
            int[][] temp = copyBoard(board);
            r = originalR;
            c = originalC;

            for (String character : order.split("")) {
                int num = Integer.parseInt(character);

                int[] card1 = findCard(num, r, c, temp);
                temp[card1[0]][card1[1]] = 0;
                count++; // enter

                int[] card2 = findCard(num, card1[0], card1[1], temp);
                temp[card2[0]][card2[1]] = 0;
                count++; // enter

                r = card2[0];
                c = card2[1];
            }

            answer = Math.min(answer, count);
        }

        return answer;
    }

    private int[] findCard(int character, int r, int c, int[][] board) {
        Queue<Node> queue = new LinkedList<>();
        boolean[][] visited = new boolean[SIZE][SIZE];
        visited[r][c] = true;
        queue.add(new Node(r, c, 0));

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            if (board[node.x][node.y] == character) {
                count += node.cnt;
                return new int[]{node.x, node.y};
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = node.x + dx[dir];
                int ny = node.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                queue.add(new Node(nx, ny, node.cnt + 1));
            }

            for (int dir = 0; dir < 4; dir++) {
                int[] next = getNextPosition(node.x, node.y, dir, board);
                int nx = next[0];
                int ny = next[1];

                if (nx == node.x && ny == node.y) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                queue.add(new Node(nx, ny, node.cnt + 1));
            }
        }

        return new int[2];
    }

    private int[] getNextPosition(int x, int y, int dir, int[][] board) {
        x += dx[dir];
        y += dy[dir];

        while (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (board[x][y] != 0) {
                return new int[]{x, y};
            }
            x += dx[dir];
            y += dy[dir];
        }

        return new int[]{x - dx[dir], y - dy[dir]};
    }

    private int[][] copyBoard(int[][] board) {
        int[][] temp = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp[i][j] = board[i][j];
            }
        }
        return temp;
    }

    private void permutation(String cur, int depth) {
        if (characters.size() == depth) {
            orders.add(cur);
            return;
        }

        for (Integer integer : new ArrayList<>(characters)) {
            String character = String.valueOf(integer);
            if (cur.contains(character)) {
                continue;
            }
            permutation(cur + character, depth + 1);
        }
    }

    static class Node {
        int x;
        int y;
        int cnt;

        public Node(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}
