/*
    더 간단하게 풀 수 있을 것 같긴하지만 그냥 풀었다.
    각 차의 입차시간 출차시간을 벡터에 저장시켜놓고
    매 분마다 차가 몇 대인지 세어주었다.
*/
#include <iostream>
#include <vector>

using namespace std;

int A, B, C;
vector<pair<int, int> > parkinglot;

int main(void) {
    int total=0;
    int repeat=0;

    cin >> A >> B >> C;

    for(int i=0;i<3;i++) {
        int getin, getout;

        cin >> getin >> getout;

        if(getout>repeat) repeat=getout;

        parkinglot.push_back(make_pair(getin, getout));
    }

    int minute=0;
    int cnt=0;
    for(int k=0;k<repeat;k++) {
        minute++;
        cnt=0;

        for(int i=0;i<parkinglot.size();i++) {
            if(parkinglot[i].first<=minute && parkinglot[i].second>minute) cnt++;
        }

        if(cnt==3) total+=C*cnt;
        else if(cnt==2) total+=B*cnt;
        else if(cnt==1) total+=A*cnt;
    }

    cout << total <<"\n";

    return 0;
}