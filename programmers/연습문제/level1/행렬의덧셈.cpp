/*
    +1점
    행과 열의 크기가 같기 때문에 둘 중 아무 사이즈를 기준으로 잡고 동일한 위치를 참조하면서 더해주면 된다.
*/
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0;i<arr1.size();i++) {
        vector<int> temp;
        for(int j=0;j<arr1[i].size();j++) {
            temp.push_back(arr1[i][j]+arr2[i][j]);
        }
        answer.push_back(temp);
    }
    
    return answer;
}