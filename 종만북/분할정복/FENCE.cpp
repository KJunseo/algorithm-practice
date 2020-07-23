/*
    분할 정복이 아직 익숙하지 않은게 분명하다.
    기저 사례를 생각해내는 것이 아직 많이 헷갈리고 재귀 호출부분도 아직 확실하게 하지 못하는 것 같다.

    풀이를 보고나면 이해가 되긴하는데 이런 생각을 어떻게 해내는지 모르겠다. 
    풀이를 참고하지 않고 풀어내고 싶다.
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int C;
int N;
vector<int> fence;

int solve(int left, int right) {
    
    // 기저 사례: 울타리가 하나인 경우는 그 울타리의 높이가 넓이가 된다.
    if(left==right) return fence[left];

    // 울타리를 반으로 나눈다.
    int mid = (left+right)/2;

    // mid를 기준으로 왼편의 넓이와 오른편의 넓이를 계산하여 더 큰 값을 ret에 저장해놓는다.
    int ret = max(solve(left, mid), solve(mid+1, right));

    // 최대 넓이 사각형이 중간지점에 걸쳐 있는 경우
    // low: 왼쪽으로 확장하기 위한 변수, high: 오른쪽으로 확장하기 위한 변수 
    int low = mid, high = mid+1;

    // 최대 사각형의 높이는 두 값 중 작은 값의 높이가 된다.(비스듬한 사각형이 불가능하기 때문에)
    int height = min(fence[low], fence[high]);

    // 중앙을 기준으로 양옆만 포함하는 경우(넓이=2)를 먼저 계산한다.
    ret = max(ret, height*2);

    // 전체 울타리를 탐색할때까지 반복한다.
    while(left<low || high < right) {

        // 항상 높이가 높은 쪽으로 확장한다.
        if(high < right && (low==left || fence[low-1] < fence[high+1])) { // 오른쪽으로 확장하는 경우
            high++;
            height = min(height, fence[high]);
        } else { // 왼쪽으로 확장하는 경우
            low--;
            height = min(height, fence[low]);
        }

        // 확장할 때마다 최대 넓이 계산
        ret = max(ret, height*(high-low+1));
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {
        cin >> N;

        fence.clear();

        for(int i=0;i<N;i++) {
            int h;

            cin >> h;

            fence.push_back(h);
        }

        cout << solve(0, fence.size()-1) << "\n";
    }

    return 0;
}