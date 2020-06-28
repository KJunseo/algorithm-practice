/*
    +1점. level1 중에서는 헷갈렸다.
    대문자 소문자를 나눠서 시작점을 잡아주고
    모듈 연산을 통해 순환시켜준다.
*/
#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i<s.length();i++) {
        char start;
        
        if(s[i]>='A' && s[i]<='Z') start='A';
        else if(s[i]>='a' && s[i]<='z') start='a';
        
        if(s[i]!=' ') {
            s[i]=start+((s[i]+n-start)%26);
        }
        
        answer+=s[i];
    }
    
    return answer;
}