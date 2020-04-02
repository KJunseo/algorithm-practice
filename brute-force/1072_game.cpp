/*
    100 : 53 = x:47 -> 100 : 게임횟수(x) = 승률(z) : 이긴 게임(y) -> z = 100*y/x 
    그냥 1씩 더해가면서 계산하면 될 거 같은데 MAX 값이 너무 커서 시간초과가 난다.
    승률이 99이상이면 100은 될 수 없으므로 예외처리도 해주었다.

    이분탐색으로 풀어야한다고 한다.
    이분탐색을 구현해서 푼 적이 처음이었다.

    low=0 | high=MAX 값으로 설정한다.
    mid를 구하고, 해당 mid에서의 승률을 계산한다.
    계산한 승률이, 원래 승률보다 크다면, high를 mid-1로 바꾼다.
    계산한 승률이, 원래 승률보다 작거나 같다면, low를 mid+1로 바꾼다.
*/
#include <stdio.h>
#define MAX 1000000000

using namespace std;
 
long long x, y;
int main(void) {
    scanf("%lld %lld", &x, &y);

    long long z = 100*y/x;

    if(z>=99) {
        printf("-1\n");
        return 0;  
    }

    long long low=0;
    long long high=MAX;

    while(low<=high) {
        long long mid=(low+high)/2;

        long long tempZ=100*(y+mid)/(x+mid);

        if(tempZ > z) high=mid-1;
        else low=mid+1;
    }

    printf("%lld\n", low);

    return 0;
}