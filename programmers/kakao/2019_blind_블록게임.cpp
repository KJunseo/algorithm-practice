/*
    가능한 블럭 모양 중 5개만 삭제할 수 있는 블럭이었다.
    ㅗ    __|    |__    |      |
                        |_   _|

    따라서, 우선 board를 순회하다가 0이 아닌 수를 만나면, 위의 5개 모양 중 하나인 지 확인했다.
    그 후 위의 5개 중 하나라면, 각 블럭의 채울 부분 좌표에서 위로 탐색하면서 막혀있는지 여부를 확인하였고,
    막혀있다면 지울 수 없고, 막혀있지 않다면 지워주었다.
    맞는 방법이라고 생각하였지만 65점에서 틀렸다..

    풀이에는 두 가지 방법이 있었다.
    하나는 내가 생각한 방법이고 다른 하나는 아래와 같다.

    보드의 왼쪽 위부터 가로로 진행하면서, 현재 칸이 빈칸이라면, 현재 칸 위쪽에 다른 블럭이있는지 확인한다.
    다른 블럭이 없다면 검은 블럭을 채우고, 다른 블럭이 있다면 빈칸으로 둔다.

    칸을 확인 한 후, 해당 칸을 포함하는 칸 중, 삭제 가능한 블럭을 확인한다.(검은 블럭 2개와, 같은 색 블럭 4개가 직사각형에 포함되는 지 확인)

    블럭을 지운 경우, 지워진 칸을 그대로 둘지, 검은 블럭으로 채울지 확인한다.(블럭이 삭제되었어도 검은 블럭으로 채울 수 없는 경우가 있기 때문에, 지워진 칸을 기준으로 위쪽에 삭제되지 않은 블럭이 있는 지 확인)
    블럭이 삭제되면 answer를 증가시킨다.

    풀이 방법이 똑같았는데, 값이 틀린 것을 보면 어디선가 구현을 잘못한 것 같다..
    + 어디서 잘못되었는지 찾아내어 수정하여 통과했다.
    한 번이라도 블럭이 지워진 경우 처음부터 다시 순회해야한다.(블럭 상태에따라 바뀌기 때문에)
    따라서 처음부터 순회 조건을 넣어주니 통과했다.

    아래에 다른 풀이 방법을 첨부하였다.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool checkUp(vector<vector<int>> &board, queue<pair<int, int> > all, queue<pair<int, int> > coordi, int num) {
    
    while(!coordi.empty()) {
        int y=coordi.front().first;
        int x=coordi.front().second;
        coordi.pop();
        
        int i;
        for(i=y-1;i>=0;i--) {
            if(board[i][x]!=0) {
                return false;
            }
        } 
    }
    
    while(!all.empty()) {
        int y=all.front().first;
        int x=all.front().second;
        all.pop();
        
        board[y][x]=0;
    }
    return true;
}

bool checkShape(vector<vector<int>> &board, int num, int y, int x) {
    int row=board.front().size();
    int col=board.size();
    queue<pair<int, int> > all;
    queue<pair<int, int> > coordi;
    
    if(y+1<col && board[y+1][x]==num) {
        all.push(make_pair(y, x));
        all.push(make_pair(y+1, x));

        if(x+2<row && board[y+1][x+1]==num && board[y+1][x+2]==num) {
            coordi.push(make_pair(y+1, x+1));
            coordi.push(make_pair(y+1, x+2));
            all.push(make_pair(y+1, x+1));
            all.push(make_pair(y+1, x+2));

            if(checkUp(board, all, coordi, num)) {
                return true;
            }
        }
        if(x-2>=0 && board[y+1][x-1]==num && board[y+1][x-2]==num) {
            coordi.push(make_pair(y+1, x-1));
            coordi.push(make_pair(y+1, x-2));
            all.push(make_pair(y+1, x-1));
            all.push(make_pair(y+1, x-2));

            if(checkUp(board, all, coordi, num)) {
                return true;
            }
        }
        if(y+2<col) {
            if(x-1>=0&& board[y+2][x]==num && board[y+2][x-1]==num) { 
                coordi.push(make_pair(y+2, x-1));
                all.push(make_pair(y+2, x));
                all.push(make_pair(y+2, x-1));
                
                if(checkUp(board, all, coordi, num)) {
                    return true;
                }
            }
            if(x+1<row&& board[y+2][x]==num && board[y+2][x+1]==num) { 
                coordi.push(make_pair(y+2, x+1));
                all.push(make_pair(y+2, x));
                all.push(make_pair(y+2, x+1));

                if(checkUp(board, all, coordi, num)) {
                    return true;
                } 
            }
        }
        if(x-1>=0 && x+1<row && board[y+1][x-1]==num && board[y+1][x+1]==num) {
            coordi.push(make_pair(y+1, x+1));                
            coordi.push(make_pair(y+1, x-1));
            all.push(make_pair(y+1, x+1));
            all.push(make_pair(y+1, x-1));

            if(checkUp(board, all, coordi, num)) {
                return true;
            }
        }           
    }
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(board[i][j]!=0) {
                if(checkShape(board, board[i][j], i, j)) {
                    i=0;
                    j=0;
                    answer++;
                }
            }
        }
    }
    
    return answer;
}


// 다른 풀이 방법(더 깔끔하고, 빠르다)
int N;
vector<vector<int> > Board;

// 채울 수 있는 지 확인(현재 위치 바로 위까지 모두 비어있는 지 확인)
bool canFill(int row, int col) {
    for(int i=0;i<row;i++) {
        if(Board[i][col]!=0) return false;
    }
    return true;
}

// 2*3 or 3*2 크기의 직사각형 내부 탐색 
bool find(int row, int col, int h, int w) {
    int emptyCnt=0;
    int lastValue=-1;

    for(int r=row;r<row+h;r++) {
        for(int c=col;c<col+w;c++) {
            if(Board[r][c]==0) {
                if(!canFill(r, c)) return false;
                emptyCnt++;
                if(emptyCnt>2) return false;
            } else {
                if(lastValue!=-1 && lastValue!=Board[r][c]) return false;
                lastValue=Board[r][c];
            }
        }
    }

    for(int r=row;r<row+h;r++) {
        for(int c=col;c<col+w;c++) {
            Board[r][c]=0;
        }
    }

    return true;
}

int solution(vector<vector<int>> board) {
    Board = board; // 글로벌 변수로 사용하기 위함
    N=board.size();
    int answer = 0;
    int cnt;

    do {
        cnt=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(i<=N-2 && j<=N-3 && find(i, j, 2, 3)) {
                    cnt++;
                } else if(i<=N-3 && j<=N-2 && find(i, j, 3, 2)) {
                    cnt++;
                }
            }
        }
        answer+=cnt;

    } while(cnt);

    return answer;
}