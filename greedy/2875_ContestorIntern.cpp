#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int girl,boy,intern;
    int count=0;

    scanf("%d %d %d", &girl, &boy, &intern);

    while(girl>=2&&boy>=1) {
        girl-=2;
        boy-=1;
        count++;
    }

    while(girl+boy<intern) {
        girl+=2;
        boy+=1;
        count--;
    }

    printf("%d\n", count);

    return 0;
}