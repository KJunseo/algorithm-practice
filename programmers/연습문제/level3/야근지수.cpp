/*
    남은 일이 클수록 야근 피로도가 커지기 때문에 작업량을 줄여줘야한다. 큰 작업량을 줄일 수록 값이 줄어든다.
    우선순위 큐를 사용하면 자동으로 가장 큰 값이 위에 가기 때문에 가장 큰 값을 1씩 줄여주기 편하다
    n만큼 반복 후 남은 작업량을 제곱하면 된다.
*/
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> remain(works.begin(), works.end());
    
    for(int i=0;i<n;i++) {
        if(remain.top()>0) {
            int temp=remain.top();
            remain.pop();
            remain.push(temp-1);
        }
    }
    
    while(!remain.empty()) {
        int temp=remain.top();
        remain.pop();
        
        answer+=pow((long long)temp, 2);
    }
    
    return answer;
}
