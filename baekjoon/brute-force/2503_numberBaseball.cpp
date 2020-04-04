/*
    초등부 문제였는데 어려웠다ㅎㅎ...
    여러가지 방법을 생각했었는데 실패했다.

    세자리 수이기 때문에 먼저 1000크기의 배열을 만들어준다.(true로 초기화)
    0을 포함하거나 중복되는 수가 있는 경우는 false로 바꿔준다.(123~999)
    123~999 까지 완전 탐색 하면서, 주어진 값과 strike, ball 개수를 비교하여 일치하지 않으면 false로 바꿔준다.
    true인 개수를 출력해주면 된다.

    늘 드는 의문이지만, 초등학생은 이걸 어떻게 생각해내는지 모르겠다..
*/
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int n;
bool check[1000]; // 123~999까지 경우의 수
int main(void) {
    string num;
    int strike;
    int ball;

    memset(check, true, sizeof(check));

    // 0을 포함하거나, 중복되는 수가 있는 경우 제외
    for(int i=123;i<=999;i++) {
        string temp=to_string(i);

        if(temp[0]==temp[1] || temp[1]==temp[2] || temp[0]==temp[2]) check[i]=false;
        if(temp[0]=='0' || temp[1]=='0' || temp[2]=='0') check[i]=false;
    }

    scanf("%d", &n);

    for(int l=0;l<n;l++) {
        cin >> num >> strike >> ball;

        // 123 ~ 999를 돌면서 현재 값과, 주어진 값의 strike, ball 비교
        for(int i=123;i<=999;i++) {
            int tempStrike=0;
            int tempBall=0;
            
            if(check[i]) {
                string temp=to_string(i);

                // 3자리수이기 때문
                for(int j=0;j<3;j++) {
                    for(int k=0;k<3;k++) {
                        if(j==k && num[j]==temp[k]) tempStrike++;
                        if(j!=k && num[j]==temp[k]) tempBall++;
                    }
                }
                if(strike!=tempStrike || ball!=tempBall) check[i]=false;
            }
        }
    }

    int cnt=0;
    for(int i=123;i<=999;i++) {
        if(check[i]) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}