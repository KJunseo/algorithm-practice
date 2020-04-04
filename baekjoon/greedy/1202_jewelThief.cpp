/*
    결과는 정확하게 나왔지만, 시간 초과를 해결하지 못했다.

    그리디에 우선순위 큐(힙)를 사용했어야 했다.
    우선 순위 큐는 루트가 항상 가장 큰 값이다. 가방을 기준으로, 첫 번째 가방에 들어갈 수 있는 모든 보석을 우선순위 큐에 넣고, root의 값을 더해준다.
    보석의 index를 사용하여, 이미 더해진 값은 다음 가방에서 검사하지 않는다. 
    
    값을 int로 하니 틀렸다고 떴다. long long 타입을 사용해야 했다. (출력도 %lld로 하지 않으면 실패한다)
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue <int> pq; // Max Heap 사용 

int main(void) {
    int n,k;
    int weight,price;
    long long total=0;

    vector <pair<int, int> > jewel;
    vector <int> bag;

    scanf("%d %d", &n, &k);

    for(int i=0;i<n;i++) {
        scanf("%d %d", &weight, &price);
        jewel.push_back(make_pair(weight, price));
    }

    for(int i=0;i<k;i++) {
        scanf("%d", &weight);
        bag.push_back(weight);
    }

    // 오름차순 정렬 
    sort(jewel.begin(), jewel.end()); // 무게 기준 오름차순 정렬
    sort(bag.begin(), bag.end()); // 가방 오름차순 정렬

    int idx=0; // 보석 인덱스 
    for(int i=0;i<k;i++) {
        while(idx<n && jewel[idx].first<=bag[i]) {
            pq.push(jewel[idx++].second); // 우선 순위 큐에 보석의 가격을 넣어줌 
        }
        if(!pq.empty()) { // 우선 순위 큐가 차있으면, 더해준다.
            total+=pq.top();
            pq.pop();
        }
    }

    printf("%lld\n", total);

    return 0;
}