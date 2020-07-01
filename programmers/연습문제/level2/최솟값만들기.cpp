/*
    예제를 보니 가장 작은 수와 가장 큰 수를 곱했을 때가 최소가 되길래
    A는 오름차순, B는 내림차순으로 정렬 후
    각 요소를 곱한 값을 더해주니 정답이었다.
*/
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0;i<A.size();i++) {
        answer+=A[i]*B[i];
    }
    
    return answer;
}