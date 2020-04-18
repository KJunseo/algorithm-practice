/*
    이분탐색을 어디에 적용해야하는지 감을 잡지 못했었다..
    어려웠다 ㅎㅎ..

    바위 간의 거리를 기준으로 삼는 문제이다.
    즉, 바위 간의 최소 거리를 정해주고, 최소거리 보다 작은 바위들을 모두 제거하는 방식이다.
    만약 제거된 바위가 n보다 작다면, 최소 거리를 증가시켜 더 많은 바위를 제거하도록 바꿔야한다.
    만약 제거된 바위가 n보다 많다면, 최소 거리를 감소시켜 더 적은 바위를 제거하도록 바꿔야한다.

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int numOfRocks=rocks.size(); // 바위 갯수 
    int start=1; // 시작 지점 
    int end=distance; // 끝 지점 
    
    if(n==numOfRocks) return distance; // 모든 바위를 제거하는 경우 거리 값 리턴
    
    sort(rocks.begin(), rocks.end()); 
    
    while(start<=end) {
        int mid=(start+end)/2; // 바위 간의 최소 거리 

        int cnt=0; // 삭제한 바위 갯수 
        int last=0; // 현재 위치
        for(int i=0;i<numOfRocks;i++) {
            int d = rocks[i]-last; // 현재위치와 바위 사이의 거리 
            
            // 바위 간의 최소 거리보다 작다면 
            if(d<mid) {
                cnt++; // 바위 삭제
            } else {
                last=rocks[i]; // 바위를 삭제하지 못했을 시, 현재 위치 업데이트
            }
        }

        // 삭제한 바위가 삭제해야하는 바위(n)보다 더 큰 경우
        if(cnt>n) {
            end=mid-1; // 삭제할 바위를 줄이기 위해 바위간의 최소거리를 줄여줌 
        } else {
            start=mid+1; // 삭제할 바위를 늘리기 위해 바위간의 최소거리를 늘려줌 
            answer=mid; // 삭제한 바위가 삭제해야하는 바위(n)보다 더 작거나 같은 경우만 업데이트
        }
    }
    
    return answer;
}