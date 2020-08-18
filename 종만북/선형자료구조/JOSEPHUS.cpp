/*
    list(연결리스트)를 이용한 문제였다.
    list를 이용하여 원형 연결 리스트를 흉내낸 것과
    erase()를 사용한 것이 흥미로웠다.

    erase(): list에서 포인터가 가리키는 원소를 삭제하고 그 다음 원소를 가리킴
*/
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int C;
int N, K;

void josephus() {
    list<int> survivors;

    // list에 1번부터 n번까지 사람들 넣기 
    for(int i = 1; i <= N; i++) {
        survivors.push_back(i);
    }

    // 이번에 죽을 사람을 나타내는 포인터 
    list<int>::iterator kill = survivors.begin();
    while(N > 2) {

        // 첫 번째 사람이 자살. erase()는 지운 원소의 다음 원소를 반환 
        kill = survivors.erase(kill);

        // kill이 가장 마지막 사람을 가리키면 첫 번재 사람으로 옮겨줌(원형 연결 리스트 흉내)
        if(kill == survivors.end()) kill = survivors.begin();

        N--;

        // k-1 번 다음 사람으로 옮김(erase가 지운 원소의 다음 원소를 가리키므로 k-1만큼 이동하면 k만큼 이동한 것)
        for(int i = 0; i < K-1; i++) {
            kill++;

            // 원형 연결 리스트 흉내
            if(kill == survivors.end()) kill = survivors.begin();
        }
    }

    cout << survivors.front() << " " << survivors.back() << "\n";
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N >> K;

        josephus();
    }

    return 0;
}