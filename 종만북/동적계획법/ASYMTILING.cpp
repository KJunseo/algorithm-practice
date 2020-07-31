/*
    두 가지 접근 방법이 있다.
    1. 전체에서 대칭인 것을 빼는 경우
    2. 비대칭인 것을 세는 경우

    1번 방법으로 풀었다. 이떄 주의할 점은 tiling값으로 계산할 때 음수가 나올 수 있기 때문에 MOD를 더해주어 음수를 방지한다.
    어차피 MOD로 나눈 나머지를 반환하므로 MOD를 더해줘도 답에는 변화가 없다.

    대칭인 경우는 
    1. 짝수
        - 중간에 타일 2개가 옆으로 있는 경우
        - 딱 반으로 나뉘는 경우
    2. 홀수 
        - 중간에 타일 하나가 세워진 경우

    2번 방법도 asymmetric2로 첨부하였다.
    양 끝을 타일로 채워가면서 비대칭인 부분만 세어준다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std;

int C;
int n;
int cache[101];
int cache2[101];

int tiling(int width) {

    // 기저 사례: width가 1만 남은 경우는 경우의 수 1
    if(width <= 1) return 1;

    // 기저 사례: width가 2만 남은 경우는 경우의 수 2
    if(width == 2) return 2;

    // 메모이제이션
    int& ret = cache[width];
    if(ret != -1) return ret;

    return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}

// 전체 - 대칭인 부분
int asymmetric(int width) {

    int ret = tiling(width);

    // 홀수인 경우 
    if(width%2 == 1) return (ret - tiling(width/2) + MOD) % MOD;

    // 짝수인 경우
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling(width/2-1) + MOD) % MOD;

    return ret;
}

// 비대칭인 부분 바로 구하기
int asymmetric2(int width) {

    // 기저 사례
    if(width <= 2) return 0;

    // 메모이제이션
    int& ret = cache2[width];
    if(ret != -1) return ret;

    // 남은 부분을 덮는 방법 찾기. 나머지 부분이 대칭이 아니어야 함
    ret = asymmetric2(width-2) % MOD;
    ret = (ret + asymmetric2(width-4)) % MOD;

    // 남은 부분을 덮는 방법 찾기. 어차피 이미 대칭이 아니므로 대칭이든지 아니든지 상관 없음
    ret = (ret + tiling(width-3)) % MOD; 
    ret = (ret + tiling(width-3)) % MOD;

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));

        cin >> n;

        cout << asymmetric(n) << "\n";
        // cout << asymmetric2(n) << "\n";
    }

    return 0;
}