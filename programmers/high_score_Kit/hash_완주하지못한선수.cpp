/*
    처음에는 이중배열로 모든 요소를 검사하였다. 정확성은 모두 통과하였으나, 효율성은 하나도 통과하지 못했다.

    그 다음으로 시도한 방법이, 참가자 벡터에서 하나씩 꺼내보면서, find를 통해 완주자 벡터에 있으면 지우고, 
    없으면 그 값을 리턴하도록 하였다. 마찬가지로 정확성은 모두 통과하였으나, 효율성은 하나도 통과하지 못했다.

    정렬을 해주면 되는 문제였다. 참가자, 완주자 벡터를 각각 정렬하고, 순서대로 비교해가면서 다른 값이 나온경우
    참가자벡터의 값이 정답이다.

    unordered_map이나 unordered_set같은 것으로도 구현할 수 있다.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 내가 시도한 방법.. 
// string solution(vector<string> participant, vector<string> completion) {
//     string answer = "";
    
//     while(!participant.empty()) {
//         string temp=participant.back();
//         participant.pop_back();    
        
//         vector<string>::iterator it;
//         it=find(completion.begin(), completion.end(), temp);
//         if(it!=completion.end()) {
//             completion.erase(it);
//         } else {
//             answer=temp;
//             break;
//         }
//         if(participant.size()==1) answer=participant.back();
//     }
    
//     return answer;
// }

// 정렬을 이용한 방법
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0;i<participant.size();i++) {
        if(participant[i]!=completion[i]) {
            answer=participant[i];
            break;
        }
    }
    
    return answer;
}

// unordered_map(hash_table 기반의 hash container)을 이용한 방법 
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    
    // 완주자 목록을 돌면서, 처음 보는 이름이면 삽입, 이미 존재하는 이름이면 count++
    for(auto elem : completion) {
        if(um.end()==um.find(elem)) {
            um.insert(make_pair(elem, 1));
        } else um[elem]++;
    }
    
    // 참가자 목록을 돌면서 없는 이름이 있으면 그이름이 정답. 
    // 그게 아니면 발견할 때 마다 count-- 하여 count가 0보다 작아질 경우 그게 정답.
    for(auto elem : participant) {
        if(um.end()==um.find(elem)) {
            answer=elem;
            break;
        } else {
            um[elem]--;
            
            if(um[elem]<0) {
                answer=elem;
                break;
            }
        }
    }
    
    return answer;
}