/*
    어떻게 접근해야 할지 헷갈렸다.
    벡터를 사용해서 1부터 N까지 배정하고, 만약 대진표의 양 쪽이 지민, 한수면 종료시켰다.
    그렇지 않으면 승자를 뽑아서 대진표 벡터를 다시 배정하는 식으로 했다.

    테스트 케이스는 통과했는데, 메모리초과, 시간초과가 났다..

    수학문제라고 한다.
    라운드가 올라갈 때마다, 자신의 번호는 (자신의 번호+1)/2가 된다.
    똑같은 번호를 배정받으면 대진을 하는 것이다.

    너무 복잡하게 접근했었다.
*/
#include <iostream>

using namespace std;

int N;
int round;
int jimin, hansoo;
int main(void) {

    cin >> N >> jimin >> hansoo;

    while(N) {
        round++;

        // 라운드가 증가할 때마다 인덱스는 반이 된다.(지민, 한수는 무조건 이긴다.)
        jimin=(jimin+1)/2; 
        hansoo=(hansoo+1)/2;

        // 토너먼트에서 만나면 라운드 출력 후 종료
        if(jimin == hansoo) {
            cout << round << "\n";
            return 0;
        }

        N/=2; // 한 라운드가 끝날 때 마다, 반씩 사라지기 때문에
    }

    if(N==0) cout << -1 << "\n"; // 끝까지 매칭안되면 -1

    return 0;
}