#include <stdio.h>
#include <iostream>

using namespace std;

// 첫 마이너스 이후는 다 빼주면 됨 
int main(void) {
    bool firstMinus = false;
    string question;
    string tempNum="";
    int result = 0;

    cin >> question;

    for(int i=0;i<=question.length();i++) {

        // 연산기호인 경우 
        if(question[i]=='-' || question[i]=='+' || question[i]=='\0') {

            // 처음 마이너스를 발견한 이후면 모든 수를 빼주고, 그 반대인 경우 더해준다.
            if(firstMinus) {
                result-=stoi(tempNum);
                tempNum="";
            } else {
                result+=stoi(tempNum);
                tempNum="";
            }
            
        } else {
            tempNum+=question[i]; 
        }

        // 제일 처음 마이너스를 발견했다는 것을 표시(위의 조건식보다 밑에있어야지 첫 마이너스 발견 전의 수를 더해줄 수 있다.)
        if(question[i]=='-') {
            firstMinus = true;
        }
    }

    cout << result;

    return 0;
}