#include <stdio.h>

const int CURRENCY[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10, 1};

int answer[9];

int main(void) {
    int money;
    scanf("%d", &money);

    for(int i = 0; i < 9; i++) {
        int num = money / CURRENCY[i];
        if(num > 0) {
            money -= (CURRENCY[i] * num);
            answer[i] += num;
        }
    }

    for(int i = 0; i < 9; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}