/*
    +1점
*/
#include <iostream>

using namespace std;

int n, m;

int main(void) {

    cin >> n >> m;
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout << "*";
        }
        cout << "\n";
    }
    

    
    return 0;
}