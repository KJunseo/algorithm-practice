/*
    stages 내부를 오름차순으로 정렬하고
    스테이지 1부터 N까지 반복하면서
    각 스테이지에 멈춰있는 유저수를 세어 실패율을 구한 후
    실패율과, 유저 순서를 pair로 저장했다.
    그 후, 조건에 맞게 sort하였다.
    풀긴했지만 +2 밖에 받지 못했다 ㅎ..
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if(a.first>b.first) return true;
    else if(a.first==b.first) {
        if(a.second<b.second) return true;
        return false;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > fail;
    int totalUser=stages.size();
    
    sort(stages.begin(), stages.end());
    
    int index=0;
    for(int i=1;i<=N;i++) {
        int noClear=0;
        for(int j=index;j<totalUser;j++) {
            if(stages[j]==i) noClear++;
            else if(stages[j]>i) break;
        }
        double rate;
        if(noClear==0) {
            rate=0;
        } else {
            rate=(double)noClear/(double)(totalUser-index);
        }

        fail.push_back(make_pair(rate, i));
        index+=noClear;
    }
    
    sort(fail.begin(), fail.end(), compare);
    
    for(int i=0;i<fail.size();i++)
        answer.push_back(fail[i].second);
    
    return answer;
}