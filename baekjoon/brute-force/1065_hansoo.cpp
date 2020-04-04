/*
    처음에 한수 개념을 이해하는 것이 조금 힘들었다.

    두 자리 수 일 경우에는 모두 한수이므로 ++해준다.
    세 자리 수는 각 자리의 수의 차를 구해 같으면 ++해준다.
    1000은 break 해주었다.
*/
#include <stdio.h>

int main(void) {
    int n;
    int num[3];
    int cnt=0;

    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        if(i<100) cnt++;
        else if(i==1000) break;
        else {
            int temp=i;
            for(int j=0;j<3;j++) {
                num[j]=temp%10;
                temp/=10;
            }
            if(num[1]-num[0] == num[2]-num[1]) cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}