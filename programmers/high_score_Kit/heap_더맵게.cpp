/*
    우선 순위 큐를 사용하니 금방 풀 수 있었다.
    min heap으로 풀었다.

    가장 작은 수가 k보다 큰지 안 큰지를 판별하면 된다.
    만약 우선순위 큐의 사이즈가 1인데 k보다 작다면 -1을 리턴해준다.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++) {
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()) {
        int first=pq.top();
        
        if(pq.size()==1 && first<K) return -1;
       
        if(first>K) break;
        
        pq.pop();
        int second=pq.top();
        pq.pop();
        
        int newFood=first+(second*2);
        
        pq.push(newFood);
        answer++;
    }
    
    return answer;
}