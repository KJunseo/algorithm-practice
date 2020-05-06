/*
    배열을 회전시키면서, 가능한 모든 경우 탐색하면서, 자물쇠에 모든 홈을 채울 수 있다면 true 
    lock을 가로 세로 길이가 3배인 배열의 중앙으로 옮긴 후, key 배열을 새로운 배열의 처음부터 겹치는 부분만 확인 

    key를 회전시키면서 찾아보려고 하였으나, 크기3배인 배열을 만들어 하는 부분을 생각하지 못했었다.
*/
#include <string>
#include <vector>

using namespace std;

int keySize;
int lockSize;
int boardSize;

// 오른쪽으로 90도 회전 
void rotate(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=key[m-j-1][i];
        }
    }
    key=temp;
}

// 자물쇠를 열 수 있는지 확인
bool match(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for(int i=x;i<x+keySize;i++) {
        for(int j=y;j<y+keySize;j++) {
            board[i][j]+=key[i-x][j-y];
        }
    }
    
    for(int i=lockSize;i<boardSize-lockSize;i++) {
        for(int j=lockSize;j<boardSize-lockSize;j++) {
            if (board[i][j]==1) continue;
 
            return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keySize=key.size();
    lockSize=lock.size();
    boardSize=lockSize*3;
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    
    // 크기가 3배인 배열을 만들어 자물쇠를 중앙에 배치 
    for(int i=lockSize;i<boardSize-lockSize;i++) {
        for(int j=lockSize;j<boardSize-lockSize;j++) {
            board[i][j]=lock[i-lockSize][j-lockSize];
        }
    }
    
    // 오른쪽 회전 시키면서, key가 갈 수 있는 모든 경우를 대입
    for(int i=0;i<4;i++) {
        for(int i=0;i<=boardSize-keySize;i++) {
            for(int j=0;j<=boardSize-keySize;j++) {
                if(match(i, j, key, board)) {
                    return true;
                }
            }
        }
        rotate(key);
    }
    
    return false;
}