/*
    처음엔 그냥 정렬해서 앞에서 두개씩 체크하면 되는거 아닌가 라고 생각했으나,
    정렬 후, 가장 큰 수와 가장 작은 수를 체크하여 같이 태워 보내는 식으로 했어야했다.
    그다지 어려운 문제는 아니었다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int right_idx=people.size()-1;
    
    sort(people.begin(), people.end(), greater<int>());
    
    for(int i=0;i<people.size();i++) {
        int currentWeight=people[i];
        int smallWeight=people[right_idx];
        
        if(i>right_idx) break;
        
        if(currentWeight+smallWeight<=limit) right_idx--;
        
        answer++;
    }
    
    return answer;
}