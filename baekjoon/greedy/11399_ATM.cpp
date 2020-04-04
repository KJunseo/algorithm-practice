#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 1001

using namespace std;

int p[N];
int ac_p[N];
int main(void) {
    int n;
    int total_time=0;
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d", &p[i]);
    }

    sort(p, p+n+1);

    for(int i=1;i<=n;i++) {
        ac_p[i] = ac_p[i-1] + p[i];
        total_time += ac_p[i];
    }

    printf("%d\n", total_time);
    
    return 0;
}