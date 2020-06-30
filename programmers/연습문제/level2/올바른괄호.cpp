/*
    +1점
    덱을 이용해서 풀었다. 스택처럼 사용했다.
    덱이 비어있다면 무조건 넣어주고
    덱의 가장위가 '(' 이고 넣어야하는 괄호가 ')' 일 경우만 덱의 가장 위를 제거해주고
    나머지 경우는 덱에 괄호를 추가해주었다.

    모든 문자열을 진행하고나서 덱이 비어있다면 true 그렇지 않다면 false이다.
*/
#include <string>
#include <deque>

using namespace std;

bool solution(string s) {
    deque<char> dq;

    for(int i=0;i<s.length();i++) {
        
        if(dq.empty()) {
            dq.push_back(s[i]);
        } else {
            if(dq.back()=='(' && s[i]==')') {
                dq.pop_back();
            } else {
                dq.push_back(s[i]);
            }
        }
    }

    return dq.empty() ? true : false;
}