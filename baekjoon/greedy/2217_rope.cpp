#include <stdio.h>
#include <algorithm>
#define MAX 100001

using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int rope[MAX];
int main(void) {
    int num;
    int result=0;
    scanf("%d", &num);
    int j=num-1;
    for(int i=0;i<num;i++) {
        scanf("%d", &rope[i]);
    }

    sort(rope, rope+num, compare);

    for(int i=0;i<num;i++,j--) {
        result=max(result, rope[i]*(num-j));
    }
    printf("%d", result);

    return 0;
}