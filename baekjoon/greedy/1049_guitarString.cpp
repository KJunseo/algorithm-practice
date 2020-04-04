/*
    처음에는 6개 이상일 경우, 가장 싼 패키지를 먼저사고
    6개 이하가 남으면 전부 낱개로 사는 방식으로만 계산하였다.
    그러나 이거 말고도, 전부 낱개로 사는 방법. 전부 패키지로 사는 방법. 
    의 경우의 수가 더 있었다. 아직 알고리즘 적 사고가 부족한 것 같다.
*/
#include <stdio.h>
#include <algorithm>
#define INF 100000000

using namespace std;

int main(void) {
    int num, brandNum;
    int apiece, pkg;
    int result=0;
    int minPkg=INF, minApiece=INF;

    scanf("%d %d", &num, &brandNum);

    for(int i=0;i<brandNum;i++) {
        scanf("%d %d", &pkg, &apiece);
        minPkg = min(minPkg, pkg);
        minApiece = min(minApiece, apiece);
    }

    // 1. 낱개만 사는 경우
    result=minApiece*num;

    // 2. 패키지만 사는 경우
    // 6개 이하일 때는 1개
    // 12개 이하일 때는 2개
    // 18개 이하일 때는 3개 
    // .... 
    result=min(result,minPkg*((num/6)+1));

    // 3. 섞어서 사는 경우
    result=min(result,(minPkg*(num/6))+(minApiece*(num%6)));

    printf("%d\n", result);

    return 0;
}