#include <stdio.h>
#include <algorithm>
#define N 11

using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int coin[N];
int main(void) {
    int n, k; // n: 동전 갯수, k: 목표 액수 
    int count=0;
    scanf("%d %d", &n, &k);

    for(int i=0;i<n;i++) {
        scanf("%d", &coin[i]);
    }

    sort(coin, coin+n, compare);

    for(int i=0;i<n;i++) {
        if(k/coin[i]>=1) {
            count+=(k/coin[i]);
            k-=(coin[i]*(k/coin[i]));
        }
    }
    printf("%d\n",count);

    return 0;
}