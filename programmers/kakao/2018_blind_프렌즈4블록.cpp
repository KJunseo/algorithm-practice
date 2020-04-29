/*
    복잡한 구현 문제였다.
    board를 순회하면서, 4개 블럭을 만나면, 방문처리를 하고, 더해주었다.
    그 후 방문한 블럭들의 갯수만큼 answer을 증가시키고, 방문한 블럭들을 삭제해주었다.
    풀긴 했지만, 시간이 엄청 오래 걸렸다. 

    효율적인 코드를 밑에 추가하였다.
*/

// 직접 구현한 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void boardErase(vector<string> &board, vector<vector<bool> > &check, int m, int n) {
    queue<char> temp;
    
    for(int j=0;j<n;j++) {
        for(int i=m-1;i>=0;i--) {
            if(!check[i][j]) {
                temp.push(board[i][j]);
            }
        }
        for(int i=m-1;i>=0;i--) {
            char c=' '; 
            if(!temp.empty()) {
                c=temp.front();
                temp.pop();
            }

            board[i][j]=c;
        }
    }
    
    for(int i=0;i<check.size();i++) {
        for(int j=0;j<check[i].size();j++) {
            check[i][j]=false;
        }
    }
    
}

bool checkDelete(vector<string> board, int m, int n, vector<vector<bool> > &check) {
    char temp = board[m][n];
    vector<vector<bool> > tempCheck;
    
    tempCheck=check;
    
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            if(board[m+i][n+j]!=' ') {
                if(board[m+i][n+j]!=temp) {
                    check=tempCheck;
                    return false;
                }
                check[m+i][n+j]=true;
            } else {
                check=tempCheck;
                return false;
            }
        }
    }
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag=false;
    vector<vector<bool> > check(m, vector<bool>(n, false));
    vector<vector<bool> > temp;
    
    temp=check;
    
    while(true){
        flag=false;
        for(int i=0;i<m-1;i++) {
            for(int j=0;j<n-1;j++) {
                if(checkDelete(board, i, j, check)) {  
                    flag=true;
                    temp=check;
                }
            }
        }
        
        if(!flag) break;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(check[i][j]) answer++;
            }
        }
        
        boardErase(board, check, m, n);
        temp=check;
    }
    
    return answer;
}


// 간단한 풀이(훨씬 효율적인 결과)
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag = false;

	while (!flag) {
		vector<vector<bool>> check(m, vector<bool>(n, false));
		flag = true;

		for (int i = 0; i <m-1;i++) {
			for (int j = 0; j < n - 1; j++) {
                char current=board[i][j];

                // 없는 블럭이면 건너뛰기
				if (board[i][j]==0)
					continue;

                // 방문처리
				if (current==board[i][j+1] && current==board[i+1][j] && current==board[i+1][j+1]) {
					check[i][j] = true;
					check[i][j+1] = true;
					check[i+1][j] = true;
					check[i+1][j+1] = true;
					flag = false;
				}
			}
		}

		for (int i=0;i<m;i++) {
			for (int j=0;j<n;j++) {
				if (check[i][j]) {
					answer++;
					for (int k=i-1;k>=0;k--) {
						board[k+1][j] = board[k][j]; // 한 칸 내리기 
						board[k][j] = 0; // 삭제 
					}
				}
			}
		}

	}

	return answer;
}