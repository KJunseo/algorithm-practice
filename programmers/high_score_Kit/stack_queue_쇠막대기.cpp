/*
    레이저의 위치를 찾아내는 것은 쉬웠는데, 막대를 생성하는 것이 조금 헷갈렸다.
    결국 막대의 시작점과, 끝 점을 찾아서 벡터에 넣어주고, 레이저는 큐에 넣어준 후,
    레이저를 하나씩 꺼내면서, 막대의 시작점과, 끝 점 사이에 레이저가 위치하면 answer를 하나씩 늘렸다.
    그리고 막대 벡터의 사이즈를 더해주었다.(기본 막대의 갯수)

    다른 사람은 23줄 정도로도 푼 풀이를 봤다 ㅎ..(밑에 첨부했다.)
    이 코드가 훨씬 빠르기도 했다.
*/
#include <string>
#include <vector>
#include <queue>

#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    queue<int> laser;
    vector<int> start;
    vector<int> end;
    vector<pair<int, int> > stick;
    
    for(int i=0;i<arrangement.length();i++) {
        char temp = arrangement[i];
        
        if(temp=='(' && arrangement[i+1]==')') {
            laser.push(i);
            i=i+1;
        } else {
            if(temp=='(') {
                start.push_back(i);
            } else {
                end.push_back(i);
            }
        }
        
        if(!end.empty()) {
            stick.push_back(make_pair(start.back(), end.back()));
            start.pop_back();
            end.pop_back();
        }
    }
    
    answer+=stick.size();
    
    while(!laser.empty()) {
        int l = laser.front();
        laser.pop();
        
        for(int i=0;i<stick.size();i++) {
            if(l>=stick[i].first && l<=stick[i].second) {
                answer++;
            }
        }
    }
    
    return answer;
}


// 더 효율적인 코드 
int solution(string arrangement) {
    int answer = 0;
    stack<int> s;
    
    for (int i = 0; i < arrangement.length(); i++){

        // '(' 이면 스택에 추가
        if(arrangement[i] == '(')
            s.push(1);
        else{
            s.pop(); // ')' 이면 스택에서 제거

            // 레이저인 경우이므로 열린괄호(막대 수)만큼 추가
            if (arrangement[i - 1] == '(') {
                answer += s.size();
            } else // 쇠막대기의 마지막이므로 1개 추가
                answer++;
        }
    }
    return answer;
}