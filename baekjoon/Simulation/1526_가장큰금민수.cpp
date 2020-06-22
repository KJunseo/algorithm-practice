/*
    효율적인지는 모르겠지만 쉽게 풀었다.
    N부터 --해가면서 각 자리의 수가 4나 7로만 이루어져있는지 검사했다.

    모듈러 연산을 사용하여 정수를 10씩 나누는 방법이나
    큐를 사용해 4, 7, 44, 47, 74, 77, ... 이런식으로 수를 만들어가며 확인하는 방법도 있었다.
*/
#include <iostream>

using namespace std;

int N;

int main(void) {
    bool flag=false;
    int ans=0;
    cin >> N;

    while(N) {
        flag=false;

        for(int i=0;i<to_string(N).length();i++) {
            if(to_string(N)[i]!='4' && to_string(N)[i]!='7') {
                flag=true;
                break;
            } 
        }

        if(flag) N--;
        else {
            ans=N;
            break;
        }
    }

    cout << N << " ";

    return 0;
}