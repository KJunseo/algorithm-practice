/*
    +1점
    일의 자리가 0, 1, 4, 5, 6, 9 가 아닌 수는 제곱근이 될 수 없어서 바로 return -1 해주었고
    long long 타입이므로 sqrt를 사용해 제곱근을 만들고 다시 제곱근 끼리 곱했을 때 원상복구가 되면 num+1 * num+1을 해주었다.
*/
#include <math.h>

long long solution(long long n) {
    
    if(n%10==2 || n%10==3 || n%10==7 || n%10==8) return -1; 
    
    long long num=sqrt(n);
    
    if(num*num==n) return (num+1)*(num+1);
    
    return -1;
}