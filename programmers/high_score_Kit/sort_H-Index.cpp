/*
    문제를 이해하기가 어려웠지 문제 자체는 쉬운편이었다.
    논문의 수만큼 반복하면서 
    H-index를 업데이트 해주면 되는 문제였다.

    내림차순 정렬 후, 인덱스 비교를 통해서 풀 수도 있었다.
    Ex  [1, 7, 0, 1, 6, 4] 일 때,
        index   인용 수
          0       7
          1       6
          2       4
        * 3       1 *
          4       1
          5       0

          index 3에서 최초로 인용수가 index보다 작아졌다. 
          즉, 이때 3보다 인용을 많이 한 수가 3보다 작은 index의 값 들이므로 자연스럽게 3이 정답이된다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int num=citations.size();
    int cnt=0;
    
    sort(citations.begin(), citations.end());
    
    for(int i=num;i>=0;i--) {
        cnt=0;
        for(int j=0;j<num;j++) {
            if(i<=citations[j]) cnt++;
        }
        if(cnt>=i) {
            answer=i;
            break;
        }
    }
    
    return answer;
}

// 내림차순 후 index 비교방법
int solution(vector<int> citations) {
    int index=0;
    
    sort(citations.begin(), citations.end(), greater<int>());

    while(index < citations.size()) {
        if(citations[index]<=index) break;
        index++;
    }

    return index;
}