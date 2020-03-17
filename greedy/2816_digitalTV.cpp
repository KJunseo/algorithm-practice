/*
    단순하게 KBS1을 먼저 찾아 제일 위로 올리고, KBS2를 찾아 두번째로 올리게 구현하였다.
    여러 테스트 케이스를 통과시켰지만, 틀리게 나왔다.
    실제로 문자열 swap도 해서 구현했었는데, 버튼만 출력하면 되기 때문에 굳이 문자열을 직접 바꿔줄 필요는 없는 문제였다.

    가장 간단하게 1번과 4번만 사용해서 구현하였다.
    kbs1의 위치까지 1번으로 내려가고, 4번으로 맨 끝까지 올린다.
    kbs2의 위치까지 1번으로 내려가고, 4번으로 맨 끝 바로 전까지 올린다.  
    *KBS1이 KBS2보다 밑에 있는 경우, KBS1을 위로 올리고 나면, KBS2가 원래 위치보다 하나 내려가게되므로 그 경우 kbs2의 idx++를 해줘야함 
*/
#include <stdio.h>
#include <iostream>
#define MAX 100

using namespace std;

string channel[MAX];
int main(void) {
    int n;
    int idx1=0, idx2=0;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        cin >> channel[i];

        if(channel[i]=="KBS1") idx1=i;
        if(channel[i]=="KBS2") idx2=i;
    }

    for(int i=0;i<idx1;i++) printf("%d", 1);
    for(int i=0;i<idx1;i++) printf("%d", 4);

    idx1 > idx2 ? idx2++ : idx2; // KBS1이 KBS2보다 밑에 있는 경우, KBS1을 위로 올리고 나면, KBS2가 원래 위치보다 하나 내려가게되므로 
    if(idx2!=1) {
        for(int i=0;i<idx2;i++) printf("%d", 1);
        for(int i=0;i<idx2-1;i++) printf("%d", 4);
    }

    return 0;
}