/*
    3점으로 풀었다. 자바로 풀려니 익숙하지 않아 힘들다.
    4차원 배열을 만들어서 시작점 끝점을 기준으로 방문 체크를 한다.(양방향 모두 체크해준다. -> 똑같은 길이기 때문에)
    5,5를 시작 지점으로 명령어에 따라 y, x 좌표를 옮겨주면서, 범위를 벗어나는 지 체크하고, 이미 방문했는지도 체크한다.
*/

class 방문길이 {
    final int SIZE = 11;
    boolean board [][][][] = new boolean[SIZE][SIZE][SIZE][SIZE]; // 방문 체크를 위한 배열 
    
    // 범위를 벗어나는지 확인하기 위한 배열 
    public boolean check(int y, int x) {
        return (x>=0 && x<SIZE) && (y>=0 && y<SIZE);
    }

    public int solution(String dirs) {
        int answer = 0;
        String[] go = dirs.split(""); // 문자열 한 글자씩 나누기 
        
        // 시작 지점 
        int x=5;
        int y=5;
        for(int i=0;i<go.length;i++) {
            String d=go[i];

            if(d.equals("U")) {
                if(check(y-1, x)) {
                    if(!board[y][x][y-1][x]) {
                        board[y][x][y-1][x]=true;
                        board[y-1][x][y][x]=true;
                        answer++;                        
                    }
                    y=y-1;
                }
            } else if(d.equals("D")) {
                if(check(y+1, x)) {
                    if(!board[y][x][y+1][x]) {
                        board[y][x][y+1][x]=true;
                        board[y+1][x][y][x]=true;
                        answer++;   
                    }
                    y=y+1;
                }
            } else if(d.equals("R")) {
                if(check(y, x+1)) {
                    if(!board[y][x][y][x+1]) {
                         board[y][x][y][x+1]=true;
                        board[y][x+1][y][x]=true;
                        answer++;                   
                    }
                    x=x+1;
                }
            } else if(d.equals("L")) {
                if(check(y, x-1)) {
                    if(!board[y][x][y][x-1]) {
                        board[y][x][y][x-1]=true;
                        board[y][x-1][y][x]=true;
                        answer++;                    
                    }
                    x=x-1;
                }
            }
        }
        
        return answer;
    }
}
