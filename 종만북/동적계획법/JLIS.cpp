/*
    풀이를 봐야만 풀어내고 있다..
    풀이를 보면 이해는 되지만, 내가 스스로 이런 방식을 생각해서 구현하기까지는 실력이 많이 모자른 것 같다.
    그래도 계속 하다보면 언젠가는 될거라고 생각한다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min(); // 아주 작은 값 표현(64비트 정수): 32비트 부호있는 정수 전체이기 때문에

int c;
int n, m;
int A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB) {

    // 메모이제이션
    int& ret = cache[indexA+1][indexB+1]; // -1부터 실행하였으므로 +1 해주기(A[-1] == B[-1] == -INF)
    if(ret!=-1) return ret;

    ret=2; // A[indexA]와 B[indexB]는 이미 존재하므로 +2부터 시작 
    long long a = (indexA==-1 ? NEGINF : A[indexA]);
    long long b = (indexB==-1 ? NEGINF : B[indexB]);
    long long maxElement = max(a, b);

    // 다음 원소부터 찾아서 현재 기준(maxElement)보다 큰 값이 있는 경우 재귀 호출
    for(int nextA=indexA+1;nextA<n;nextA++) {
        if(maxElement < A[nextA]) ret = max(ret, jlis(nextA, indexB)+1);
    }

    for(int nextB=indexB+1;nextB<m;nextB++) {
        if(maxElement < B[nextB]) ret = max(ret, jlis(indexA, nextB)+1);
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> c;

    for(int t=0;t<c;t++) {

        memset(cache, -1, sizeof(cache));

        cin >> n >> m;

        for(int i=0;i<n;i++) {
            cin >> A[i];
        }

        for(int i=0;i<m;i++) {
            cin >> B[i];
        }

        cout << jlis(-1, -1)-2 << "\n";
    }

    return 0;
}