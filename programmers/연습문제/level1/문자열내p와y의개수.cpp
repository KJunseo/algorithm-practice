/*
    +1점
    문자열 처음부터 한 문자씩 확인 하여 p, y 갯수를 세고
    갯수가 다를때만 false로 바꿔준다.
*/
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int p=0, y=0;

    for(int i=0;i<s.length();i++) {
        if(s[i]=='p' || s[i]=='P') p++;
        else if(s[i]=='y' || s[i]=='Y') y++;
    }
    
    if(p!=y) answer=false;

    return answer;
}