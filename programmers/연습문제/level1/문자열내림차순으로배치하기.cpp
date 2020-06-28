/*
    +1점
    그냥 sort 함수를 사용하면 끝이다
*/
#include <string>
#include <algorithm>

using namespace std;

bool compare(char &a, char &b) {
    return a > b;
}

string solution(string s) {
    
    sort(s.begin(), s.end(), compare);

    return s;
}