/*
    모든 수의 합이 s가 되어야한다. 또 곱의 값이 가장 크려면 각 원소들의 차가 최소가 되어야한다.
    따라서 우선 s를 n으로 나누어준다. 그럼 n등분 한 값이 나오고 그 수를 answer에 넣어준다.
    그 후 s에서 answer에 넣어준 수를 빼주고, n도 -- 해준다. 
    이 과정을 반복하면 모든 원소의 합이 s이고 곱은 최대인 값이 나온다.

    처음에 push_back으로 값을 집어넣으니 효율성에서 시간 초과가 나왔다. resize를 통해 벡터 크기를 정해주고 idx를 통해 값을 넣으니 통과했다.
*/
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int num=0;
    int idx=0;
    
    if(n>s) answer.push_back(-1);
    else {
        answer.resize(n);
        
        for(int i=n;i>0;i--) {
            num=s/i;
            answer[idx]=num;
            s-=num;
            idx++;
        }
    }
    
    return answer;
}