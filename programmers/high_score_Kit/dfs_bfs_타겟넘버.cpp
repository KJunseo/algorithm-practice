/*
    dfs는 아직 별로 익숙하지 않다.
    이게 맞나 하면서 풀었는데 맞았다.

    그냥 배열의 각 요소들을 더하는 경우와, 빼는 경우 2가지가 있기 때문에 
    두 가지의 경우의 수로 dfs를 진행하였다. 
    모든 배열을 탐색했을 때, target과 값이 같으면 answer을 ++ 시켜줬다.
*/
#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int target, int sum, int repeat) {
    
    if(repeat==numbers.size()) {
        if(sum==target) answer++;
        return;
    }
    
    dfs(numbers, target, sum+numbers[repeat], repeat+1);
    dfs(numbers, target, sum-numbers[repeat], repeat+1);
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}