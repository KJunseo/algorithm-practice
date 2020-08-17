/*
    코드를 보면서 집중해보면 이해는 되긴하는데 내가 응용해서 적용하기까지는 아직 시간이 필요할 것 같다.
    비트를 이용해 각 과목을 추가, 삭제 하는 부분이 흥미로웠다.

    다만 조건문에 쓰거나, 순회하는 방법은 아직도 헷갈린다..
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
#define MAXN 12

using namespace std;

int n, k, m, l; // n: 전공 과목 수, k: 들어야 하는 과목의 수, m: 학기의 수, l: 한 학기에 최대로 들을 수 있는 과목의 수
int prerequisite[MAXN]; // i 번째 과목의 선수 과목의 집합
int classes[10]; // i번째 학기에 개설되는 과목의 집합
int cache[10][1<<MAXN];

// x를 이진수로 표현 후 1의 갯수
int bitCount(int x) {
    if(x == 0) return 0;
    return x%2 + bitCount(x/2);
}

// semester: 이번 학기, taken: 지금까지 들은 과목의 집합
// k개 이상의 과목을 모두 들으려면 필요한 학기의 수를 return. 불가능할 경우 INF 리턴
int graduate(int semester, int taken) {

    // 기저 사례: k개 이상의 과목을 이미 들은 경우
    if(bitCount(taken) >= k) return 0;

    // 기저 사례: 학기가 모두 지난 경우 
    if(semester == m) return INF;

    int& ret = cache[semester][taken];
    if(ret != -1) return ret;

    ret = INF;
    int canTake = (classes[semester] & ~taken); // 이번학기에 열리는 과목 중 아직 듣지 않은 과목 찾기 

    // 선수 과목을 듣지 않은 과목들 제외시키기 
    for(int i = 0; i < n; i++) {
        if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i]) {
            canTake &= ~(1 << i);
        }
    }

    // 이 집합의 모든 부분 집합을 순회
    for(int take = canTake; take > 0; take = ((take - 1) & canTake)) {
        if(bitCount(take) > l) continue; // 한 학기에 l과목 까지만 들을 수 있다.
        ret = min(ret, graduate(semester+1, taken | take) + 1);
    }

    ret = min(ret, graduate(semester+1, taken)); // 이번 학기에 아무 과목도 듣지 않는 경우(휴학)
    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    int C;
    cin >> C;

    for(int tc = 0;tc < C; tc++) {

        // 초기화 
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));
        memset(cache, -1, sizeof(cache));

        cin >> n >> k >> m >> l;

        for(int i = 0; i < n; i++) {
            int preSubjectNum;
            cin >> preSubjectNum;

            for(int j = 0; j < preSubjectNum; j++) {
                int subject;
                cin >> subject;

                prerequisite[i] |= (1 << subject); // i번째 과목의 선수 과목 집합에 추가 
            }
        }

        for(int i = 0; i < m; i++) {
            int subjectNum;
            cin >> subjectNum;

            for(int j = 0; j < subjectNum; j++) {
                int subject;
                cin >> subject;

                classes[i] |= (1 << subject); // i번째 학기에 개설되는 과목에 추가
            }
        }

        int ret = graduate(0, 0);

        if(ret == INF) cout << "IMPOSSIBLE";
        else cout << ret;
        cout << "\n";
    }

    return 0;
}