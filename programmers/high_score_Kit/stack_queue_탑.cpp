/*
    주어진 벡터를 이용하여 스택처럼 사용하였다.
    오른쪽 부터 탐색하여, answer에 요소를 추가해주었다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> height) {
    vector<int> answer;
    
    while(height.size()!=0) {
        int temp = height.back();
        height.pop_back();
        
        int i;
        for(i=height.size()-1;i>=0;i--) {
            if(height[i]>temp) {
                answer.push_back(i+1);
                break;
            }
            if(i==0) {
                answer.push_back(0);
            }
        }
    }

    answer.push_back(0); // 제일 처음은 항상 0 

    reverse(answer.begin(), answer.end());
    
    return answer;
}