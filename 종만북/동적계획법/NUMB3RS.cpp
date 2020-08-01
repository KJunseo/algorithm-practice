/*
    동적 계획법을 사용할 때 탐색 방향을 바꾸면 시간 복잡도가 많이 달라질 수도 있다는 것을 알게되었다.
    동적 계획법 파트는 꼭 익숙해져야겠다는 생각이들었다..
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int C;
int n, d, p;
int t, q;
int connected[51][51], deg[51];
double cache[51][101];

// 탐색하고자 하는 마을로부터 시작하여 거꾸로 답을 구하는 방법 
double search(int here, int days) {

    // 기저 사례: 출발일로 돌아왔을 때 교도소이면 1.0 아니면 0
    if(days == 0) return (here == p ? 1.0 : 0.0);

    // 메모이제이션
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;

    ret = 0.0;
    for(int there = 0; there < n; there++) {
        // 인접한 마을이면
        if(connected[here][there]) {
            ret += search(there, days-1) / deg[there];
        }
    } 

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc=0;tc<C;tc++) {
        cin >> n >> d >> p;

        // 초기화
        for(int i=0;i<50;i++) {
            for(int j=0;j<100;j++) {
                cache[i][j] = -1.0;
            }
        }

        memset(deg, 0, sizeof(deg));

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> connected[i][j];
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                deg[i] += connected[i][j];
            }
        }

        cin >> t;

        for(int i=0;i<t;i++) {
            cin >> q;

            cout.precision(8);
            cout << search(q, d) << " ";
        }
        cout << "\n";
    }

    return 0;
}