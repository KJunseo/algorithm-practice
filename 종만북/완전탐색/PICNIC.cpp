/*
    백준에서 DFS/BFS를 어느 정도 풀어봐서 그런지 예전에는 재귀에 대해 이해하기가 어려웠는데
    어느정도 쉽게 이해할 수 있었다.

    중복을 막기 위해 속성을 강제하는 것이 다른 문제에서도 중요할 것 같다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int C; // 테스트 케이스 수 
int n, m; // n: 총 학생 수, m: 친구쌍 수 
bool friends[10][10]; // 친구 관계를 나타냄 
bool paired[10]; // 짝이 되었는지 여부 확인 

// 짝 지을 수 있는 총 경우의 수를 세는 함수
int countPairings() {
    int student=-1;

    // 짝 지어지지 않은 가장 빠른 번호의 학생을 찾기
    for(int i=0;i<n;i++) {
        if(!paired[i]) {
            student=i;
            break;
        }
    }

    if(student == -1) return 1; // 모두 짝지어 진 상태면 1가지 방법을 찾은 것

    int cnt=0;

    // 기준으로 삼은 학생 바로 다음 학생부터 검사
    for(int i=student+1;i<n;i++) {

        // 짝이 없는 상태이면서 기준 학생과 친구관계에 있는 학생이라면
        if(!paired[i] && friends[student][i]) {
            paired[student] = paired[i] = true; // 짝 지어 주기 
            cnt+=countPairings();
            paired[student] = paired[i] = false; // 짝 해제(다른 경우의 수를 찾기 위함)
        }
    }
    
    return cnt;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        // 초기화 
        memset(friends, 0, sizeof(friends));
        memset(friends, 0, sizeof(paired));

        cin >> n >> m;

        // 친구 여부 표시
        for(int i=0;i<m;i++) {
            int p1, p2;

            cin >> p1 >> p2;

            friends[p1][p2]=true;
            friends[p2][p1]=true;
        }

        cout << countPairings() << "\n";
    }

    return 0;
}