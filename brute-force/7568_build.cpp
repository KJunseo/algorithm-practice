/*
    쉬운 문제였는데 처음에 삽질을 조금 했다 ㅎ..
    그냥 처음부터 끝까지 비교하면서, 본인보다 몸무게와 키 둘 다 큰 경우를 발견하면 등수를 하나씩 뒤로 미뤄주기만 하면 된다.
*/

#include <stdio.h>
#include <iostream>
#define MAX 51

using namespace std;

pair<int, int> person[MAX];
int main(void) {
    int n;

    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d %d", &person[i].first, &person[i].second);
    }

    for(int i=1;i<=n;i++) {
        int order=1;

        for(int j=1;j<=n;j++) 
            if(person[i].first<person[j].first && person[i].second < person[j].second) order++;           
        
        printf("%d ", order);
    }

    return 0;
}