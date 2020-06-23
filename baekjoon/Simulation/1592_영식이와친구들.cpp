/*
    각 자리를 key라고 생각하고, 공을 받은 횟수를 value라고 생각하여 map을 사용했다.
    순서가 그리 중요하지 않은 것 같아서 unordered_map을 사용했다.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, L;
unordered_map<int, int> um;

int main(void) {
    int cnt=0;
    int pos=1;

    cin >> N >> M >> L;

    for(int i=1;i<=N;i++) {
        um[i]=0;
    }

    while(true) {
        cnt++;
        um[pos]++;

        if(um[pos]%2==0) pos=pos-L<=0 ? pos-L+N : pos-L;
        else pos=pos+L>N ? pos+L-N : pos+L;

        if(um[pos]+1==M) break;
    }

    cout << cnt << "\n";

    return 0;
}