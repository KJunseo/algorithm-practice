/*
    종료하는 경우의 수를 생각하는 것이 어려웠다.

    1. s[pos]와 w[pos]가 대응되지 않는 경우
    2. w가 끝에 도달한 경우: *가 없으므로 패턴과 문자열의 길이가 정확히 일치해야 함
    3. s가 끝에 도달한 경우: 패턴은 남았지만, 문자열이 끝난 경우. 남은 패턴이 *로만 이루어져있다면 true 아니라면 false
    4. w[pos]가 *인 경우: *가 몇 글자나 커버할지 모르기땜누에 0글자부터 남은 문자열의 길이만큼 모든 가능성을 검사

    다시 풀어봐야할 문제.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int C;
string W, S;
int N;
int cache[101][101];
vector<string> result;
 
// 와일드카드 패턴과 문자열을 비교 
bool matchMemoized(int w, int s) {

    // 메모이제이션
    int& ret = cache[w][s]; // 참조형 변수
    if(ret!=-1) return ret; // 이미 값이 존재하는 경우 그 값을 사용

    // 인덱스를 기준으로 와일드카드(W)와 문자열(S)를 맞춰나감
    if(s<S.size() && w<W.size() && (W[w]=='?' || W[w]==S[s]))
        return ret=matchMemoized(w+1, s+1); // if문이 실행된다면, 확인한 다음 인덱스부터 비교

    // 패턴의 끝에 도달한 경우 문자열도 끝났으면 true
    if(w==W.size()) return ret=(s==S.size());

    // *를 만난 경우: *에 몇 글자를 대응해야 할지 재귀 호출로 확인
    if(W[w]=='*') 
        if(matchMemoized(w+1, s) || // 아무 글자도 대응시키지 않은 경우
            (s<S.size() && matchMemoized(w, s+1))) // 한 글자를 대응 시킨 경우
            return ret=1;
    
    return ret=0;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int t=0;t<C;t++) {

        result.clear();
        
        cin >> W >> N;
        
        for(int i=0;i<N;i++) {
            cin >> S;

            memset(cache, -1, sizeof(cache)); // 매번 문자열을 검사할 때 마다 초기화 해줘야 함 

            if(matchMemoized(0, 0)) result.push_back(S);
        }

        sort(result.begin(), result.end()); // 사전 순 

        for(int i=0;i<result.size();i++) {
            cout << result[i] << "\n";
        }
    }

    return 0;
}