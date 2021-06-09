#include <iostream>

using namespace std;

int T;

int A = 60 * 5; // 300
int B = 60;
int C = 10;

int cnt[3];

int main() {
    cin >> T;

    if (T % 10)
    {
        cout << -1;
        return 0;
    }

    cnt[0] = T / A;
    T = T % A;

    cnt[1] = T / B;
    T = T % B;

    cnt[2] = T / C;

    cout << cnt[0] << " " << cnt[1] << " " << cnt[2];

    return 0;
}