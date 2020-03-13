/*
    처음 입력 받은 2개는 콘센트에 넣고, 그 뒤의 전자기기들을 콘센트 구멍 갯수만큼 비교하면서 구현하려하였는데 실패했다.

    생각해야 할 것은 3가지이다.
    1. 콘센트에 빈 공간이 있는가?
    2. 빈 공간이 없는 경우 이미 사용중인가?
    3. 빈 공간이 없고 사용중도 아니면 가장 마지막에 쓰일 전자기기나, 사용 계획이 없는 전자기기를 뺀다.

    3번의 경우가 이해하기가 힘들고 어떻게 저렇게 구현할 생각을 했는지 잘 모르겠다...
*/
#include <stdio.h>
#include <vector>
#define MAX 101

using namespace std;

int uses[MAX];
int socket[MAX];
int main(void) {
    int n, k;
    int cnt=0;
    bool flag = false;

    scanf("%d %d", &n, &k);

    for(int i=0;i<k;i++) {
        scanf("%d", &uses[i]);
    }

    for(int i=0;i<k;i++) {

        flag = false;
        int idx, deviceIdx = -1;
        // 1. 비어 있는 공간이 있는가?
        for(int j=0;j<n;j++) {
            if(!socket[j]) {
                socket[j]=uses[i];
                flag=true;
                break;
            } else {
                // 2. 빈 공간이 없고 미리 꽂혀 있는가?
                if(uses[i]==socket[j]) {
                    flag=true;
                    break;
                }

                // 3. 빈 공간이 없고 꽂혀 있지 않는 경우
                // 3-1. 쓰일 계획이 없는 것 빼기
                // 3-2. 가장 마지막에 쓰일 것 빼기
                int lastIdx=0;

                for(int l=i+1;l<k;l++) {
                    if(uses[l]==socket[j]) break;
                    lastIdx++;
                }
                if(lastIdx>deviceIdx) {
                    idx=j;
                    deviceIdx=lastIdx;
                }
            }
        }
        if(flag) continue; // 빈 공간이 있거나, 이미 사용 중이면 continue

        // 가장 마지막에 쓰일 전자기기가 꼽혀있는 콘센트를 뺀다.
        socket[idx]=uses[i];        
        cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}