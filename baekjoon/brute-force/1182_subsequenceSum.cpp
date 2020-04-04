/*
    dfs를 써야할 거 같았는데 구현을 못하겠었다. 
    해당 부분에서의 합과, 시작점, 방문여부 등을 넘겨서 하면 되지 않을까라고 했는데 실패했다.

    종료조건은 n까지 모두 더했을 때이다.
    dfs를 수행하는 2가지 경우가 있다.
    1. 현재 가리키는 수를 더하는 것
    2. 현재 가리키는 수를 더하지 않는 것(이 부분을 생각하지 못했었다.)
    (그리고 구현 자체도 설계를 잘못했던 것 같다..)

    아직 혼자 힘으로 풀지는 못했었지만, 그래도 dfs가 떠올랐다는 점과, 대강 접근 방법이 유사했다는 점에서 의의를 두고, 계속 풀다보면 dfs 설계에 감이 올것이라고 생각한다.
*/
#include <stdio.h>

int n,s;
int num[20];
int cnt;

void dfs(int i, int sum) {
    if(i==n) return;
    if(sum+num[i]==s) cnt++;

    dfs(i+1, sum);
    dfs(i+1, sum+num[i]);
}

int main(void) {

    scanf("%d %d", &n, &s);

    for(int i=0;i<n;i++) {
        scanf("%d", &num[i]);
    }

    dfs(0, 0);

    printf("%d\n", cnt);

    return 0;
}