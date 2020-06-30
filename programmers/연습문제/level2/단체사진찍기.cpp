/*
    +2점
    모든 경우의 수에서 조건 검사를 해주면 된다고 생각했다.
    next_permutation이 생각나서 next_permutation을 사용해서 모든 가능한 경우의 수를 만들어주고
    조건 검사를 모두 통과한 경우만 answer++해주었다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> people{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char>::iterator it;
    
    do {
        bool flag=true;
        
        for(int i=0;i<data.size();i++) {
            char to=data[i][0];
            char from=data[i][2];
            char command=data[i][3];
            int interval=data[i][4]-'0';
            
            it=find(people.begin(), people.end(), to);
            int to_idx=distance(people.begin(), it);
        
            it=find(people.begin(), people.end(), from);
            int from_idx=distance(people.begin(), it);
            
            if(command=='=') {
                if(abs(from_idx-to_idx)-1!=interval) {
                    flag=false;
                    break;
                }
            } else if(command=='<') {
                if(abs(from_idx-to_idx)-1>=interval){
                    flag=false;
                    break;
                }
            } else if(command=='>') {
                if(abs(from_idx-to_idx)-1<=interval) {
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag) answer++;
        
    } while(next_permutation(people.begin(), people.end()));
    
    return answer;
}