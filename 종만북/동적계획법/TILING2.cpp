#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std;

int C;
int n;
int cache[101];

int tiling(int width) {

    // 기저 사례: width가 1만 남은 경우는 경우의 수 1
    if(width == 1) return 1;

    // 기저 사례: width가 2만 남은 경우는 경우의 수 2
    if(width == 2) return 2;

    // 메모이제이션
    int& ret = cache[width];
    if(ret != -1) return ret;

    return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));

        cin >> n;

        cout << tiling(n) << "\n";
    }

    return 0;
}