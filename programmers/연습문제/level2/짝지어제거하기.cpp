/*
    벡터를 스택처럼 사용하였다.
    젤 처음 요소는 그냥 넣어주고, 그 다음 요소부터 가장 뒤의 요소와 넣으려는 요소가 같은경우 pop 아닐경우 push 해주었다.
*/
#include <vector>
#include <string>

using namespace std;

int solution(string s) {
    vector<char> v;

    v.push_back(s[0]);
    for(int i=1;i<s.length();i++) {

        if(v.back()==s[i]) {
            v.pop_back();
        } else {
            v.push_back(s[i]);
        }
    } 

    return v.empty() ? 1 : 0;
}