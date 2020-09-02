/*
    먼저 각 스테이지 별 통과 못한 사람들의 수를 map을 사용해서 정리하였다.
    그 후 각 스테이지 별 실패율을 계산하였다.(* 0으로 나누는 것을 조심해야한다. 이 예외처리를 하지 않으니 테스트 케이스 5개가 틀렸다.)
    실패율 계산 후 sort의 compare함수를 조작하여 문제에서 원하는 방법으로 정렬하였다.

    이전에 풀이한 것을 보니 stages를 먼저 정렬 후 각 스테이지의 실패율을 계산했었다.(https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2019_blind_%EC%8B%A4%ED%8C%A8%EC%9C%A8.cpp) 
    지금 풀이가 더 나은 것 같다.
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second > b.second) return true;
    else if(a.second == b.second) {
        if(a.first < b.first) return true;
    }
    
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > ratePerStage;
    map<int, int> m;
    int totalUser = stages.size();
    
    for(int i = 0; i < totalUser; i++) {
        if(stages[i] != N+1) m[stages[i]]++;
    }
    
    for(int i = 1; i <= N; i++) {
        double failureRate;
        if(totalUser != 0) 
            failureRate = (double)m[i] / (double)totalUser;
        else failureRate = 0;
        
        totalUser -= m[i];
        ratePerStage.push_back(make_pair(i, failureRate));
    }
    
    sort(ratePerStage.begin(), ratePerStage.end(), compare);
    
    for(int i = 0; i < ratePerStage.size(); i++) {
        answer.push_back(ratePerStage[i].first);
    }
    
    return answer;
}