/*
    가장 큰 수가 9876543210 이므로, 반복문을 돌려 
    0인 경우 -> 0
    1~9인 경우 -> 자기 자신
    10~ -> 9876543210을 넘지 않을 때까지 세면서 출력하려했으나
    시간초과가 나버렸다.

    dp를 사용해서 풀 수도 있다고하는데,
    큐를 사용한 풀이가 신박했다.

    1~9까지 큐에 넣고, 차례대로 뺀다
    1을 빼면 1보다 작은 0을 붙여 10을 다시 큐에 넣는다.
    2를 빼면 2보다 작은 0, 1을 붙여 20, 21을 다시 큐에 넣는다.
    ...


*/
#include <stdio.h>
#include <queue>
#define MAX 1000001

using namespace std;

long decreasingNum[MAX]; // n번째 감소수를 차례로 담는 배열 
queue <long> q;
int main(void) {
    int n;
    int idx=9;

    scanf("%d", &n);

    if(n==0) {
        printf("0\n");
        return 0;
    }

    // 1~9 까지는 자기 자신이 감소수(1은 1번째 감소수, 2는 2번째 감소수 ...)
    for(int i=1;i<=9;i++) {
        q.push(i);
        decreasingNum[i]=i;
    }

    // n 번째 감소수까지 q를 돌려 만듬
    while(idx<n) {
        if(!q.empty()) {
            long long temp=q.front();
            q.pop();

            int lastNum=temp%10;
            for(int i=0;i<lastNum;i++) {
                q.push(temp*10+i);
                decreasingNum[++idx]=temp*10+i;
            }
        } else break;
    }

    if(!decreasingNum[n]) printf("-1\n"); // n 번째 감소수가 없는 경우
    else printf("%ld\n", decreasingNum[n]);

    return 0;
}