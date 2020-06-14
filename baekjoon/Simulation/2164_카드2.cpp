/*
    1부터 N까지 모두 큐에 넣고, 큐의 크기가 1이 남을 때까지 반복문을 돌리면서
    1. 큐의 front를 제거(맨 위의 카드 제거)
    2. 큐의 front를 push하고 pop(두 번째 카드 맨 아래에 넣기)
    위의 과정을 반복해주었다.
*/
#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main(void) {

    cin >> N;

    for(int i=1;i<=N;i++) {
        q.push(i);
    }

    while(q.size()>1) {
        q.pop();

        int temp=q.front();
        q.push(temp);
        q.pop();
    }

    cout << q.front() << "\n";

    return 0;
}