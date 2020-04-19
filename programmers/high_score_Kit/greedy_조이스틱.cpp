/*
    오른쪽으로 쭉 진행했을 때와, 반대로 쭉 진행했을 때 둘 중 최소값이 정답이라고 생각했는데
    11번 테스트케이스를 실패하였다. 
    "BBAABB"와 같이 오른쪽으로 쭉 가다가 반대로 돌아가는 경우가 최소인 경우가 존재하기 때문이다..

    두 가지 경우의 수가 있다.
    1. 오른쪽으로만 진행
    2. 방향을 바꾸는 경우

    현재 인덱스의 다음 인덱스를 가지고 다음 인덱스가 전체 문자열 길이보다 작고, A이면 계속 오른쪽으로 증가시킨다.
    왼쪽으로 갔을 때, A가 아닌 것을 만날 때 까지 이동한 횟수에 현재 인덱스와, 뒤에서 부터 시작하여 A가 아닌 인덱스 중 작은 값을 더한다.

    turn 부분은 완벽하게 이해하지 못하였다..
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int turn = size-1; // 이동 횟수를 나타냄(최대 이동 횟수(오른쪽으로 쭉 이동하는 경우)로 초기화)

    for(int i=0;i<size;i++) {
        if(name[i]>'N') answer+=1+'Z'-name[i];
        else answer+=name[i]-'A';

        int next = i+1; // 다음 문자 인덱스 
        while(next<size && name[next]=='A') next++; // 문자열의 크기보다 작고, A이면 오른쪽으로 이동 

        // i+size-next: 현재 위치에서 반대방향으로 진행 시, 자기자신의 다음값과, A가 아닌 것을 만날 때 까지 최대 이동한 횟수
        // size-next: 가장 끝 문자를 시작점으로, 현재 위치 바로 다음 A가 아닌 인덱스 값
        // min(i, size-next): 현재 인덱스와 size-next 중 최소값 
        turn = min(turn, i+size-next+min(i, size-next));
    }

    answer+=turn;

    return answer;
}

// 테스트케이스 11 같은 경우 해결하지 못한 코드 
// int solution(string name) {
//     string init, temp;
//     int cnt1=0, cnt2=0;
    
//     for(int i=0;i<name.length();i++) {
//         init+='A';
//         temp+='A';
//     }
    
//     // 오른쪽으로 쭉 진행
//     for(int i=0;i<name.size();i++) {
//         if(init==name) break;
//         if(i!=0) cnt1++;
//         if(name[i]>'N') cnt1+=1+'Z'-name[i];
//         else cnt1+=name[i]-'A';
//         init[i]=name[i];
//     }
    
//     init=temp;
    
//     // 반대로 쭉 진행
//     if(name[0]>'N') cnt2+=1+'Z'-name[0];
//     else cnt2+=name[0]-'A';
//     init[0]=name[0];
    
//     for(int i=name.size()-1;i>0;i--) {
//         if(init==name) break;
//         cnt2++;
//         if(name[i]>'N') cnt2+=1+'Z'-name[i];
//         else cnt2+=name[i]-'A';
//         init[i]=name[i];
//     }

//     return min(cnt1, cnt2);
// }