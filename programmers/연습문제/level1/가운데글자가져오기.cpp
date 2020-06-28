/*
    음 또 1점을 받았다. 
    짝수 일 경우 문자열 (길이-1)/2 인덱스와 길이/2 인덱스를 더해주면 되고
    홀수 일 경우 길이/2 인덱스만 더해주면된다.
*/
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.length()%2==0) {
        answer=s[(s.length()-1)/2];
        answer+=s[(s.length())/2];
    } else {
        answer=s[s.length()/2];
    }
    
    return answer;
}