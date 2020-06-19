/*
    매우 쉬운 문제였다.
    그냥 국어랑 수학이 0page가 될때까지 C, D 값 만큼씩 매일 빼주면 되는 문제이다.
*/
#include <iostream>

using namespace std;

int L, A, B, C, D;

int main(void) {

    cin >> L >> A >> B >> C >> D;

    while(A>0 || B>0) {
        L--;
        A-=C;
        B-=D;
    }

    cout << L << "\n";

    return 0;
}