/*
    dfs를 써서 모든 요소를 검사하였는데 시간초과가 나왔다.

    굳이 dfs를 써야하는 문제가 아니라, 가로를 바꿔주고 검사. 세로를 바꿔주고 검사를 해주면 되는 문제였다.
    (사실 dfs도 맞게 구현된건지는 모르겠다..)
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cnt;
int result;
vector <string> candy;

void countNum() {
    for(int i=0;i<n;i++) {
        cnt=1;
        for(int j=1;j<n;j++) {
            if(candy[i][j-1]==candy[i][j]) cnt++;
            else cnt=1;
            result=max(result,cnt);
        }
    }

    for(int i=0;i<n;i++) {
        cnt=1;
        for(int j=1;j<n;j++) {
            if(candy[j-1][i]==candy[j][i])cnt++;
            else cnt=1;
            result=max(result,cnt);
        }
    }
}

int main(void) {
    string color;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        cin >> color;
        candy.push_back(color);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j+1<n) {
                swap(candy[i][j], candy[i][j+1]);
                countNum();
                swap(candy[i][j], candy[i][j+1]);
            }
            if(i+1<n) {
                swap(candy[i][j], candy[i+1][j]);
                countNum();
                swap(candy[i][j], candy[i+1][j]);
            }
        }
    }

    printf("%d\n", result);

    return 0;
}