/*
    4개의 배열을 모두 돌리는 것은 당연히 안된다고 생각해서 각각 두개의 배열로 나누었다.
    AB끼리 더하고, CD끼리 더한 후, 두 개의 값을 더해서 0이 나오는 걸 찾았지만, 시간초과가 나와버렸다.
    접근을 똑바로 했는데, 구현을 틀린 것 같다.

    Binary Search를 이용하는 문제였다.
    lower_bound: 찾고자 하는 값 이상이 처음 나타나는 위치 
    upper_bound: 찾고자 하는 값 보다 큰 값이 처음 나타나는 위치

    lower_bound & upper_bound를 처음 써봤다.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 4000

using namespace std;

int A[MAX], B[MAX], C[MAX], D[MAX];
vector <int> AB, CD;
int main(void) {
    int n;
    long long cnt=0;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            AB.push_back(A[i]+B[j]);
            CD.push_back(-(C[i]+D[j]));
        }
    }

    sort(CD.begin(), CD.end());

    int low=0;
    int high=0;
    for(int i=0;i<AB.size();i++) {
        low=lower_bound(CD.begin(), CD.end(), AB[i])-CD.begin();
        high=upper_bound(CD.begin(), CD.end(), AB[i])-CD.begin();
        cnt+=high-low;
    }

    printf("%lld\n", cnt);

    return 0;
}