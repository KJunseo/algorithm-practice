/*
    처음에 갈피를 완전히 잘못 짚어, 출발지 기준 오름차순을 하여 풀이를 하려고 하다가 시간만 쓰고 실패하였다.

    도착지 기준으로 오름차순 정렬한다.(한 번 방문한 도시는 다시 방문하지 않기 때문이다.)
    각 마을 별 수용가능한 용량을 c로 초기화 해준다.
    그 후, 범위 별로 박스를 싣는다. 이때 범위에 포함되는 마을 중 남은 공간이 가장 작은 곳과, 박스의 용량을 비교하여,
    박스의 용량이 남아있는 공간보다 큰 경우는 남아있는 공간만큼만 싣는다.

    ex. 1번 마을에서 3번 마을로 10개를 보낸다고 가정하자.
    1번 마을 용량: c / 2번 마을 용량: c / 3번 마을 용량: c 이면,
    1번 마을 용량: c-10 / 2번 마을 용량: c-10 / 3번 마을 용량: c 을 해주면 된다.
    왜냐하면, 1번 마을에서 박스를 싣고, 2번마을에서도 여전히 박스가 실린 채로 있기 때문이다. 도착지에는 박스를 내리기 때문에 -10을 해주지 않는 것이다.

    초등부 문제를 맞이하게 될 때마다, 현타가 심하게 온다.. 초등학생은 이걸 어떻게 푸는 것인가.. 
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define M 10001

using namespace std;

bool compare(pair < pair<int, int> , int> &a, pair < pair<int, int> , int> &b) {
    if(a.first.second < b.first.second) return true;
    else if(a.first.second == b.first.second) {
        if(a.first.first < b.first.first) return true;
    }
    return false;
}

int main(void) {
    int n; // 마을 수
    int c; // 트럭 용량
    int m; // 보내는 박스 정보의 개수
    int from, to, num; // 보내는 마을, 받는 마을, 보내는 박스 수 
    int capacity[M];
    int maxNum=0;

    vector < pair < pair<int, int> , int> > a;

    scanf("%d %d", &n, &c);
    scanf("%d", &m);

    fill(capacity, capacity+M, c);

    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &from, &to, &num);
        a.push_back(make_pair(make_pair(from,to),num));
    }

    sort(a.begin(), a.end(), compare);

    for(int i=0;i<m;i++) {
        int f = a[i].first.first;
        int t = a[i].first.second;
        // 범위 중 남은 공간이 가장 작은 곳 찾기
        int smallest = capacity[f];
        for(int j=f+1;j<t;j++) {
            smallest = min(smallest, capacity[j]);
        }

        // 박스 싣기. 남은 공간보다 박스 용량이 크면 남은 공간만큼만 싣기(남은 용량이 크면 전부 싣기)
        int cnt=a[i].second;
        if(smallest<cnt) cnt=smallest;
        for(int j=f;j<t;j++) {
            capacity[j]-=cnt;
        }

        // 박스 내리기
        maxNum+=cnt;
    }

    printf("%d\n", maxNum);

    return 0;
}