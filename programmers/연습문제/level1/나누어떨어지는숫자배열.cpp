/*
    역시 +1점..
    그냥 모든 배열을 순회하면서 나눌 수 있는 경우만 벡터에 추가해주고
    벡터 사이즈가 0이면 -1을 넣고 아니라면 sort해줬다.
*/
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++) {
        if(arr[i]%divisor==0) answer.push_back(arr[i]);
    }
    
    if(answer.size()==0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}