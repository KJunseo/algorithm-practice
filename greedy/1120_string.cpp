#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 10000000

using namespace std;

int main(void) {
    string first, second;
    int d;
    int result = INF;

    cin >> first >> second;

    d = second.length() - first.length();  

    /*
        추가한 문자는 어차피 second의 문자와 같을 것이기 때문에 실제로 추가해 줄 필요는 없다.

        ex) 
        j가 0인 경우 -> first 뒤에 문자를 추가한 경우
        j가 1인 경우 -> first 앞에 문자 하나, 나머지는 first 뒤에 추가한 경우 
        ...
    */
    for(int i=0;i<=d;i++) {
        int count=0;

        for(int j=0;j<first.length();j++) {
            if(first[j]!=second[j+i]) {
                count++;
            }
        }
        result = min(result, count);
    }

    printf("%d\n", result);
    return 0;
}