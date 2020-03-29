/*
    dfs를 사용해 경우의 수를 모두 따져보았고, 만족하는 경우일 때, 3 수가 모두 삼각 수 인 경우가 있으면 1을 출력하게하였다.
    구현하면서도 뭔가 잘못한 거 같았다.
    결국 시간초과가 나버렸다..

    삼각수를 먼저 계산해놓은 다음
    3가지를 뽑아 만족하는 것을 찾는 방법이었다.

    어려운 문제는 아니었는데, 처음 접근 방향을 너무 이상하게 잡았던거같다...
*/
#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector <int> triangleNum;

void initTriangleNum() {
    int i=1;
    while(i*(i+1)/2<1000) {
        triangleNum.push_back((i*(i+1))/2);
        i++;
    }
}

bool eureka(int num) {
    for(int i=0;i<triangleNum.size();i++) {
        for(int j=0;j<triangleNum.size();j++) {
            for(int k=0;k<triangleNum.size();k++) {
                if(triangleNum[i]+triangleNum[j]+triangleNum[k]==num) return true;    
            }
        }
    }
    return false;
}

int main(void) {
    int tc;
    scanf("%d", &tc);

    initTriangleNum();

    for(int k=0;k<tc;k++) {
        scanf("%d", &n);

        if(eureka(n)) printf("1\n");
        else printf("0\n");
    }

    return 0;
}