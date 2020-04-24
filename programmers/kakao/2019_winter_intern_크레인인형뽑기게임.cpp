/*
    분명 더 효율적인 방법이 있을 것 같긴 했지만 풀긴 풀었다.(+3점..)

    인형 뽑기 기계의 세로줄을 기준으로, 인형들을 각각 벡터에 집어넣었다.
    그 후, moves를 차례로 돌면서 각 벡터의 맨 위의 값을 basket에 넣고,
    만약 똑같은 값이면 answer+2를 해주었다.

    board를 새로운 벡터에 안 넣어주고도, 바로 비교해서 풀이할 수도 있다.
*/
#include <string>
#include <vector>

#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> machine[board.size()];
    vector<int> basket;
    
    // 인형뽑기 기계를 세로줄을 기준으로 벡터에 집어넣음 
    for(int i=board.size()-1;i>=0;i--) {
        for(int j=board[i].size()-1;j>=0;j--) {
            if(board[j][i]!=0) machine[i].push_back(board[j][i]);
        }
    }
    
    for(int i=0;i<moves.size();i++) {
        if(machine[moves[i]-1].size()==0) continue; // 꺼낼 인형이 없는 경우 스킵

        int position=machine[moves[i]-1].back(); // 현재 위치의 인형
        machine[moves[i]-1].pop_back();
        
        // 젤 처음은 무조건 집어넣음
        if(i==0) {
            basket.push_back(position);
            continue;
        }
        
        // 같은 인형일 경우 인형 제거
        if(basket.back()==position) {
            answer+=2;
            basket.pop_back();
        } else {
            basket.push_back(position);
        }
    }
    
    return answer;
}

// 다른 풀이 
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    for(int i=0;i<moves.size();i++) {
        int position = moves[i]-1;

        for(int j=0;j<board.size();j++) {
            if(board[j][position]!=0) {
                if(!s.empty() && s.top() == board[j][position]) {
                    s.pop();
                    answer+=2;
                } else s.push(board[j][position]);

                board[j][position]=0;
                break;
            }
        }
    }

    return answer;
}
