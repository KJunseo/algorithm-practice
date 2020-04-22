/*
    피보나치였다.
    +2점 밖에 얻지 못했지만, 혼자서 dp를 사용해서 풀었다.
    
    내가 발견한 공식은 
    N개의 사각형을 사용했을 때, 짧은 변은 N-2의 짧은 변 + N-1의 짧은 변 이었고,
                          긴 변은 N-1의 짧은 변 + N-1의 긴 변이었다.

    사각형을 한 개 사용할 땐, 짧은 변 1 / 긴 변 1을 리턴해주고,
    사각형을 두 개 사용할 땐, 짧은 변 1 / 긴 변 2를 리턴해주었다.

    그게 아니하면 위의 공식을 적용해서 풀었다.

    굳이 짧은 변, 긴 변으로 나누지 않아도 풀 수 있는 문제였다.
    ((N-2) + 2*(N-1) + N ) * 2를 하면 답이 나온다.
*/
#include <string>
#include <vector>

using namespace std;

pair<long, long> side[80];
pair<long, long> dp(int x) {
    
    if(x==1) {
        return make_pair(1, 1);
    }
    if(x==2) {
        return make_pair(1, 2);
    }
    
    if(side[x].first!=0 && side[x].second!=0) return side[x];
    else {
        side[x].first=dp(x-2).first + dp(x-1).first;
        side[x].second=dp(x-1).first + dp(x-1).second;
        return side[x];
    }
}

long long solution(int N) {
    long long answer = 0;
    pair<long, long> temp;
    
    temp=dp(N);
    
    answer=(temp.first+temp.second)*2;
    
    return answer;
}