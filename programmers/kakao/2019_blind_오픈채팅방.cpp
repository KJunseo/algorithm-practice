/*
    id에 따라서 닉네임을 구분하기 때문에 unodered_map을 사용해서 uid에따라 닉네임 값을 변경하면서 저장해주면 된다고 생각했다.
    공백으로 record 내부가 나뉘어져있어서 그걸 기준으로 행동, 아이디, 닉네임을 구분하였다.
    들어간 경우와, 나간경우만 출력하므로 그 경우는 userAct라는 벡터에 추가해주었다. 
    userAct를 순회하면서, 아이디에 따른 현재 닉네임과 행동을 이용하여 결과를 출력하였다.
    통과는 했지만, +1점이었다 ㅎㅎ....
*/
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, char> > userAct;
    unordered_map<string, string> user;
    
    for(int i=0;i<record.size();i++) {
        char act;
        string uid="";
        string nickname="";
        stringstream ss;
        
        ss.str(record[i]);
        string temp;
        int cnt=0;
        while(ss>>temp) {
            if(cnt==0) {
                act=temp[0];
            } else if(cnt==1) {
                uid=temp;
            } else if(cnt==2) {
                nickname=temp;
            }
            cnt++;
        }
        
        if(act=='E'||act=='C') user[uid]=nickname;
        if(act=='E'||act=='L') userAct.push_back(make_pair(uid, act));
        
    }
    
    for(int i=0;i<userAct.size();i++) {
        string result="";
        result+=user[userAct[i].first];
        if(userAct[i].second=='E') {
            result+="님이 들어왔습니다.";
        } else {
            result+="님이 나갔습니다.";
        }
        answer.push_back(result);
    }
    
    return answer;
}