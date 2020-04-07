/*
    그냥 commands의 수만큼 반복하면서 array를 잘라 정렬 후 answer 벡터에 넣어주면 되는 문제였다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++) {
        int start=commands[i][0];
        int end=commands[i][1];
        int target=commands[i][2];
        vector<int> temp;
        
        for(int j=start-1;j<=end-1;j++) {
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[target-1]);
    }
    
    return answer;
}