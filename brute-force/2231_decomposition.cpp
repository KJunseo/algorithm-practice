/*
    처음에 문제 이해가 잘 안되었다.
    문제는 분해합(결과)을 받아서 어떤 것의 합을 통해 분해합을 만들어내는지를 찾는 것이다.

    입력받은 분해합부터 1까지 돌면서 분해합을 찾아서 일치하면 갱신해주는 식으로 구현하였다.
    각 자리수를 구하는 과정이 조금 헷갈렸다.
    난이도는 높지 않지만, 혼자 풀어내서 기분은 좋았다.
*/
#include <stdio.h>

int main(void) {
    int n;
    int result;
    int temp;
    bool flag=false;

    scanf("%d", &n);

    for(int i=n-1;i>0;i--) {
        int num=i;
        temp=num;

        while(num>0) {   
            temp+=num%10;
            num/=10;
        }
        if(temp == n) {
            result=i;
            flag=true;
        }
    }

    if(!flag) result=0;

    printf("%d", result);

    return 0;
}