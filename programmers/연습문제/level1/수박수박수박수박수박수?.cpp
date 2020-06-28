/*
    +1점
    n을 2로 나눈 수 만큼 "수박"을 추가해주고
    홀수일 경우만 "수"를 추가해준다.

    비트연산자가 인상깊었다. 1과 홀수를 & 연산하면 1이 리턴된다는 것을 이용한다.
    i & 1 ? answer += "박" : answer += "수";
*/
#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i=0;i<n/2;i++) {
        answer+="수박";
    }
    
    if(n%2==1) answer+="수";
    
    return answer;
}