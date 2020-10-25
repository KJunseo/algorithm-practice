/*
    코드가 좀 지저분 한 느낌이 있긴하고 히든 테스트케이스를 통과 할 수 있을지는 잘 모르겠다.
*/
#include <iostream>

using namespace std;

int main(void) {
    string cryptogram;
    cin >> cryptogram;

    string answer = "";
    bool flag = true;
    while(flag) {
        answer = "";
        flag = false;

        cout << cryptogram << "\n";

        if(cryptogram == "")
            break;
        
        for(int i = 0; i < cryptogram.length() - 1; i++) {
            if(cryptogram[i] == cryptogram[i + 1]) {
                int j = i + 1;
                while(cryptogram[j] == cryptogram[i])
                    j++;
                i = j - 1;
                flag = true;
            } else {
                answer += cryptogram[i];
            }
        }

        if(cryptogram[cryptogram.length() - 1] != cryptogram[cryptogram.length() - 2])
            answer += cryptogram[cryptogram.length() - 1];

        cryptogram = answer;
    }

    return 0;
}