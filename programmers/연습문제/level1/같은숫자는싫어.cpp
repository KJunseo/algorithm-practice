/*
    효율적인 생각을 못하는건가 계속 1점을 얻는다. 
    이전값을 계속 업데이트하면서 같지 않을 때만 추가해주었다

    erase & unique를 사용하면 한 줄로도 풀 수 있는 문제였다.
    효율성은 erase & unique가 더 좋았다.
*/
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int prev=arr.front();
    answer.push_back(prev);
    
    for(int i=1;i<arr.size();i++) {
        if(arr[i]!=prev) answer.push_back(arr[i]);
        
        prev=arr[i];
    }

    return answer;
}

// erase & unique
vector<int> solution(vector<int> arr) {
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    return arr;
}