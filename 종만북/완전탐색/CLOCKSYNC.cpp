#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

// 스위치와 시계의 연결 상태를 나타냄(1: 연결, 0: 연결x)
const int linked[10][16] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

int C;
vector<int> clocks; // 현재 시계의 상태

// 시계가 모두 12시로 정렬되었는지 확인하는 함수 
bool areAligned() {
    
    for(int i=0;i<clocks.size();i++) {
        if(clocks[i]!=12) return false;
    }

    return true;
}


int solve(int switchNum) {

    // 기저 사례: 마지막 스위치까지 누른 후에는 정렬상태를 확인하여 정렬되었으면 0을 아니면 INF를 리턴 
    if(switchNum == 10) return areAligned() ? 0 : INF;

    int ret = INF;

    // 스위치 누르기 0~3번까지 모두 시도  
    for(int cnt=0;cnt<4;cnt++) {
        ret = min(ret, cnt + solve(switchNum+1));

        // 실제로 스위치를 cnt만큼 눌렀다고 생각하고 연결된 시계의 시간을 바꿔줌
        for(int i=0;i<16;i++) {
            if(linked[switchNum][i]==1) {
                clocks[i]+=3;
                if(clocks[i]==15) clocks[i]=3;
            }
        }
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        clocks.clear();

        for(int i=0;i<16;i++) {
            int clock;

            cin >> clock;

            clocks.push_back(clock);
        }

        int result = solve(0);

        if(result==INF) cout << -1 << "\n";
        else cout << result << "\n";
    }

    return 0;
}