/*
    +1점
    min_element를 사용해서 가장 작은 값을 찾고
    arr를 순회하며 가장작은 값을 제외한 값들만 answer에 추가했다.
*/
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=*min_element(arr.begin(), arr.end());
    
    for(int i=0;i<arr.size();i++) {
        if(arr[i]==min) continue;
        answer.push_back(arr[i]);
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}