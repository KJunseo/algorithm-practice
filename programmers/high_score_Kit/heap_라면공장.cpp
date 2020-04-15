/*
    너무 어렵게 생각했었던 것 같다..
    dates와 supplies를 pair로 묶어서 빠른 날짜가 top에 오게끔 pq에 넣고,
    빼면서 비교했었는데, 실패했다. 설계부터 잘못했던 것 같다.

    중요한 것은, 공급 가능한 여러 날이 지나는 경우, stock이 0이 되면, 
    여러 날 중 가장 많이 공급 받을 수 있는 것을 골라 공급을 받아야한다는 것이다.

    일단 공급 가능한 날이 되면 무조건 pq(max heap)에 넣고,
    날짜(k)를 기준으로 반복시키면서, stock이 0이 되는 경우,
    pq의 top을 꺼내서 stock에 추가한다.
*/
#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int index=0;
    
    // 목표 날짜 까지 반복
    for(int i=0;i<k;i++) {

        // 많이 공급 받을 수 있는 만큼 pq에 넣어줌(max heap)
        if(dates[index]==i) {
            pq.push(supplies[index]);
            index++;
        }
        
        // 재고가 없으면 
        if(stock==0) {
            stock=pq.top(); // 가장 많이 공급 받을 수 있는 것을 공급 받음
            pq.pop();
            answer++;
        }

        stock--; // 하루에 1톤씩 소모
    }
    
    return answer;
}

int main(void) {
    vector<int> dates;
    vector<int> supplies;

    dates.push_back(4);
    dates.push_back(10);
    dates.push_back(15);

    supplies.push_back(20);
    supplies.push_back(5);
    supplies.push_back(10);

    int ans = solution(4, dates, supplies, 30);

    printf("%d\n", ans);

    return 0;
}
