/*
    시킨대로 구현했다.
    이진수 변환 후 1의 갯수를 세도 된다고 한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> stick;

int stickSum() {
    int sum=0;
    for(int i=0;i<stick.size();i++) {
        sum+=stick[i];
    }
    return sum;
}

int main(void) {
    int X;
    int sum=0;

    cin >> X;
    
    stick.push_back(64);

    while(true) {
        sum=0;
        sort(stick.begin(), stick.end());

        sum=stickSum();

        if(sum==X) {
            cout << stick.size() << "\n";
            break;
        }

        if(sum>X) {
            int temp = stick[0]/2;

            if(sum-temp>=X) stick[0]/=2;
            else {
                stick[0]/=2;
                stick.push_back(temp);
            }
        }

    }

    return 0;
}