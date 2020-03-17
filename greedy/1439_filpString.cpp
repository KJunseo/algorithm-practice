/*
    난이도가 낮은 문제이긴 했지만, 정말 오랜만에 아무 도움 없이 혼자 해결한 문제여서 기분이 좋았다.

    1 -> 0 인 경우와
    0 -> 1 인 경우를 
    비교하여 최솟값을 출력해주었다.
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string s;
    int cnt1=0;
    int cnt2=0;
    
    cin >> s;

    // 1 -> 0 으로 바꾸는 경우
    for(int i=0;i<s.length();i++) {
        if(s[i]=='0') continue;
        while(s[i]=='1') {
            i++;
        }
        cnt1++;
    }

    // 0 -> 1로 바꾸는 경우
    for(int i=0;i<s.length();i++) {
        if(s[i]=='1') continue;
        while(s[i]=='0') {
            i++;
        }
        cnt2++;
    }

    printf("%d\n", min(cnt1, cnt2));

    return 0;
}