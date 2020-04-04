/*
    반복문을 통해 next_permutation를 사용하여 출력했다. 
    지저분하긴 하지만 어찌저찌 구현하여 테스트케이스는 통과하였는데, 시간초과가 났다...

    dfs(재귀)로 풀 수 있다.

    재귀부분은 진짜 너무 감이 안온다..
*/
#include <stdio.h>
#define MAX 13

using namespace std;

int lotto[MAX];
int c[MAX];
int k;
void dfs(int start, int depth) {
    // 깊이가 6이 되면 출력해준다.
    if(depth==6) {
        for(int i=0;i<6;i++) {
            printf("%d ", c[i]);
        }
        printf("\n");
        return;
    }

    for(int i=start;i<k;i++) {
        c[depth]=lotto[i];
        dfs(i+1, depth+1);
    }
}

int main(void) {

    while(1) {
        scanf("%d", &k);
        if(k==0) break;
        for(int i=0;i<k;i++) {
            scanf("%d", &lotto[i]);
        }
        dfs(0,0);
        printf("\n");
    }

    return 0;
}