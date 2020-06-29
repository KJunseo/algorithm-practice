/*
    +1점
    %와 /를 이용해서 한 자리씩 나눠주면 저절로 역순이된다.
*/
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n>0) {
        answer.push_back(n%10);
        n/=10;
    }
    
    return answer;
}