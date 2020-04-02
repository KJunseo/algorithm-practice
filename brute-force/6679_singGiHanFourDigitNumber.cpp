#include <stdio.h>

int duodecimalSum(int num) {
    int sum=0;
    while(num>0) {
        sum+=num%12;
        num/=12;
    }
    return sum;
}

int hexadecimalSum(int num) {
    int sum=0;
    while(num>0) {
        sum+=num%16;
        num/=16;
    }
    return sum;
}

int decimalSum(int num) {
    int sum=0;
    while(num>0) {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main(void) {

    for(int i=1000;i<=9999;i++) {
        if(decimalSum(i)==duodecimalSum(i) && decimalSum(i)==hexadecimalSum(i)) 
            printf("%d\n", i);
    }

    return 0;
}