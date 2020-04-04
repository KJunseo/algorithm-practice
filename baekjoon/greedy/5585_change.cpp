#include <stdio.h>
#define MONEY 1000

int main(void) {
    int price;
    int change;
    int count=0;
    scanf("%d", &price);

    change=MONEY-price;

    count+=(change/500);
    change%=500;

    count+=(change/100);
    change%=100;
 
    count+=(change/50);
    change%=50;

    count+=(change/10);
    change%=10;

    count+=(change/5);
    change%=5;

    count+=(change/1);
    change%=1;

    printf("%d",count);

    return 0;
}