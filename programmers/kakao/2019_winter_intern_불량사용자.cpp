/*
    user_id의 모든 부분 집합을 구해서, banned_id의 크기와 같은 부분집합일 경우만
    내부를 비교하여 만족하면 answer를 + 하는 식으로 구현하려고 하였다.
    그러나 부분 집합 내부를 비교하는 것에서 실패했다.

    그래서 애초에 부분집합을 만들 때 크기가 banned_id의 사이즈 만큼인 것만 벡터에 추가해서 비교하려고 했다.
    코드를 짜다보니 굉장히 깔끔하지는 못한 것 같다.

    밑에 좋은 풀이를 추가하였다.. 비트 마스킹을 완벽히 이해하지는 못했지만 대략 느낌을 파악했다.
    아직 많이 멀었다는 것이 느껴진다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int b_size=banned_id.size(); // 만들어야할 부분 집합의 크기 
    vector<vector<string> > result; // 크기가 b_size인 모든 경우를 담는 벡터
    vector<string> temp; // 모든 경우를 담기 위한 임시 벡터 
    vector<vector<string> > finalResult; // 마지막 결과를 위한 벡터
    bool flag = false;
    
    sort(user_id.begin(), user_id.end()); // next_permutation을 사용하기 위해 미리 정렬

    do {
        for(int i=0;i<b_size;i++) temp.push_back(user_id[i]); // b_size 만큼 문자열을 집어넣음 
        
        result.push_back(temp); // 모든 경우를 담는 벡터에 담아줌
        temp.clear();
    } while(next_permutation(user_id.begin(), user_id.end()));
    
    result.erase(unique(result.begin(), result.end()), result.end()); // 중복되는 경우를 모두 삭제
    
    for(int i=0;i<result.size();i++) {
        flag=false;
        for(int j=0;j<result[i].size();j++) { 
            for(int k=0;k<banned_id[j].length();k++) {
                // 각 길이가 같고, 각 자리 문자가 일치하는 경우
                if(result[i][j].length()==banned_id[j].length() && (result[i][j][k]==banned_id[j][k] || banned_id[j][k]=='*')) flag=true;
                // 각 길이가 같지 않고, 각 자리 문자가 일치하지 않는 경우
                else {
                    flag=false;
                    break;
                }
            }

            if(!flag) break;

            // 모든 경우를 통과하는 경우 최종 결과에 넣어줌
            if(j==result[i].size()-1) finalResult.push_back(result[i]);
        }
    }
    
    // 중복 요소를 지우기 위해 모두 정렬
    /* (중복 요소를 위에서 지웠지만 또 중복 체크를 해줘야하는 이유)
        crodo frodo abc123
        frodo crodo abc123
        위의 두 경우는 같은 경우이기 때문 
    */
    for(int i=0;i<finalResult.size();i++) sort(finalResult[i].begin(), finalResult[i].end());
    
    sort(finalResult.begin(), finalResult.end());
    
    finalResult.erase(unique(finalResult.begin(), finalResult.end()), finalResult.end());
    
    return finalResult.size();
}

// 좋은 풀이(완벽히 이해하지 못했음)
bool visited[1<<8];
bool isPossible(string a, string b) {
    if(a.size()!=b.size()) return false; // 두 문자열의 사이즈가 다르면 다른 문자열이다.

    for(int i=0;i<a.size();i++) {
        // 각 문자열의 문자를 비교
        if(!(a[i]==b[i]||a[i]=='*')) return false;
    }

    return true;
}

// 순서를 생각하지 않는 경우이기 때문에, 방문 여부를 체크(비트 마스킹)
// bannedIdx: 제재된 유저 수 
// N: 제재 해야하는 유저 수 
// bits: 제재 유저 아이디 구성 ex. 00001001 -> 0번 3번 유저로 구성되어 있다는 뜻
// sanction: 각 banned_id에 맞는 제재 가능한 유저 아이디 벡터
void dfs(int bannedIdx, int N, int bits, const vector<vector<int>> &sanction) {

    // 제재된 유저 수와 제재 해야하는 유저수가 같아지면 종료
    if(bannedIdx==N) {
        visited[bits]=true; // 비트마스킹으로 방문 여부 체크
        return;
    }

    // 제재 가능한 유저 아이디 벡터를 돌면서
    for(auto next:sanction[bannedIdx]) {
        // 현재 유저 구성과 & 다음 유저 교집합 ex. 00000000 & 00000010 -> 00000000
        // 현재 유저 구성과, 다음 유저 구성에 겹치는 유저가 있으면 skip
        if(bits&(1<<next)) continue;

        // 현재 유저 구성 | 다음 유저 합집합 ex. 00000000 | 00000010 -> 00000010
        dfs(bannedIdx+1, N, bits|(1<<next), sanction);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>>sanction(banned_id.size()); // banned_id 사이즈 만큼 제재 가능한 유저아이디를 담는 벡터 생성

    for(int i=0;i<banned_id.size();i++) {
        string banned=banned_id[i];

        for(int j=0;j<user_id.size();j++) {
            string user=user_id[j];

            // user_id와 banned_id를 비교해서 조건에 부합하면 제재할 유저 아이디를 벡터에 추가
            if(isPossible(banned, user)) 
                sanction[i].push_back(j);
        }
    }

    dfs(0, banned_id.size(), 0, sanction);

    // (1<<8) : 256
    for(int i=0;i<(1<<8);i++)
        if(visited[i]) answer++;
    
    return answer;
}