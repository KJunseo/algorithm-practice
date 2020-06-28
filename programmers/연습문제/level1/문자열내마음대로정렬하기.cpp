/*
    +1점
    compare 함수를 잘못 만들어서 그런지 몇 번 틀렸다.
    N번째 인덱스가 다른 경우는 N번째 순서로 비교
    그게 아니라면 전체 문자열 비교로 했다.
*/
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool compare(string a, string b) {
    if(a[N]!=b[N]) {
        return a[N]<b[N];
    } else {
        return a<b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    N=n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}