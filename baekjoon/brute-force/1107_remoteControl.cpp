/*
    경우가 3개라고 생각했다.

    그리고, 숫자 입력 후 연산자 사용 & 연산자는 하나만 사용 해야된다고 생각했다.

    1. 100인 경우
    2. | n - 100 |
    3. 자리수만큼 반복하여, 각 자리수와 최대한 가까운 수를 넣고, | 만들어진 수 - n |

    위의 3가지를 고려하여 min 값을 찾으며 된다고 생각했다. 
    test case는 통과하였지만, 런타임 에러가 났다. 어디서 발생한지는 잘 모르겠다..

    그리고 123 / 2 / 2 3 으로 입력이 들어오면, 내 코드로는 12가 나오는데(1,1,4 + 9) 원래는(119+4)로 7이 나와야한다.

    풀이과정은 아래와 같다.
    경우의 수는 2가지이다.
    1. 100에서 + or - 하는 경우
    2. 숫자 입력 후 + or - 하는 경우

    1번 같은 경우는 그냥 | n- 100 | 값이다.
    2번은 0번 채널부터 1000000 까지 돌면서, 
    리모컨으로 해당 번호를 누를 수 있으면,
    해당 번호와 n의 절대값을 계산하여 result값을 최소로 갱신해준다.
    그 후, result값(해당채널 - n의 절대값)이랑 해당 채널의 길이를 더해주면,
    채널 입력 후, +나 -를 눌러 n번으로 이동하는 최솟값이 나온다.
*/
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define MAX 1000001

using namespace std;

int n;
int m;
int result;
bool remote[10]={true,true,true,true,true,true,true,true,true,true};

bool possible(int channel) {
    if(channel==0) {
        if(!remote[0]) return false;
        else return true;
    }

    while(channel) {
        if(!remote[channel%10]) return false;
        channel/=10;
    }
    return true;
}

int inputNum() {
    int result=MAX;
    int near=0;

    for(int i=0;i<MAX;i++) {
        if(possible(i)) {
            int click=abs(n-i);
            if(result>click) {
                result=click;
                near=i;
            }
        }
    }

    string temp=to_string(near);

    return result+temp.size();
}

int main(void) {
    
    scanf("%d", &n);

    scanf("%d", &m);

    for(int i=0;i<m;i++) {
        int wrong;
        scanf("%d", &wrong);
        remote[wrong]=false;
    }

    int result=min(abs(n-100), inputNum());

    printf("%d\n", result);

    return 0;
}