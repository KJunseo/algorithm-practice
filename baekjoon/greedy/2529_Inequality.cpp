/*
    처음에 prev_permutation과 next_permutation의 존재를 모르고,
    어거지로 풀어서 겨우 최솟값은 찾았는데, 최댓값을 어떻게 구해야하는지 전혀 감을 잡지 못했었다.
    prev_permutation과 next_permutation는 자동으로 현재 수의 배열에서 다음 순열을 만들어 준다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string inequality;

// 부등호를 만족하는 지 검사 
bool check(vector <int> &n) {
    for(int i=0;i<inequality.length();i++) {
        if(inequality[i]=='<' && n[i]>n[i+1]) return false;
        else if(inequality[i]=='>' && n[i]<n[i+1]) return false;
    }
    return true;
}

int main(void) {
    int num;
    char c;

    vector<int> max, min;

    scanf("%d", &num);

    for(int i=0;i<num;i++) {
        cin >> c;
        inequality+=c;
    }

    // 부등호를 만족하는 가장 큰 수의 배열 
    for(int i=9;i>9-(num+1);i--) max.push_back(i);
    while(1) {
        if(check(max)) break;
        prev_permutation(max.begin(), max.end()); // 큰 수 -> 작은 수 
    }

    // 부등호를 만족하는 가장 작은 수의 배열
    for(int i=0;i<=num;i++) min.push_back(i);
    while(1) {
        if(check(min)) break;
        next_permutation(min.begin(), min.end()); // 작은 수 -> 큰 수
    }
    
    for(int i=0;i<max.size();i++) {
        printf("%d", max[i]);
    }
    printf("\n");
    for(int i=0;i<min.size();i++) {
        printf("%d", min[i]);
    }
   

    return 0;
}