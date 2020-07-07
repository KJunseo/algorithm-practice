/*
    순열을 구하는 문제여서 바로 next_permutation을 사용하였다.
    정확성은 모두 통과했으나 효율성에서 전부 시간초과가 났다.
    혹시 거꾸로 하면 상관없지 않을까해서 prev_permutation을 사용했지만 효율성은 통과하지 못했다.

    첫 번째 사람부터 마지막 사람까지 한 명씩 찾아 가야하는 문제였다.
    모든 경우의 수는 n!이며 숫자가 1~n으로 구성되어 있으므로 각 숫자가 모두 각각 첫 번째 자리에 올 수 있다.

    따라서 n!/n을 하면 각 숫자가 첫 번째 자리에 위치할 경우의 경우의 수를 알 수 있다.

    풀이를 많이 보긴 했는데 이해가 잘 안되었다. 다음에 다시 봐야할 것 같다.
*/
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    long long fact=1;
    
    for(int i=1;i<=n;i++) {
        fact*=i;
        people.push_back(i);
    }

    while(n) {
        fact/=n;
        int idx;
        
        if(k==0) {
            idx=n-1;
        } else {
            idx=(k-1)/fact;
        }
        
        // 해당 인덱스 번째 사람 추가 및 삭제
        answer.push_back(people[idx]);
        people.erase(people.begin()+idx);
        
        k%=fact;
        n--;
    }
    
    return answer;
}