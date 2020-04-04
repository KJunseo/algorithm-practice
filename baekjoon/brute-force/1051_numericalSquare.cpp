/*
    이 문제는 쉬웠다. 난이도를 보면 더 낮은 난이도가 왜 더 어렵게 느껴지는 지 모르겠다..

    그냥 처음부터 끝까지, 일정한 길이 만큼 사각형을 늘려가면서 넓이를 구하면된다.
    4 꼭지점이 하나도 일치하는 경우가 없을 때는 1을 출력하면된다.
*/
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
int result;
vector <string> rectangle;
int main(void) {
    string rec;
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        cin >> rec;
        rectangle.push_back(rec);
    }

    int plus=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            plus=1;
            while(i+plus<n && j+plus<m) {
                if(rectangle[i][j]==rectangle[i+plus][j] && rectangle[i][j]==rectangle[i][j+plus] && rectangle[i][j]==rectangle[i+plus][j+plus]) {
                    result=max(result, plus+1);
                }
                plus++;
            }
        }
    }
    if(result==0) result=1;
    printf("%d\n", result*result);

    return 0;
}