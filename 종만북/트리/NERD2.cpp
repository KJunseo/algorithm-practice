/*
    몇 번 사용해봤던 stl의 map이 트리로 이루어졌다는 것을 처음 알았다.
    문제를 보고 규칙을 찾고 나눠서 구현하는 것이 정말 대단한 것 같다.
*/
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int C;
int N;
map<int, int> coords;

// 새로운 점 (x, y)가 기존의 다른 점들에 지배당하는지 확인 
bool isDominated(int x, int y) {

    // x 보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾는다.
    map<int, int>::iterator it = coords.lower_bound(x);

    // 그런 점이 없다면 (x, y)는 지배당하지 않는 것 
    if(it == coords.end()) return false;

    // 이 점은 x보다 오른쪽에 있는 점 중 가장 위에 있는 점이므로
    // (x, y)가 어느 점에 지배되려면 이 점에도 지배되어야한다. 
    return y < it->second;
}

// 새로운 점(x, y)에 지배당하는 점들을 트리에서 삭제 
void removeDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);

    // (x, y)보다 왼쪽에 있는 점이 없는 경우 
    if(it == coords.begin()) return;

    it--;

    // it은 (x, y)의 바로 왼쪽에 있는 점 
    while(true) {

        // it이 (x, y)에 지배되지 않는다면 바로 종료
        if(it->second > y) break;

        // 이전 점이 없는 경우 it만 지우고 종료 
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        } else {
            // 이전 점으로 이터레이터를 옮겨좋고 it 지우기
            map<int, int>::iterator jt = it;
            jt--;
            coords.erase(it);
            it = jt;
        }
    }
}

// 새로운 점 x, y 가 추가되었을 때, coords를 갱신하고
// 다른 점에 지배당하지 않는 점들의 수를 리턴한다.
int registered(int x, int y) {

    // (x, y)가 지배당하는 경우에는 기존 사이즈 반환 
    if(isDominated(x, y)) return coords.size();

    // 기존에 있는 점들 중 (x, y)에 지배당하는 점들 삭제
    removeDominated(x, y);

    // 새로운 점 (x, y) 추가 
    coords[x] = y;

    return coords.size();
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N;

        coords.clear();

        int ret = 0;
        for(int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;

            ret += registered(x, y);
        }

        cout << ret << "\n";
    }

    return 0;
}