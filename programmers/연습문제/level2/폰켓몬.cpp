/*
    조합을 사용하는 문제라고 생각했고 next_permutation을 이용해 구현했으나
    테스트 7번부터 모두 시간초과가 나버렸다.

    잘 생각해보면 폰켓몬의 종류가 모두 다른 경우는 N/2 만큼 잡을 수 있고
    제일 적게 잡을 수 있는 경우는 모두 종류가 같은 경우이다.
    set은 중복 제거가 되기 때문에 N까지 모든 폰켓몬을 set에 넣어주고
    N/2와 set.size() 중에 작은 값이 정답이다. 
*/
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    set<int> s;
    
    for(int i=0;i<nums.size();i++) {
        s.insert(nums[i]);
    }
    
    return min(s.size(), nums.size()/2);
}