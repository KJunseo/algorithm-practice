/*
    경우의 수를 사용해서 풀어야했다. 처음에는 dfs를 써야하나 시도하다가 실패했다..

    만약 A, B, C 세 종류의 옷이 각각 하나씩 있다고 가정하면
    A를 입는 경우 1        B를 입는 경우 1          C를 입는 경우 1
    A를 안 입는 경우 1      B를 안 입는 경우 1       C를 안 입는 경우 1
    총 2가지              총 2가지                총 2가지

    => 8가지 - 1(모두 안입는 경우 하나 제외)가 공식이다.
    즉, A의 갯수+1(A 입을 수 있는 갯수 + 아무것도 안 입는 경우 1) * B의 갯수+1 * C의 갯수+1 - 1이 답이다.

*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;

    for(auto elem : clothes) {
        um[elem[1]]++;
    }
    
   for(auto elem : um) {
        answer*=elem.second+1;
    }
    
    return answer;
}