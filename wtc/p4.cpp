#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int sumPageNum(int page) {
    int sum = 0;

    while(page) {
        sum += page % 10;
        page /= 10;
    }

    return sum;
}

int mulPageNum(int page) {
    int mul = 1;

    while(page) {
        mul *= page % 10;
        page /= 10;
    }

    return mul;
}

int main(void) {
    vector<int> pobi(2), crong(2);

    for(int i = 0; i < 2; i++)
        scanf("%d", &pobi[i]);

    for(int i = 0; i < 2; i++)
        scanf("%d", &crong[i]);

    if(pobi[1] - pobi[0] != 1 || crong[1] - crong[0] != 1) {
        printf("%d\n", -1);
        return 0;
    }

    int pobi_sum = max(sumPageNum(pobi[0]), sumPageNum(pobi[1]));
    int pobi_mul = max(mulPageNum(pobi[0]), mulPageNum(pobi[1]));
    int pobi_score = max(pobi_sum, pobi_mul);

    int crong_sum = max(sumPageNum(crong[0]), sumPageNum(crong[1]));
    int crong_mul = max(mulPageNum(crong[0]), mulPageNum(crong[1]));
    int crong_score = max(crong_sum, crong_mul);

    if(pobi_score > crong_score) 
        printf("%d\n", 1);
    else if(pobi_score == crong_score)
        printf("%d\n", 0);
    else
        printf("%d\n", 2);

    return 0;
}