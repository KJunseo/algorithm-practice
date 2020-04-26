/*
    효율성까지 보는 문제들은 아직 효율성 만족을 못시키겠다.
    모의고사를 풀 때 효율성을 통과하지 못할 걸 알았지만, 완전탐색으로 시도하다가 결국 효율성을 통과하지 못했다.

    이분 탐색을 하는 문제였다.
    건너갈 수 있는 사람의 수를 기준으로 이분탐색을 한다.
    연속된 음수(건널 수 없는 징검다리)의 수가 연속하여 k개 있으면, 건널 수 없는 경우이다.
    건널 수 있는 사람의 수를 M이라고 할 때, M-1명 까지는 건넜다고 가정한다. 
    따라서 '각 징검다리의 수 - M' 이 0보다 작은 경우를 카운트해주고 연속하여 음수가 k개 이상 나오면,
    불가능한 경우이므로 end를 M-1로 해준다. 
    그 반대라면 start를 M+1로 해준다.

    이분 탐색은 항상 기준을 뭐로 잡을지가 어려운 것 같다.
*/
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> stones, int mid, int k) {
    int cnt=0; // 연속되는 음수의 수 

    for(int i=0;i<stones.size();i++) {
        // mid명을 수용하지 못한다면 cnt
        if(stones[i]-mid<=0) 
            cnt++;
        // 연속된 갯수를 찾아야하므로 중간에 하나라도 0보다 큰 값이 있는 경우 0으로 초기화 
        else 
            cnt=0;

        // 연속된 수가 k이상이면 불가능한 경우
        if(cnt==k) return false; 
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int start=1;
    int end=2000000000;
    
    while(start<=end) {
        int mid = (start+end)/2; // 건너갈 수 있는 사람의 수
        
        // 연속되는 음수의 수가 k보다 작다면 
        if(check(stones, mid, k))
            start=mid+1; // 건너갈 수 있는 사람의 수 증가 
        else 
            end=mid-1; // 건너갈 수 있는 사람의 수 감소
    }
    
    return start;
}