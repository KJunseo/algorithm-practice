/*
    +1점 
    그냥 더하기를 계속해주었지만 곱하기를 사용하거나 누적 시킨다면 for문을 하나만 쓸 수 있다.
*/
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for(int i=0;i<n;i++) {
        long long temp=x;
        for(int j=0;j<i;j++) {
            temp+=x;
        }
        answer.push_back(temp);
    }
    
    return answer;
}