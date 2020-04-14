/*
    덱을 사용해서 풀었고, 생각보다 쉬워서 level2가 맞나 싶었다.
    효율성까지 검사해서 혹시 틀리나 생각했지만 통과하였다.
    
    다른 풀이를 보니 그냥 단순히 벡터 이중 for문으로 계산해도 통과한다.
    오히려 효율성은 이 방법이 더 좋게나온다.
*/
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i=0;i<prices.size();i++) {
        dq.push_back(prices[i]);
    }
    
    while(!dq.empty()) {
        int temp=dq.front();
        dq.pop_front();
        
        for(int i=0;i<dq.size();i++) {
            if(dq[i]<temp) {
                answer.push_back(i+1);
                break;
            }
            if(i==dq.size()-1) answer.push_back(dq.size());
        }
    }
    answer.push_back(0);
    
    return answer;
}

// 벡터 사용 
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    for(int i = 0; i<prices.size(); i++){
        for(int j = i+1; j<prices.size(); j++){
            if(prices[i]<=prices[j]){
                answer[i]++;
            }
            else{
                answer[i]++;
                break;
            }
        }
    }

    return answer;
}