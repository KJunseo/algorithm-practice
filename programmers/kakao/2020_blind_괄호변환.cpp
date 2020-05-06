/*
    문제 이해하기가 너무 어려웠다.
    재귀를 통해, 문자열을 u, v로 나누는 것을 반복했고,
    u가 올바른 괄호 문자열인지 확인해서, 맞으면 u+결과값
    아니면 ( + 결과값 + ) + u의 맨 처음, 맨 끝 제거한 문자열을 반대로 바꾼 값을 리턴했다.
    +1 점으로 통과했다.. 요즘 너무 비효율적으로 짜는 건가 하는 생각이든다.
    통과했다는 것에 의의를 둔다..

    다른 풀이를 밑에 첨부하였다.
*/
#include <string>
#include <vector>

using namespace std;

// 문자열 반대로 바꾸기
string change(string s) {
    string result="";
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') result+=')';
        else if(s[i]==')') result+='(';
    }
    return result;
}

// 올바른 괄호 문자열인지 확인하는 함수
bool check(string str) {
    vector<char> v;
    v.push_back(str[0]);
    
    for(int i=1;i<str.length();i++) {
        if(v.front()==')') return false;
        
        if(v.back()=='(' && str[i]==')'){
            v.pop_back();
            continue;
        }
        v.push_back(str[i]);
    }
    
    return true;
}

string divideStr(string p) {
    if(p.length()==0) return ""; // 빈 문자열이면 "" 리턴 
    if(check(p)) return p; // 올바른 문자열이면 자기자신 리턴 

    string u="";
    string v="";
    string result="";
    char base=p[0];
    int cnt1=1;
    int cnt2=0;
    int index=0;

    // 가장 짧은 균형잡힌 문자열로 분리 
    for(int i=1;i<p.length();i++) {
        if(base==p[i]) cnt1++;
        else cnt2++;
        
        if(cnt1==cnt2) {
            index=i;
            break;
        }
    }
    u=p.substr(0, index+1);
    v=p.substr(index+1);
    
    if(check(u)) {  // 올바른 문자열이면
        result+=u;
        result+=divideStr(v);
    } else {        // 올바른 문자열이 아니면 
        result+='(';
        result+=divideStr(v);
        result+=')';
        result+=change(u.substr(1, u.length()-2));
    }
    return result;
}

string solution(string p) {
    return divideStr(p);
}



// 다른 풀이
#include <stack>

bool isCorrect(string str, int* pos) {
    bool ret=true;
    int left=0, right=0; // left: (  / right: )
    stack<char> mystack;

    for(int i=0;i<str.length();i++) {
        if(str[i]=='(') {
            left++;
            mystack.push('(');
        } else {
            right++;
            if(mystack.empty()) ret=false;
            else mystack.pop();
        }
        if(left==right) {
            *pos=i+1;
            return ret;
        }
    }
    return true;
}

string solution(string p) {    
    if(p.empty()) return p;

    int pos;
    bool correct = isCorrect(p, &pos);

    string u = p.substr(0, pos);
    string v = p.substr(pos);

    if(correct) {
        return u+solution(v);
    }

    string answer="(" + solution(v) + ")";
    for(int i=1;i<u.length()-1;i++) {
        if(u[i]=='(') answer+=')';
        else answer+='(';
    }

    return answer;
}
