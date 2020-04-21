/*
    백준에서 풀었었던 문제였다.
    누적합을 사용한다.
    먼저 저울추를 오름차순으로 정렬하고,
    다음 저울추가 누적합+1보다 큰 경우, 누적합+1의 값은 만들 수 없는 것이다.
    
    예를 들어, 다음 저울 추가 7이고, 누적합이 5라면, 저울추 7을 사용해서 7은 만들 수 있지만,
             6이라는 숫자를 만들어 낼 수 없다.
*/
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    int sum=0;
    
    sort(weight.begin(), weight.end());
    
    for(int i=0;i<weight.size();i++) {
        if(weight[i]>answer+1) return answer+1;
        answer+=weight[i];
    }
    
    return answer+1;
}