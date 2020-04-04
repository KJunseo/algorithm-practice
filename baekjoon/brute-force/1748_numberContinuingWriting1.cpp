/*
    음 그냥 진짜 단순하개 i를 n까지 반복시키면서 i를 10으로 나눈 값의 자리수를 비교해서 정답값을 + 시켰다.
    맞긴했지만 시간을 많이 잡아먹었다(196ms)

    각 자리수 별로 생각하면 된다.(0ms)
    Ex. n=120 이면
    1의 자리가 포함된 수는 총 120개 이다 -> 1 ~ 120 => n - 1 + 1
    10의 자리가 포함된 수는 총 111개 이다 -> 10 ~ 120 => n - 10 + 1
    100의 자리가 포함된 수는 총 21개 이다 -> 100 ~ 120 => n - 100 + 1
    ...
    이런식으로 포함된 자리수를 모두 더해주면 된다.
*/
#include <stdio.h>

int main(void) {
    int n;
    int result=0;

    scanf("%d", &n);

    // 자리수 별로 생각하는 방법 
    int i=1;
    while(i<=n) {
        result+=n-i+1;
        i*=10;
    }
    
    // 단순히 1부터 n까지 자리수를 구해 더해주는 방법
    /*for(int i=1;i<=n;i++) {
        if(i/10==0) result++;
        else if(i/10>=1 && i/10<10) result+=2;
        else if(i/10>=10 && i/10<100) result+=3;
        else if(i/10>=100 && i/10<1000) result+=4;
        else if(i/10>=1000 && i/10<10000) result+=5;
        else if(i/10>=10000 && i/10<100000) result+=6;
        else if(i/10>=100000 && i/10<1000000) result+=7;
        else if(i/10>=1000000 && i/10<10000000) result+=8;
        else result+=9;
    }*/

    printf("%d", result);

    return 0;
}