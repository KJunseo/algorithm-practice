/*
    미리 opening, closing을 지정해놓고
    string에서 find함수를 사용했을 때, 해당 문자열이 포함된 위치를 리턴하는 것을 이용한 것이 흥미로웠다. 
    위치를 기반으로 짝이 맞는지를 판별했다.
*/
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int C;
string str;

bool wellMatched() {

    const string opening("({["), closing(")}]");

    stack<char> openStack;
    for(int i = 0; i < str.length(); i++) {
        
        // 여는 괄호이면 스택에 넣음
        if(opening.find(str[i]) != -1) openStack.push(str[i]);
        else {

            // 비어있는 상태인데 닫는 괄호일 경우 false
            if(openStack.empty()) return false;

            // 서로 짝이 맞지 않으면 실패
            if(opening.find(openStack.top()) != closing.find(str[i])) return false;

            // 짝이 맞는 경우 스택에서 가장 위에꺼 빼기 
            openStack.pop();
        }
    }

    // 모든 괄호가 짝을 찾아서 빈 스택이 되는 경우 true 
    return openStack.empty();
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> str;

        if(wellMatched()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}