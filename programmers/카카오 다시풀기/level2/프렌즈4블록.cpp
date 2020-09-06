/*
    처음에 문제를 잘못 이해해서 잘못 구현을 했다.
    시뮬레이션 문제였다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    
    while(flag) {
        vector<vector<bool> > visited(m, vector<bool>(n, false)); // 방문 처리 
        flag = false;
        
        // 블럭 작동 
        for(int i = 0; i < m-1; i++) {
            for(int j = 0; j < n-1; j++) {
                char block = board[i][j];
                
                if(board[i][j] == ' ') continue;
                
                if(block == board[i][j+1] && 
                  block == board[i+1][j] && 
                  block == board[i+1][j+1]) {
                    visited[i][j] = true;
                    visited[i][j+1] = true;
                    visited[i+1][j] = true;
                    visited[i+1][j+1] = true;
                    flag = true;
                }
            }
        }
        
        // 삭제된 블럭 수 세기 
        // 삭제된 블럭 내리기
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) {
                    answer++;
                    
                    // 한 칸 내리기
                    for(int k = i-1; k >= 0; k--) {
                        board[k+1][j] = board[k][j]; 
                        board[k][j] = ' ';
                    }
                }
            }
        }
    }
    
    return answer;
}