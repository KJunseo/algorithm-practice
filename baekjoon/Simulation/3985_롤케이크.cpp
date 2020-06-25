/*
    효율적인지는 모르겠지만 쉽게 풀었다.
    가장 많이 받을 것이라고 생각하는 사람은 그냥 K-P가 가장 큰 사람이고
    실제로 많이 받은 사람은 동일한 양일 경우 번호가 빠른 사람이 답이기 때문에 map을 사용해서 실제 받은 양이 커질때만 업데이트 해주었다.
*/
#include <iostream>
#include <map>

using namespace std;

int L;
int N;
int cake[1001];

int main(void) {
    int expect=0;
    int e_person;
    int real=0;
    int r_person;

    cin >> L;
    cin >> N;

    for(int i=1;i<=N;i++) {
        int P, K;

        cin >> P >> K;

        if(expect<(K-P)) {
            expect=K-P;
            e_person=i;
        }

        for(int j=P;j<=K;j++) {
            if(cake[j]==0) {
                cake[j]=i;
            }
        }
    }

    map<int, int> m;
    for(int i=1;i<=L;i++) {
        if(cake[i]!=0) {
            m[cake[i]]++;
        }
    }

    for(auto it=m.begin();it!=m.end();it++) {
        if(it->second>real) {
            real=it->second;
            r_person=it->first;
        }
    }

    cout << e_person << "\n";
    cout << r_person << "\n";

    return 0;
}