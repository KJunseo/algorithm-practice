#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    int sum=0;
    int result=0;

    for(int i=0;i<4;i++) {
        int out, in;

        cin >> out >> in;

        sum-=out;
        sum+=in;

        result=max(result, sum);
    }

    cout << result << "\n";

    return 0;
}