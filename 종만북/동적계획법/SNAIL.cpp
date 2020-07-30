/*
    double형 array는 memset으로 안된다는 걸 알게 되었다.
    .precision은 소수 아래 몇 자리를 나타낼 것인가에 대한 것이다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int C;
int n, m;
double cache[1001][2001]; // 최대 2000까지 갈 수 있으므로

double climb(int days, int climbed) {

    // 기저 사례: 날이 다 지났을 때 n 만큼 올랐는가 
    if(days == m) return climbed >= n ? 1 : 0;

    // 메모이제이션
    double& ret = cache[days][climbed];
    if(ret != -1.0) return ret;

    return ret = (0.25 * climb(days+1, climbed+1)) + (0.75 * climb(days+1, climbed+2));
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int t=0;t<C;t++) {

        // double형 array는 memset이 안된다.
        for(int i=0;i<1001;i++) {
            for(int j=0;j<2001;j++) {
                cache[i][j] = -1.0;
            }
        }

        cin >> n >> m;

        cout.precision(10); // 10자리
        cout << climb(0, 0) << "\n";
    }

    return 0;
}