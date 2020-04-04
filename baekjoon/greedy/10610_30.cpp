#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
    return a>b;
}

int main(void) {
    string num;
    long long int sum=0;
    bool check_zero=false;

    cin >> num;
    int length = num.length();

    for(int i=0;i<length;i++) {
        if(num[i]=='0') check_zero=true;
        sum+=num[i]-'0';
    }

    if(!check_zero || sum%3!=0) printf("%d", -1);
    else {
        sort(num.begin(), num.end(), compare);
        cout << num;
    }

    return 0;
}