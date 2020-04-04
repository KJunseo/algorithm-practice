/*
    처음에 그림을 그려보며 규칙성을 찾으려 했지만, 규칙성을 찾지 못해 수학공식을 찾아보고 구현하려했다.
    4*(n-1)*(n-2)+pow((n-2),2) - 1면
    4*((n-1)+(n-2)) - 2면 
    4 - 3면

    n이 1인 경우는 가장 큰 수를 아래로 두면되고,
    n이 2부터는, 3가지 경우의 수가 있다.
    1. 한 면만 보일 경우: 가장 작은 수가 보여지면 된다.
    2. 두 면이 보일 경우: 마주 보는 조합을 제외한 수 중 가장 작은 것
    3. 세 면이 모두 보일 경우: 마주 보는 면을 포함한 조합을 제외하고, 3개의 수의 조합 중 가장 작은 것

    ** 구현은 올바르게 했으나, long long을 안써서 계속 시간을 보냈다.. 언제 int 언제 long long을 쓸지 감이 잘 안온다.
    ** 내가 푼 방법보다 더 간단하게 한 방법이 있어 주석처리 해놓았다.
    ** 각각 마주보는 두 면 중 작은 값을 골라서 나온 3개의 값을 오름차순으로 정렬하여,
    ** 한 면일 때 첫 번째 요소, 두 면일 때 첫 번째 + 두번째, 세 면일 때 첫 번째 + 두 번째 + 세 번째를 해주는 알고리즘이었다.
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void) {
    long long n;
    int dice[6];
    long long sum=0;

    scanf("%lld", &n);
    for(int i=0;i<6;i++) {
        scanf("%d", &dice[i]);
    }
   
    if(n==1) {
        sort(dice, dice+6);
        for(int i=0;i<5;i++) {
            sum+=dice[i];
        }
    } else {
        long long oneSideNum=4*(n-1)*(n-2)+pow((n-2),2); // 1면
        long long twoSideNum=4*((n-1)+(n-2)); // 2면 
        long long threeSideNum=4; // 3면

        // 간단한 방법
        /*dice[0]=min(dice[0],dice[5]);
        dice[1]=min(dice[1],dice[4]);
        dice[2]=min(dice[2],dice[3]);

        sort(dice, dice+3);
        int oneMin=dice[0];
        int twoMin=dice[0]+dice[1];
        int threeMin=dice[0]+dice[1]+dice[2];*/

        // 3면 최소
        int threeMin=dice[0]+dice[1]+dice[2];
        for(int i=0;i<6;i++) {
            for(int j=i+1;j<6;j++) {
                for(int k=j+1;k<6;k++) {
                    if(i==j || j==k || i==k || i+j==5 || i+k==5 || j+k==5) continue;
                    threeMin=min(threeMin, dice[i]+dice[j]+dice[k]);
                }
            }
        }

        // 2면 최소
        int twoMin=dice[0]+dice[1];
        for(int i=0;i<6;i++) {
            for(int j=i+1;j<6;j++) {
                if(i+j==5 || i==j) continue;
                twoMin=min(twoMin,dice[i]+dice[j]);
            }
        }

        // 1면 최소
        sort(dice, dice+6);
        int oneMin=dice[0];

        sum+=oneSideNum*oneMin;
        sum+=twoSideNum*twoMin;
        sum+=threeSideNum*threeMin;
    }
    
    printf("%lld\n", sum);

    return 0;
}