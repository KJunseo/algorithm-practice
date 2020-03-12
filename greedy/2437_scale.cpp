/*
    생각을 많이 해봤는데 잘 모르겠었다. 출처가 한국 정보 올림피아드 초등부인데, 못 풀겠어서 현타가 왔다....

    누적합을 사용해서 값을 구한다. 
    1. 입력받은 저울추들을 오름차순으로 정렬한다.
    2. 다음 저울추가 누적합+1 보다 크면 누적합+1의 값은 만들 수 없는 것이다.
        예를들어 다음 저울추의 값이 7이고, 이때까지 누적합이 5이면, 7은 만들 수 있지만, 6이라는 값을 만들어낼수 없기 때문이다. 
*/
#include <stdio.h>
#include <algorithm>
#define MAX 1001

using namespace std;

int amount[MAX];

int main(void) {

    int num;
    int sum=0;

    scanf("%d", &num);

    for(int i=1;i<=num;i++) {
        scanf("%d", &amount[i]);
    }

    sort(amount, amount+num+1);
    
    for(int i=1;i<=num;i++) {
        if(amount[i]>sum+1) break;
        sum+=amount[i];
    }

    printf("%d\n", sum+1);

    return 0;
}