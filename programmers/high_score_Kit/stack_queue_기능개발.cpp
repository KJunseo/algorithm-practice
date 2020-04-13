/*
    어 쉽네라고 생각한 문제였는데 생각보다 시간이 걸렸다.

    큐를 사용해서 풀었다. 앞의 수가 빠져나가야지 뒤에 수를 뺄 수 있는 부분에서 구현이 조금 걸렸다.
    보통 남은 작업량을 계산해서 푸는 풀이가 많았다.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    queue<int> speed;
    int num=0;
    
    for(int i=0;i<progresses.size();i++) {
        q.push(progresses[i]);
        speed.push(speeds[i]);
    }
    
    int idx=0;
    while(!q.empty()) {
        int size=q.size();

        for(int i=0;i<size;i++) {
            int temp=q.front();
            int s=speed.front();
            q.pop();
            speed.pop();
            
            if(i==idx&&temp>=100) {
                num++;
                idx++;
                continue;
            } 
            
            q.push(temp+s);
            speed.push(s);
        }
        
        if(num>0) {
            answer.push_back(num);
            num=0;
            idx=0;
        }

    }
    
    // 좀 더 간단한 풀이
    /*int day=1;
    while(!q.empty()) {
        int cnt=0;
        int size=q.size();

        for(int i=0;i<size;i++) {
            if((q.front()+(speed.front()*day))>=100) {
                cnt++;
                q.pop();
                speed.pop();
            }
        }
        if(cnt>0) answer.push_back(cnt);
        day++;
    }*/

    return answer;
}