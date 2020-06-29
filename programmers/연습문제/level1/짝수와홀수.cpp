/*
    +1점
*/
#include <string>

using namespace std;

string solution(int num) {
    string answer = "";
    
    if(num%2==0) answer="Even";
    else answer="Odd";
    
    return answer;
}

// 비트연산
string solution(int num) {
    return num & 1 ? "Odd" : "Even";
}