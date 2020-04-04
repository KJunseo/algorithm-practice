/*
    Silver1 난이도를 처음으로 혼자 풀어낸 거 같아서 너무 좋았다.

    숫자는 고정 되어 있고, 연산자를 sort해준다음 next_permutaion으로 순열을 바꿔가면서 출력했다.
    다른 풀이를 찾아보니 DFS로 푼 풀이가 대부분이었다.

    dfs일 경우는 +, -, *, / 의 갯수를 dfs로 넘겨, 
    각각 연산자의 남은 갯수만큼 재귀함수로 dfs를 호출하고, 
    모든 연산자를 사용한 경우 그때까지의 합계와 MAX, MIN을 비교하여 업데이트 해주는 방식이었다.

    dfs는 아직 익숙하지가 않아 문제를 많이 풀어봐야할 것 같다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define VALUE 1000000000

using namespace std;

int num[100];
int op_num[4];
vector <char> op;
int main(void) {
    int n;
    int minNum=VALUE;
    int maxNum= -VALUE;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d", &num[i]);
    }

    for(int i=0;i<4;i++) {
        scanf("%d", &op_num[i]);

        for(int j=0;j<op_num[i];j++) {
            if(i==0) op.push_back('+'); 
            else if(i==1) op.push_back('-');
            else if(i==2) op.push_back('*');
            else op.push_back('/');
        }
    }

    sort(op.begin(), op.end());

    do {
        int temp=num[0];
        for(int i=0;i<n;i++) {
            if(i < op.size()) {
                if(op[i]=='+') temp+=num[i+1];
                else if(op[i]=='-') temp-=num[i+1];
                else if(op[i]=='*') temp*=num[i+1];
                else temp/=num[i+1];
            }
        }

        if(minNum > temp) minNum=temp;
        if(maxNum < temp) maxNum=temp;
    } while (next_permutation(op.begin(), op.end()));

    printf("%d\n", maxNum);
    printf("%d", minNum);

    return 0;
}