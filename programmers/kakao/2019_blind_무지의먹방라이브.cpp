/*
    정확성은 시간 기준으로 for문을 증가시키면서, 다음 먹을 음식을 찾으면 된다.

    효율성까지 통과하기 위해서는 아래와 같이 한다.

    먼저 음식 시간 별로 정렬한다.(인덱스와 시간을 합쳐서)
    예를 들어

    [3, 1, 2] 를 [1, 2, 3]으로 정렬하면

    *               *
    *   *  ->     * *
    * * *       * * *
    
    이런식으로 된다. 이럴 경우 한번에 시간을 3초 씩 셀 수 있다.(맨 밑을 모두 제거 가능)
          *
        * *   ->      *
      * * *         * *
    
    그 후, 가장 먹는 시간이 적은 음식의 높이를 기준으로 한 번에 먹을 수 있는 음식 양을 계산하여,
    그 수만큼 시간을 빼준다.(1초에 하나씩 먹으므로)
    먹을 수 있는 음식이 없으면 continue, 남은 k보다 작으면 빼주고, 남은 k보다 클 경우, 다시 원래 순서로 sort 후, 순서를 알아낸다.
    그 후, 순서에 맞는 음식 인덱스를 출력시킨다.

    2018년 문제들에 비해 많이 어려운 것 같다. 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int> > foods; // <먹는 시간, 먹는 순서>
    int total = food_times.size();

    for(int i=0;i<total;i++) {
        foods.push_back(make_pair(food_times[i], i+1)); // 1번 부터 시작
    }

    sort(foods.begin(), foods.end()); // 먹는 시간 기준으로 오름차순 정렬

    int beforetime = 0; // 이전 시간(이전 시간과의 차이 계산하기 위함)
    for(auto it=foods.begin();it!=foods.end();it++, total--) {
        long long eat = (long long)(it->first - beforetime) * total; 
        if(eat==0) continue;
        if(eat<=k) {
            k-=eat; // 먹은 만큼 k 빼주기
            beforetime = it->first; // 이전 시간 업데이트
        } else {
            k%=total; // 순서 알아내기 위함
            sort(it, foods.end(), compare); // 원래 순서로 다시 sort
            return (it+k)->second;
        }
    }

    return -1;
}