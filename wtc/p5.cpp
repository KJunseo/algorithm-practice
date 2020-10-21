#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        string num = to_string(i);

        for(int j = 0; j < num.length(); j++) {
            if(num[j] == '3' || num[j] == '6' || num[j] == '9')
                cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}