/*
    도착지를 기준으로 sort 해주고, ICN 출발지를 찾아, ICN과 도착지를 answer에 넣은 후, tickets에서 지워주고
    재귀를 통해 현재 도착지와, 새로운 곳의 출발지가 같으면 answer에 넣어주는 것을 반복하여 tickets size가 0이면 종료했다.
    테이스케이스 1, 2에서 시간초과가 났다.

    모든 도시 방문 여부를 확인하기 위해 d(깊이) 값을 dfs에 넘겨줬고, 
    ICN 부터 시작해서 도착지와 다음 출발지를 비교하여 같은 경우 방문처리 후, dfs에 넘겨줬다.
*/

// 통과 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<string> temp;
bool checked[10000];

bool dfs(int d, string from, vector<vector<string>> &tickets, bool checked[]) {

    temp.push_back(from);

    // 모든 곳을 방문했는 지 확인
    if(d==tickets.size()) {
        answer=temp;
        return true;
    }

    for(int i=0;i<tickets.size();i++) {

        // 도착지를 방문하지 않았고, 도착지와 다음 출발지가 일치한다면 
        if(tickets[i][0]==from && !checked[i]) {
            checked[i]=true; // 방문 처리 

            bool flag = dfs(d+1, tickets[i][1], tickets, checked);

            if(flag) return true; // 경로찾기를 성공한 경우 dfs 종료

            checked[i]=false; // 방문 해제 
        }
    }

    temp.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());

    dfs(0, "ICN", tickets, checked);

    return answer;
}


// 처음에 시도한 TC 1,2 시간초과 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool compare(vector<string> a, vector<string> b) {
    if(a[1]<b[1]) return true;
    return false;
}

void dfs(vector<vector<string>> tickets) {
    if(tickets.size()==0) {
        return;
    }
    
    for(int i=0;i<tickets.size();i++) {
        if(tickets[i][0]==answer.back()) {
            answer.push_back(tickets[i][1]);
            tickets.erase(tickets.begin()+i);
            break;
        }
    }
    dfs(tickets);
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end(), compare);
    
    for(int i=0;i<tickets.size();i++) {
        if(tickets[i][0]=="ICN") {
            answer.push_back(tickets[i][0]);
            answer.push_back(tickets[i][1]);
            tickets.erase(tickets.begin()+i);
            break;
        }
    }
    
    dfs(tickets);
    
    return answer;
}