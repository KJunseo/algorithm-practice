/*
    9명의 키를 모두 더하고, 그 값에서 100을 뺀 값을 2명으 키로 나타낼 수 있는 경우를 찾아서 빼주면 된다.

    결과물이 오름차순으로 정렬되야 하므로, 먼저 오름차순 정렬을 해준 다음,
    이중 for문으로 두 명의 난쟁이를 뽑아 합이 9명의 키의 합 - 100 인 값을 찾으면 된다.
    
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int height[9];
    int sum=0;
    int i,j;
    bool flag=false;

    for(int i=0;i<9;i++) {
        scanf("%d", &height[i]);
        sum+=height[i];
    }

    sort(height, height+9);

    int num = sum-100;
    for(i=0;i<9;i++) {
        for(j=1;j<9;j++) {
            if(height[i]+height[j]==num) {
                flag=true;
                break;
            }
        }
        if(flag) break;
    }


    for(int k=0;k<9;k++) {
        if(k==i || k==j) continue;
        printf("%d\n", height[k]);
    }

    return 0;
}