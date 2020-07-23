/*
    처음에는 문제 자체를 이해하지 못했다. 

    이 문제의 풀이에서 인상 깊었던 것은 iterator를 전달해서 사용하는 부분이었다.
    문자열의 한 글자를 가리키는 포인터를 전달하여 함수에서 한 글자 검사 할때마다 포인터를 하나씩 옮기면 변화가 밖에까지 영향을 끼치기때문에
    다음 부분의 시작 위치를 가리키게 된다.

    많이 부족함을 느낀다.
*/
#include <cstdio>
#include <iostream>

using namespace std;

int C;

string reverse(string::iterator& it) {
    char head = *it;
    it++;

    // 기저 사례 
    if(head == 'b' || head == 'w') {
        return string(1, head);
    }

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 위 아래 조각의 순서 바꾸기 
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void) {

    cin >> C;

    for(int t=0;t<C;t++) {
        string picture;

        cin >> picture;

        string::iterator it = picture.begin();

        cout << reverse(it) << "\n";
    }

    return 0;
}