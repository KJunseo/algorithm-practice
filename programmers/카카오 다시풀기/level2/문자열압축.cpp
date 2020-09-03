/*
    예외처리를 하나 해주지 않아 시간을 좀 썼다.
    문자열을 나누는 기준을 1 부터 문자열 길이의 반만큼 증가 시키면서 각각 압축 문자열의 길이 중 최소를 반환하면 된다.
    나는 compression이라는 함수를 만들어 문자열과, 문자열을 나누는 기준을 받아 
    해당 기준으로 문자열을 나누어 벡터에 저장하고 인접한 두 문자열을 비교하여 같은 경우 count를 올려가며 압축 문자열을 만들었다.
    여기서 인접한 두 문자열을 비교할 때 벡터의 범위를 넘어가는 부분을 예외처리 하지 않아서 계속 88점에서 머물다가 예외처리를 해주고 나니 통과했다.

    이전에 푼 풀이보다는 훨씬 나아보인다.(https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2020_blind_%EB%AC%B8%EC%9E%90%EC%97%B4%EC%95%95%EC%B6%95.cpp)

*/
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int compression(string s, int unit) {
    vector<string> v;
    string ret = "";
    int position = 0;
    
    for(int position = 0; position < s.length(); position+=unit) {
        string sub = "";
        if(position+unit <= s.length()) sub = s.substr(position, unit);
        else sub = s.substr(position);
        
        v.push_back(sub);
    }

    int count = 1;
    for(int i = 0; i < v.size(); i++) {
        
        if(i < v.size()-1 && v[i] == v[i+1]) count++;
        else {
            if(count > 1) ret += to_string(count);
            ret += v[i];
            count = 1;
        }
    }
    
    return ret.length();
}

int solution(string s) {
    int answer = s.length();
    
    for(int unit = 1; unit <= s.length()/2; unit++) {
        answer = min(answer, compression(s, unit));
    }
    
    return answer;
}