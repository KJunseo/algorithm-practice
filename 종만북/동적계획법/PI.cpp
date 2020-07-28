/*
    종만북 문제를 풀다보면 (하) 난이도지만 너무 어렵게 느껴진다.
    내가 너무 준비가 안 된 상태에서 시작한건가 싶기도 하다.
    하지만 일단 시작했으니 끝까지 해보려고한다.
    한 번 정독 후 다시 풀어보든지 해야겠다.

    문제를 부분 문제로 나누는 게 아직 감이 잘 안온다.
    이 문제인 경우 '자른 문자열 이후의 나머지 문자열의 난이도 최적해' + '자른 문자열 구간의 난이도 최적해' 로 나누어 구현하면 된다.
    빨리 동적 계획법 감을 잡아 잘하고 싶다..
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define INF 987654321

using namespace std;

int C;
string number;
int cache[10001];

// 숫자의 [a..b] 구간의 난이도를 반환하는 함수 
int classify(int a, int b) {

    // 전체 숫자를 [a..b] 구간으로 자른다.
    string subNum = number.substr(a, b-a+1);

    // 모든 숫자가 같은 경우 난이도는 1
    if(subNum == string(subNum.size(), subNum[0])) return 1;

    // 등차 수열을 판단 
    bool progressive = true;
    for(int i=0;i<subNum.size()-1;i++) {
        if(subNum[i+1]-subNum[i] != subNum[1]-subNum[0]) progressive = false;
    }

    // 등차 수열이면서 공차가 1 또는 -1인 경우 난이도는 2
    if(progressive && abs(subNum[1]-subNum[0])==1) return 2;

    // 두 수가 번갈아 등장하는지 확인
    bool alternating = true;
    for(int i=0;i<subNum.size();i++) {
        if(subNum[i]!=subNum[i%2]) alternating = false;
    }

    // 두 수가 번갈아 등장하면 난이도는 4
    if(alternating) return 4;

    // 공차가 1 또는 -1이 아닌 다른 등차 수열인 경우 난이도는 5
    if(progressive) return 5;

    // 나머지 모든 경우는 난이도 10
    return 10;
}

int memorize(int index) {

    // 기저 사례: 수열의 끝에 도달했을 경우 종료 
    if(index == number.size()) return 0;

    // 메모이제이션
    int& ret = cache[index];
    if(ret!=-1) return ret;

    ret = INF;
    for(int L=3;L<=5;L++) { // 3 ~ 5 사이의 길이로만 자를 수 있기 때문에 
        if(index+L<=number.size()) {
            ret = min(ret, memorize(index+L)+classify(index, index+L-1));
        }
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));

        cin >> number;

        cout << memorize(0) << "\n";
    }

    return 0;
}