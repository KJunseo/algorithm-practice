/*
    +1점
    string으로 바꿔주고 sort를 사용해서 정렬 후 stol로 다시 형 변환 해준다.
*/
#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string str=to_string(n);
    
    sort(str.begin(), str.end(), greater<char>());
    
    return stol(str);
}