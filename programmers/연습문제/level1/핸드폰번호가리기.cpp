/*  
    +1점
    substr을 사용해서 끝에서 4개의 문자를 추출한다음
    나머지 숫자만큼 *를 추가한 곳에 더해주었다.
    아에 전화번호를 변경해도 되는 문제이다.
*/
#include <string>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size=phone_number.length()-4;
    string last=phone_number.substr(size);
    
    for(int i=0;i<size;i++) {
        answer+='*';
    }
    
    answer+=last;
    
    return answer;
}