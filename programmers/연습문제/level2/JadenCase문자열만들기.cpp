/*
    stringstream으로 공백 기준으로 나눈 후 index 0만 대문자로 나머지는 소문자로 바꿨는데 틀렸었다.
    생각해보니 공백이 두 개 이상 주어질 수도 있었다.
    그래서 각 단어 사이에 공백 갯수를 벡터에 저장해두고 stringstream을 써서 단어 변환 후 answer에 더해줄 때 벡터의 요소도 차례대로 더해주었다.

    훨씬 간단한 코드가 있어 밑에 첨부하였다. 제일 처음 요소를 toupper 해준 후, 다음 요소부터 문자열 끝까지 탐색하면서
    이전 문자가 공백인 경우만 toupper 나머지는 tolower 해주면 된다.
*/
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<string> empty;
    string temp="";
    int idx=0;
    
    for(int i=0;i<s.length();i++) {
        if(s[i]==' ') temp+=s[i];
        
        if(temp.length()>0 && s[i]!=' ') {
            empty.push_back(temp);
            temp="";
        }
    }
    if(temp.length()>0) empty.push_back(temp);
    
    while(ss >> temp) {
        for(int i=0;i<temp.length();i++) {
            if(i==0) temp[i]=toupper(temp[i]);
            else temp[i]=tolower(temp[i]);
        }
        answer+=temp;
        
        if(idx<empty.size()) answer+=empty[idx++];
    }
    
    return answer;
}

string solution(string s) {
    string answer="";

    answer+=toupper(s[0]);
    for(int i=1;i<s.length();i++) {
        s[i-1]==' ' ? answer+=toupper(s[i]) : answer+=tolower(s[i]);
    }

    return answer;
}