/*
    각 부분 문제의 최적해가 전체의 최적해로 이어질 경우 최적 부분 구조를 가진다.
    이 문제의 경우 어떤 경로로 한 지점의 부분 문제에 도달했다고 해도 남은 부분문제에 아무 영향을 끼치지 않는다.
    즉, 각 부분 문제의 최적해만 있으면 전체 문제의 최적해를 쉽게 알아낼 수 있는 문제이다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int C;
int n;
int triangle[101][101];
int cache[101][101];

int path(int y, int x) {

    // 기저 사례: 가장 밑에 도착한 경우 그 자리의 값 리턴 
    if(y==n) return triangle[y][x];

    // 메모이제이션
    int& ret = cache[y][x];
    if(ret!=-1) return ret;

    return ret = max(path(y+1, x+1), path(y+1, x)) + triangle[y][x];
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));

        cin >> n;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                cin >> triangle[i][j];
            }
        }

        cout << path(1, 1) << "\n";
    }

    return 0;
}