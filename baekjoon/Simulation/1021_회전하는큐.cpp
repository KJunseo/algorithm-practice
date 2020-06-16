/*
    큐의 앞 뒤를 모두 조작할 수 있는 덱을 이용한다.
    2번을 실행할지 3번을 실행할지 인덱스로 비교해야한다.
*/
#include <iostream>
#include <deque>

using namespace std;

int N, M;
int cnt;
deque<int> dq;

// 현재 큐에서 입력받은 숫자의 인덱스를 찾음 
int findIdx(int num) {
    int idx;
    for(int i=0;i<dq.size();i++) {
        if(dq[i]==num) {
            idx=i;
            break;
        }
    }
    return idx;
}

int main(void) {

    cin >> N >> M;

    for(int i=1;i<=N;i++) {
        dq.push_back(i);
    }

    for(int i=0;i<M;i++) {
        int num;

        cin >> num;

        int idx=findIdx(num);

        if(idx<dq.size()-idx) { // 인덱스가 큐의 크기에서 인덱스를 뺀 값보다 작다면 2번 실행
            while(true) {
                if(dq.front()==num) {
                    dq.pop_front();
                    break;
                }
                ++cnt;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else { // 3번 실행
            while(true) {
                if(dq.front()==num) {
                    dq.pop_front();
                    break;
                }
                ++cnt;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}