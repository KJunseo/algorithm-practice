/*
    매번 자신의 왼쪽 자리로 폭탄을 옮기기 때문에 큐를 사용하면 편할 것 같았다.
    폭탄을 가진 사람부터 큐에 넣어준후, 정답을 맞추면 큐에서 빼서 큐에 다시 넣어주고 틀리거나 스킵이면 시간만 빼주었다.
    큐를 사용하지 않고도 그냥 계산으로도 풀 수 있다.
*/
#include <iostream>
#include <queue>

using namespace std;

int K, N;
int second=210;
queue<int> bomb;

int main(void) {

    cin >> K >> N;

    for(int i=0;i<8;i++) {
        bomb.push(K++);

        if(K>8) K=1;
    }

    for(int i=0;i<N;i++) {
        int t;
        char answer;

        cin >> t >> answer;

        second-=t;

        if(second<=0) break;

        if(answer=='T') {
            bomb.push(bomb.front());
            bomb.pop();
        } 
    }

    cout << bomb.front() << "\n";

    return 0;
}