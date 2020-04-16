/*
    우선 순위 큐만으로 해결해보려 하다가, 덱을 사용했다.
    덱에 요소를 넣을 때마다 sort를 해서, 최소, 최대를 동시에 접근할 수 있도록 하였다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i=0;i<operations.size();i++) {
        if(operations[i][0]=='I') {
            dq.push_back(stoi(operations[i].substr(1)));
            sort(dq.begin(), dq.end());
        } else if(operations[i][0]=='D') {
            if(dq.size()==0) {
                continue;
            }
            if(operations[i][2]=='-') {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        }
    }
    
    if(dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}