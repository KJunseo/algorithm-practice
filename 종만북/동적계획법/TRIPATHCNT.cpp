/*
    이전에 했던 경로 찾기 문제에서 갯수를 세는 함수만 하나 추가하면 된다.
    이것도 DP이므로 저장소를 하나 더 생성한다.
    갈 수 있는 경로 중 최대 경로인 곳으로 가면서 갯수를 더해준다.
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
int countCache[101][101];

int path(int y, int x) {

    // 기저 사례: 가장 밑에 도착한 경우 그 자리의 값 리턴 
    if(y==n) return triangle[y][x];

    // 메모이제이션
    int& ret = cache[y][x];
    if(ret!=-1) return ret;

    return ret = max(path(y+1, x+1), path(y+1, x)) + triangle[y][x];
}

int count(int y, int x) {

    // 기저 사례: 맨 아래에 도착하는 경우
    if(y == n) return 1;

    // 메모이제이션 
    int& ret = countCache[y][x];
    if(ret != -1) return ret;

    ret = 0;

    // 갈수있는 경로 중 큰 경로에 따라 값이 달라짐. 같은 경우는 두 경우 모두 더해주기
    if(path(y+1, x+1) >= path(y+1, x)) ret += count(y+1, x+1);
    if(path(y+1, x+1) <= path(y+1, x)) ret += count(y+1, x);

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));

        cin >> n;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                cin >> triangle[i][j];
            }
        }

        cout << count(1, 1) << "\n";
    }

    return 0;
}