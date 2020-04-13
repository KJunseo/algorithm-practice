/*
    덱을 사용해서 풀었다. 

    문제 설명 그대로, 해당 프린트물 보다 우선순위가 높은 프린트물이 있으면 맨 뒤로 옮겨주고, 
    가장 우선순위가 높은 것이 현재 프린트 물일 경우 array에 순위를 넣어준 후, location에 해당하는 순위를 return 했다.

    *max_element를 사용한 풀이도 있었다.
    *max_element(priorities.begin(),priorities.end()): 가장 큰 element 
*/
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int,int>> dq;
    int array[priorities.size()];
    
    for(int i=0;i<priorities.size();i++) {
        dq.push_back(make_pair(i, priorities[i]));
    }
    
    int idx=1;
    while(!dq.empty()) {
        pair<int, int> temp = dq.front();
      
        for(int i=0;i<dq.size();i++) {
            if(temp.second<dq[i].second) {
                dq.push_back(temp);
                break;
            }
            if(i==dq.size()-1) array[temp.first]=idx++;
        }
        
        dq.pop_front();
    }
    
    return array[location];
}