/*
    풀이를 보면서 이해는 하였지만, 혼자힘으로 풀기는 역부족인 문제였다.
    부분합을 이용해서 합을 구하는 방법과 sum(A[i]-m)^2 을 이용하는 방법은 지금 실력으로는 생각할 수 없었다.

    먼저 숫자를 정렬한다. 같은 수로 양자화되는 수들은 항상 인접해있기 때문이다.
    그리고 '수열의 from에서 조각 크기만큼 자른 수열의 최솟값' + 'from+조각크기 다음부터 다시 양자화' 이렇게 나누는 걸 생각하는 게 핵심이었다.
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int C;
int n, s;
int A[101];
int pSum[101]; // A[]의 부분합을 저장. ex) pSum[5] = A[0]...A[5] 까지의 합
int psqSum[101]; // A[]제곱의 부분합을 저장. ex) psqSum[5] = A[0]^2...A[5]^2 의 합
int cache[101][11];

int minError(int lo, int hi) {
    
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]); // A[lo]...A[hi] 까지의 합 
    int sqSum = psqSum[hi] - (lo == 0 ? 0 : psqSum[lo-1]); // A[lo]^2...A[hi]^2 까지의 합 

    // 평균을 반올림한 값으로 이 수들을 표현
    int m = int(0.5 + (double)sum / (hi - lo + 1));

    // sum(A[i]-m)^2 을 전개한 결과를 부분 합으로 표현
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo +1);

    return ret;
}

// 양자화. from: 시작 위치, parts: 조각 낼 수 있는 갯수
int quantize(int from, int parts) {

    // 기저 사례: 모든 숫자를 다 양자화 한 경우
    if(from == n) return 0;

    // 기저 사례: 수열의 숫자는 남았는데, 더 묶을 수 없는 경우 아주 큰 값 반환
    if(parts == 0) return INF;

    // 메모이제이션
    int& ret = cache[from][parts];
    if(ret != -1) return ret;

    ret = INF;

    for(int partSize=1;from+partSize<=n;partSize++) {
        ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
    }

    return ret;
}

// 초기화 
void init() {

    memset(cache, -1, sizeof(cache)); // 캐시 비우기

    sort(A, A+n); // 정렬 

    // pSum, psqSum 미리 만들기
    pSum[0] = A[0];
    psqSum[0] = A[0] * A[0];

    for(int i=1;i<n;i++) {
        pSum[i] = pSum[i-1] + A[i];
        psqSum[i] = psqSum[i-1] + A[i] * A[i];
    }
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {
        cin >> n >> s;

        for(int i=0;i<n;i++) {
            cin >> A[i];
        }

        init(); // 초기화

        cout << quantize(0, s) << "\n";
    }

    return 0;
}