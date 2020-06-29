/*
    +1점
    풀긴했으나 솔직히 지저분하게 풀었다고 생각이 든다.
    처음에 stringstream으로 무턱대고 나눠서 하다가 공백이 2개이상도 될 수 있다는 것을 적용하지 못해 틀렸다.
    그래서 stringstream으로 나누기 전에 연속된 공백만큼 벡터에 넣어주고, stringstream 사이사이에 공백벡터를 더해줬다.
    이렇게 하니까 공백이 맨처음에 올 경우를 해결하지 못했고, 따라서 s[0]이 공백일 경우는 공백벡터를 먼저 출력해주도록했다.

    실제 다른 사람의 풀이를 보니 훨씬 간단했다. 내가 너무 꼬아서 생각했던 것 같다.
*/
#include <string>

using namespace std;

string solution(string s) {
    string answer="";
    int idx=1;

    for(int i=0;i<s.size();i++, idx++) {
        if(s[i]==' ') {
            idx=0;
            answer+=' ';
        } else {
            idx & 1 ? answer+=toupper(s[i]) : answer+=tolower(s[i]);
        }
    }

    return answer;
}

// 내가 한 지저분한 코드
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp="";
    vector<string> enter, test;
    int idx=0;
    
    for(int i=0;i<s.length();i++) {
        if(s[i]==' ') temp+=' ';
        else {
            enter.push_back(temp);
            temp="";
        }
    }
    if(temp.length()!=0) enter.push_back(temp);
    
    for(int i=0;i<enter.size();i++) {
        if(enter[i].length()!=0) test.push_back(enter[i]);
    }
    
    stringstream ss(s);
    if(s[0]==' ') answer+=test[idx++];
    while(ss>>temp) {
        
        for(int i=0;i<temp.length();i++) {
            if(i%2==0) {
                temp[i]=toupper(temp[i]);
            } else {
                temp[i]=tolower(temp[i]);
            }
            answer+=temp[i];
        }
        
        if(idx<test.size()) answer+=test[idx++];
    }
    
    ss.clear();
    
    return answer;
}