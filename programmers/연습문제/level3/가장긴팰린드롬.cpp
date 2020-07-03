/*
    효율적인지는 잘 모르곘지만 풀었다.(효율성을 통과했으니 효율적인 건가..)
    우선 두가지 경우를 나눠서 생각했다.
    1. 펠린드롬 문자열이 짝수일 경우(ex. abba) 
    2. 펠린드롬 문자열이 홀 수인 경우(ex. abcba)

    홀수인 경우는 한 중앙점을 기준으로 양 옆의 문자열을 비교하면서 달라질 때 무한루프를 종료시킨다.
    짝수인 경우는 문자열을 돌면서 연속한 두 문자가 같아지는 부분을 찾고 해당 부분에서 양 옆의 문자열을 비교하면서 달라질 때 무한루프를 종료시킨다.

    이렇게 해주면 17번 테스트케이스 빼고는 통과한다.
    17번 케이스는 문자열의 길이가 1일때이다. 따라서 문자열의 길이가 1일때는 그냥 1을 리턴해주는 구문을 추가하면 통과한다.

    문자열의 길이를 증가시켜보면서 비교해보는 방법도 있었다.
*/
#include <string>

using namespace std;

int solution(string s) {
    int answer=0;
    
    if(s.length()==1) return 1; // 전체 문자열의 길이가 1일 때 

    // 기준 문자 정하기 
    for(int i=1;i<s.length();i++) {
        int diff=0;
        
        // 펠린드롬 길이가 홀수 일 때
        while(true) {
            if((i-diff)>=0 && (i+diff)<s.length()) {
                if(s[i-diff]==s[i+diff]) {
                    diff++;
                } else break;
            } else break;
        }

        int res=diff*2-1;
        
        if(answer<res) {
            answer=res;
        }
        
        diff=0;
        
        // 펠린드롬 길이가 짝수 일 때 
        if(s[i]==s[i+1]) {
            while(true) {
                if((i-diff)>=0 && (i+diff)<s.length()) {
                    if(s[i-diff]==s[i+1+diff]) {
                        diff++;
                    } else break;
                } else break;
            }
        }
        
        res=diff*2;
        
        if(answer<res) {
            answer=res;
        }
    }

    return answer;
}