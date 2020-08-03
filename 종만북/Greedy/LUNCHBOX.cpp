/*
    먹는 시간이 가장 오래 걸리는 도시락을 제일 먼저 데운다.
    다른 도시락을 데우는 동안 먹을 수 있기 때문에 먹는 시간이 오래걸리는 도시락을 먼저 돌린다음에 먹기 시작하는 것이 가장 최선이다.

    그리디는 어떤 방법이 최적일까를 찾아내는 것이 포인트인 것 같다. 
    이때까지 sort(a.begin(), a.end(), greater<int>()) 는 많이 사용해봤지만 음수로 정렬한다는 것이 신기했다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n;
int e[10000], m[10000];

int heat() {

    vector<pair<int, int> > order;

    // 음수로 저장하는 이유는 먹는 시간이 많이 걸리는 도시락 부터 내림차순 정리를 쉽게하기 위함
    for(int i = 0; i < n; i++) {
        order.push_back(make_pair(-e[i], i));
    }
    sort(order.begin(), order.end());

    int ret = 0, beginEat = 0;
    for(int i = 0; i < n; i++) {
        int box = order[i].second; // 먹는 시간이 가장 오래 걸리는 도시락의 인덱스
        beginEat += m[box]; // 먹는 시간이 가장 오래 걸리는 도시락의 데우는 시간을 더함
        ret = max(ret, beginEat + e[box]); // 먹는 시간이 가장 오래 걸리는 도시락의 먹는 시간을 더함(데우는 시간만 더한 값과 먹는 시간도 더한 값 비교)
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        // 데우는데 걸리는 시간
        for(int i = 0; i < n; i++) {
            cin >> m[i];
        }

        // 먹는데 설리는 시간
        for(int i = 0; i < n; i++) {
            cin >> e[i];
        }

        cout << heat() << "\n";
    }

    return 0;
}