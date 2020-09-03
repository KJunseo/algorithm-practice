/*
    예전에 처음 풀 때 문제 자체도 이해 못했던 기억이난다.

    해당 문자열이 올바른 괄호 문자열인지 확인하는 과정과
    문자열을 u와 v로 분리하는 과정이 핵심인 것 같다.
    나머지는 적혀있는 시나리오 순서로 구현하면 된다.

    이전 풀이
    (https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2020_blind_%EA%B4%84%ED%98%B8%EB%B3%80%ED%99%98.cpp)
*/
#include <string>
#include <vector>

using namespace std;

bool isRight(string s) {
    vector<char> v;
    
    for(int i = 0; i < s.length(); i++) {
        if(v.empty()) v.push_back(s[i]);
        else {
            if(v.back() == '(' && s[i] == ')') {
                v.pop_back();
            } else if(v.back() == '(' && s[i] == '(') {
                v.push_back(s[i]);
            }
        }
    }
    
    return v.empty();
}

vector<string> separation(string s) {
    vector<string> sub;
    int left = 0, right = 0;
    int i = 0;
    for(i = 0; i < s.length(); i++) {
        if(s[i] == '(') left++;
        if(s[i] == ')') right++;
        
        if(left == right) break;
    }
    
    sub.push_back(s.substr(0, i+1));
    sub.push_back(s.substr(i+1));
    
    return sub;
}

string solution(string p) {
    string answer = "";
    
    if(p.length() == 0) return "";
    if(isRight(p)) return p;
    
    vector<string> v = separation(p);
    
    if(isRight(v[0])) {
        answer += v[0];
        answer += solution(v[1]);
    } else {
        answer += "(";
        answer += solution(v[1]);
        answer += ")";
        
        string u = v[0].substr(1, v[0].length()-2);
        for(int i = 0; i < u.length(); i++) {
            if(u[i] == '(') answer += ")";
            else if(u[i] == ')') answer += "(";
        }
    }
    
    return answer;
}