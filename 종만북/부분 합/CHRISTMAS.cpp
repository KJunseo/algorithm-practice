/*
    H에서 T 구간의 선물을 나머지 없이 모두 나눠주려면 mod K 가 0이어야 된다는 것이 중요한 문제였다.
    psum을 일반적인 부분합이 아닌 부분합 mod K 를 한 값으로 한다.

    2개의 부분 문제로 나누어져있다.
    1번 문제같은 경우는 이해를 하긴했지만, 2번 문제는 이해가 잘 안간다.. 
    나중에 다시 봐야할 것 같다.. 종만북을 보면서 자괴감이 너무 드는 것 같다. 그래도 2번째 볼때는 지금보다는 나으리라 생각한다.
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int C;
int N, K; // N: 인형 상자의 개수, K: 어린이의 수 

int waysToBuy(const vector<int>& psum) {
    const int MOD = 20091101;
    int ret = 0;

    // psum의 각 값의 빈도 계산
    vector<long long> count(K, 0);
    for(int i = 0; i < psum.size(); i++) {
        count[psum[i]]++;
    }

    // 두 번 이상 본 적 있다면 이 값 중 두 개를 선택하는 방법의 수를 더한다. 
    for(int i = 0; i < K; i++){
        if(count[i] >= 2) {
            ret = (ret + ((count[i] * (count[i] -  1)) / 2)) % MOD;
        }
    }

    return ret;
}

int maxBuys(const vector<int>& psum) {
    
    // ret[i]: 첫 번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 횟수 
    vector<int> ret(psum.size(), 0);

    // prev[s]=psum[]이 s였던 마지막 위치
    vector<int> prev(K, -1);
    for(int i = 0; i < psum.size(); i++) {

        // i 번째 상자를 고려하지 않는 경우 
        if(i > 0) 
            ret[i] = ret[i-1];
        else 
            ret[i] = 0;

        int loc = prev[psum[i]]; // psum[i]를 전에도 본 적이 있으면, prev[psum[i]]+1 부터 여기까지 쭉 사 본다.
        if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);

        prev[psum[i]] = i; // prev[]에 현재 위치를 기록한다. 
    }

    return ret.back();
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N >> K;

        vector<int> box(N);
        for(int i = 0; i < N; i++) {
            cin >> box[i];
        }

        vector<int> psum(N+1);
        psum[0] = 0;

        for(int i = 1; i <= N; i++) {
            psum[i] = (psum[i-1] + box[i-1]) % K;
        }

        cout << waysToBuy(psum) << " " << maxBuys(psum) << "\n";
    }

    return 0;
}