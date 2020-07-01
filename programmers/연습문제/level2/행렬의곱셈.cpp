/*
    쉽게 풀 줄 알았는데 생각보다 헷갈렸다.
    
    행렬의 곱셈이 가능하려면 첫 번째 행렬의 열의 수와 두 번째 행렬의 행의 수가 같아야한다. 

    for(int i=0;i<행렬 A의 행의 갯수;i++) {
        for(int j=0;j<행렬 B의 열의 갯수;j++) {
            for(int k=0;k<행렬 B의 행의 갯수 || 행렬 A의 열의 갯수;k++) { 

            }
        }
    }
*/
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0;i<arr1.size();i++) {
        vector<int> temp;
        int sum=0;
        for(int j=0;j<arr2[0].size();j++) {
            sum=0;
            for(int k=0;k<arr2.size();k++) {
                sum+=arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    
    return answer;
}