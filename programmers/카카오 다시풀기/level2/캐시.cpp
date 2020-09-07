/*
    큐를 사용하려고 하였으나 find나 erase를 쓰기 위해 deque를 사용했다.
    한 가지 의문인 것은 처음에 구현할 때는 dq의 크기가 cacheSize보다 작을 때는 그냥 넣기만 하려고 하였는데 테스트 케이스 11, 16, 19, 20번을 통과하지 못했다.
    그래서 그냥 pop할때만 크기 비교를 해주니 통과했다.
*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    
    if(cacheSize == 0) return 5 * cities.size();
    
    for(int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
                
        deque<string>::iterator it = find(dq.begin(), dq.end(), cities[i]);

        if(it != dq.end()) {
            dq.erase(it);
            dq.push_back(cities[i]);
            answer += 1;
        } else {
            if(dq.size() >= cacheSize) dq.pop_front();
            dq.push_back(cities[i]);
            answer += 5;
        }
    }    
    
    return answer;
}