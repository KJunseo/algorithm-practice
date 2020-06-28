/*
    +1점
    isdigit을 사용해서 풀었다.
    먼저 문자열 길이를 비교해준 후 isdigit으로 숫자가 아닌 것이 있다면 false를 리턴했다.
*/
#include <string>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = false;
    
    if(s.length()==4 || s.length()==6) {
        for(int i=0;i<s.length();i++) {
            if(!isdigit(s[i])) {
                return answer;
            }
        }
        answer=true;
    }
    
    return answer;
}