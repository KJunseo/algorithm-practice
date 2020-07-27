/*
    문제 풀이를 보면 어떻게 저런 생각을 해내는지 신기하다.
    나는 아직 풀이를 봐야만 그런 흐름을 알 수 있는 것 같다.
    재귀적으로 생각하는 것과 그것을 표현하는 것이 조금 힘들다.

    최적화 문제 동적 계획법 레시피는 아래와 같다.
    1. 모든 답을 만들어 보고 그중 최적해의 점수를 반환하는 완전탐색 알고리즘 설계
    2. 전체 답 x, 앞으로 남은 선택들에 해당하는 점수만 반환 
    3. 꼭 필요한 정보만 남기고, 중복되는 부분 문제 많이 만들기
    4. 배열이나 문자열은 가능하다면 변환(인덱스로 표현 등)
    5. 메모이제이션
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int C;
int N;
int S[500];
int cache[501];

int list(int start) {

    // 메모이제이션
    int& ret = cache[start+1]; // -1부터 실행하였으므로 start+1
    if(ret!=-1) return ret;

    ret = 1; // S[start]는 항상 존재하므로 최소 1이상 
    for(int i=start+1;i<N;i++) {

        // -1이거나 더 큰 수의 인덱스를 찾는 경우
        if(start==-1 || S[start]<S[i]) { 
            ret = max(ret, list(i)+1);
        }
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    
    cin >> C;

    for(int t=0;t<C;t++) {

        memset(cache, -1, sizeof(cache));

        cin >> N;

        for(int i=0;i<N;i++) {
            cin >> S[i];
        }

        cout << list(-1)-1 << "\n";
    }

    return 0;
}