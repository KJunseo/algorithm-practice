/*
    그냥 문제에서 설명하는대로 차례차례 구현하면 되는 문제였다.
    카드2와 굉장히 흡사했다.
    1. card를 N번까지 큐에 넣고
    2. q.front()를 무덤에 넣고 pop한다.
    3. q.front()를 card 맨 위에 넣고 pop한다.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
queue<int> card;
vector<int> grave;

int main(void) {

    cin >> N;

    // N번까지 카드 등록
    for(int i=1;i<=N;i++) {
        card.push(i);
    }

    // 카드 한 장 남을 때 까지 반복 
    while(card.size()>1) {
        // 무덤에 맨 위의 카드 버리기 
        grave.push_back(card.front());
        card.pop();

        // 맨 위의 카드를 카드더미 맨 아래로 옮기기 
        card.push(card.front());
        card.pop();
    }

    for(int i=0;i<grave.size();i++) {
        cout << grave[i] << " ";
    }
    cout << card.front();

    return 0;
}