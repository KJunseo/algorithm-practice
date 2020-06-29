/*
    +1점
    처음에 너무 어렵게 생각했다. 갯수가 3배씩 계속 증가하길래 몇 번째에 해당하는 지 찾고 순열을 돌려야된다고 생각했었다..

    그냥 1, 2, 4만 사용가능하기 때문에 3진법으로 생각한다. 
    %3과 /3을 이용한다.
    주의할 점은 n%3==0 일 때 3대신 4를 넣어주고 n/3-1을 해줘야한다.
    매번 문자열의 맨 앞에 삽입해준다.
*/
#include <string>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n>0) {
        if(n%3==0) {
            answer.insert(0, "4");
            n=n/3-1;
        } else {
            answer.insert(0, to_string(n%3));
            n/=3;
        }
    }
    
    return answer;
}