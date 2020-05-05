/*
    +2점이지만 풀었다.
    최대로 나눌 수 있는 문자수는 문자길이의 반이므로, 문자길이의 반까지만 반복한다.
    한 글자씩, 두 글자씩, 세 글자씩 ... 차례로 벡터를 만들어
    벡터에서 하나 씩 꺼내면서 겹치는 횟수를 계산하여 문자열을 만들어주고,
    최소 값으로 계속 업데이트 해주면 된다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int lastCase = s.length()/2;
        
    // 문자열 길이의 반까지만 반복 
    for(int i=1;i<=lastCase;i++) { 
        string result="";
        vector<string> sub;

        // 글자수 만큼 문자열 나누어 벡터에 저장 
        for(int j=0;j<s.length();j+=i) {
            string temp=s.substr(j, i);
            sub.push_back(temp);
        } 
        
        // 연속되는 글자 비교하여 결과 문자열 생성
        for(int j=0;j<sub.size();j++) {
            string temp=sub[j];
            
            int k;
            for(k=j+1;k<sub.size();k++) {
                if(temp!=sub[k]) {
                    break;
                }
            }
            if(k-j!=1) result+=to_string(k-j);
            result+=temp;
 
            j=k-1;
        }

        // 최솟값 업데이트 
        if(answer>result.length()) answer=result.length();
    }
    
    return answer;
}



// 다른 풀이 
#include <algorithm>

int solution(string s) {
    int answer=s.length();

    for(int i=1;i<=s.length()/2;i++) {
        int pos=0;
        int len=s.length();

        for(;;) {
            string unit=s.substr(pos, i);
            pos+=i;

            if(pos>=s.length()) break;

            int cnt=0;
            for(;;) {
                if(unit.compare(s.substr(pos, i))==0) {
                    cnt++;
                    pos+=i;
                } else {
                    break;
                }
            }

            if(cnt>0) {
                len-=i*cnt;

                if(cnt<9) len+=1;
                else if(cnt<99) len+=2;
                else if(cnt<999) len+=3;
                else len+=4;
            }
        }

        answer=min(answer, len);
    }

    return answer;
}