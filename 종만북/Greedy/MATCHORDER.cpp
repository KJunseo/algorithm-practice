/*
    여러 STL을 사용한 문제였다.
    특히 이진 탐색 트리를 이용한 multiset이 흥미로웠다.
    multiset은 key값이 중복가능한 set이며 자동으로 오름차순 정렬된다.

    rbegin(): set의 마지막에서부터 거꾸로 탐색하는 것이다.
    erase(): iterator가 가리키는 요소 삭제 
    lower_bound(): 이진 탐색 기반의 탐색방법으로 key값이 없으면 key값보다 큰 가장 작은 요소를 찾는다. 

    동적 계획법보다는 개인적으로 더 쉽게(상대적으로) 다가온 것 같다.
    multiset과 여러 메서드들을 사용한 풀이가 신기하고 이런 것들을 많이 알고 있으면 문제 풀이가 더 쉬워질 거 같다는 생각을 했다.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int C;
int N;

int order(const vector<int>& russian, const vector<int>& korean) {

    int n = russian.size(), wins = 0;
    multiset<int> ratings(korean.begin(), korean.end()); // 한국 선수들 레이팅을 이진 탐색 트리로

    for(int rus = 0; rus < n; rus++) {

        // 한국선수 중 가장 높은 레이팅을 가진 선수가 아무 러시아 선수도 이길 수 없다면 
        // 어차피 질 거 가장 레이팅이 낮은 한국 선수를 매칭시킨다. 
        if(*ratings.rbegin() < russian[rus]) {
            ratings.erase(ratings.begin());

        // 그게 아닌 경우 현재 러시아 선수보다 레이팅이 높은 한국 선수들 중 가장 레이팅이 낮은 한국 선수와 경기시킨다.
        } else {
            ratings.erase(ratings.lower_bound(russian[rus]));
            wins++;
        }
    }

    return wins;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc=0;tc<C;tc++) {
        cin >> N;

        vector<int> korean;
        vector<int> russian;

        for(int i=0;i<N;i++) {
            int rus;
            cin >> rus;

            russian.push_back(rus);
        }

        for(int i=0;i<N;i++) {
            int kor;
            cin >> kor;

            korean.push_back(kor);
        }

        cout << order(russian, korean) << "\n";
    }

    return 0;
}