/*
    짤은 문자열 끼리 서로 합치면서 문자열이 하나가 되면 종료하면 된다.
    두 문자열을 합치는 비용을 계속 더해주면 된다.

    우선순위 큐를 사용하면 가장 작은 수나 가장 큰 수를 쉽게 얻을 수 있다.
    greater<int>을 사용하여 가장 작은 수가 top에 오도록 한 후, 두 개씩 빼면서 더해주면 된다.

    이때까지 우선순위 큐를 사용할 때 priority_queue<int> pq; 이렇게만 사용해보았었는데 
    priority_queue<int, vector<int>, greater<int> > pq; 이런식으로 컨테이너와 조건자를 넣는 방법을 처음해봤다.

    구현자체는 어렵지 않은 문제였다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int C;
int n;

int concat(const vector<int>& lengths) {

    priority_queue<int, vector<int>, greater<int> > pq; // Min heap 

    for(int i = 0; i < lengths.size(); i++) {
        pq.push(lengths[i]);
    }

    // 가장 작은 두 문자열을 서로 합친다.
    int ret = 0;
    while(pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        pq.push(min1 + min2);
        ret += min1 + min2;
    }
    
    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        vector<int> lengths;

        for(int i = 0; i < n; i++) {
            int length;

            cin >> length;
            lengths.push_back(length);
        }

        cout << concat(lengths) << "\n";
    }

    return 0;
}