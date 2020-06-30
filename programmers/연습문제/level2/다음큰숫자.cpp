/*
    bitset을 이용해 n의 1의 갯수를 알아내고
    최대 n이 1000000이므로 bitset 크기는 20으로 해주고 
    만약 1의 갯수가 4라면 00000000000000001111 초기화 해준 후
    next_permutation으로 반복하면서 n보다 제일 처음 커졌을 때 break 해주는 식으로 풀었다.
    정확성은 모두 통과했지만 효율성이 모두 시간초과가 났다.

    bitset을 이용하는 문제는 맞았다.
    n보다는 커야하니까 비교할 수를 n+1로 둔다.
    그 후 n의 1의 갯수와 비교할 수의 1의 갯수를 세면서 같아질 때까지 비교할 수를 ++해준다.
*/
#include <bitset>

using namespace std;

int solution(int n) {
    int one_count = bitset<20>(n).count();
    int answer = n+1;
    
    while(bitset<20>(answer).count()!=one_count) answer++;
    
    return answer;
}