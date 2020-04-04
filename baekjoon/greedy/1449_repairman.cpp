/*
    고장난 곳을 오름차순 정렬 했을 때, 뒤에서 앞의 값을 뺀 것과 테이프 길이 - 1(좌우 각각0.5)를 비교하여 카운트 하려고 하였으나 실패헸다.

    만약, 1번이 고장났고, 테이프 길이가 4이면, 1부터 4번 위치까지는 하나의 테이프로 해결할 수 있다.
    따라서, 굳이 뒤에서 앞의 값을 빼면서 계산할 필요가 없다.

    고민은 엄청하고 시도도 엄청하였지만, 실패하니 현타가 오고, 풀이를 보니 너무 간단해서 또 현타가 온다....
    언제 알고리즘에 감이 올지 잘 모르겠다.

*/
#include <stdio.h>
#include <algorithm>
#define MAX 1001

using namespace std;

int loc[MAX];

int main(void) {
    int n; // 물이 새는 곳의 수
    int l; // 테이프 길이
    int cnt=0;
    int complete;

    scanf("%d %d", &n, &l);

    for(int i=0;i<n;i++) {
        scanf("%d", &loc[i]);
    }

    sort(loc, loc+n);

    complete = 0;

    for(int i=0;i<n;i++) {
        //  다음 고장난 파이프가 아직 수리되지 않았다면, 
        if(complete<loc[i]) {
            complete=loc[i]+l-1; // 그 고장난 파이프 부터 테이프길이 - 1까지는 테이프 하나를 써서 수리 완료
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}