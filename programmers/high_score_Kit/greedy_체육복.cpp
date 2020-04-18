/*
    쉽게 느껴진 문제였지만, 테스트 케이스 7번을 만족시키지 못해 시간이 좀 걸렸다..
    아직도 어디가 잘못된지는 잘 모르겠다.

    처음 접근방식은 모든 학생을 true로 설정해 준 후, lost에 포함된 학생을 false로 바꿔준 후,
    reserve 학생을 돌면서, reserve 학생이 lost에도 포함되어 있는 경우, reserve 학생 본인만 true로 바꿔주고,
    lost에 포함되어 있지 않는다면, 앞사람한테 빌릴 수 있으면 빌리고, 못 빌리면 뒷 사람한테 빌리도록 하였다.
    그러나 테스트케이스 7번을 통과하지 못했고 다르게 접근하였다.

    모든 학생을 1로 초기화 하고,
    lost에 포함된 학생은 --, reserve에 포함된 학생은 ++ 해주었다.
    그 후 모든 학생을 탐색하면서 값이 0(체육복이 없는상태)인 경우 앞사람이 여벌이 있으면 빌리고, 없으면 뒷사람한테 빌리도록 하였다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n+2, 1);
    
    for(int i=0;i<lost.size();i++) check[lost[i]]--;
    
    for(int i=0;i<reserve.size();i++) check[reserve[i]]++;
    
    for(int i=1;i<=n;i++) {
        if(check[i]==0) {
            if(check[i-1]==2) {
                check[i-1]--;
                check[i]++;
            } else if(check[i+1]==2) {
                check[i+1]--;
                check[i]++;
            }
        }
        if(check[i]>=1) answer++;
    }
    
    return answer;
}

// 테스트 케이스 7번에서만 틀린풀이.. 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> check(n+2, true);
    
    for(int i=0;i<lost.size();i++) {
        check[lost[i]]=false;
    }
    
    vector<int>::iterator iter;
    
    for(int i=0;i<reserve.size();i++) {
        iter = find(lost.begin(), lost.end(), reserve[i]);
        if(iter == lost.end()) {
            if(check[reserve[i]-1]==false) check[reserve[i]-1]=true;
            else if(check[reserve[i]+1]==false) check[reserve[i]+1]=true;
        } else check[reserve[i]]=true;
    }
    
    for(int i=1;i<=n;i++) {
        if(check[i]==true) answer++;
    }
    
    return answer;
}