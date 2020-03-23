/*
    다 풀어놓고 어이없게 삽질을 많이했다 ㅎ..
    덱의 요소를 비교할 때, 덱의 사이즈로 for문을 돌려야했는데, n만큼 돌려버려서 런타임오류가 자꾸 났었다 ㅎㅎㅎㅎ...

    다른 풀이를 찾아보니 우선순위 큐도 많이 사용하는 것 같다.
*/
#include <stdio.h>
#include <queue>
#define MAX 100

using namespace std;

deque <pair<int, int> > dq;
int result[MAX];
int value[MAX];
int main(void) {
    int testNum;
    int n, m;
    int p;
    bool flag = false;

    scanf("%d", &testNum);

    for(int i=0;i<testNum;i++) {
        scanf("%d %d", &n, &m);

        for(int j=0;j<n;j++) {
            scanf("%d", &p);
            dq.push_back(make_pair(j,p));
        }

        int idx=1;
        while(!dq.empty()) {
            flag=false;
            pair<int, int> x = dq.front();
            for(int j=0;j<dq.size();j++) {
                if(x.second < dq[j].second) {
                    flag=true;
                    dq.pop_front();
                    dq.push_back(x);
                    break;
                }
            }
            if(!flag) {
                dq.pop_front();
                result[x.first]=idx++;
            }
        }
        value[i]=result[m];
    }

    for(int i=0;i<testNum;i++) {
        printf("%d\n", value[i]);
    }

    return 0;
}