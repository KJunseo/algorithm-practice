/*
    dfs를 사용해서 접근했다.
    begin, target, index, cnt(깊이), words, checked를 인자로 보내서 사용하려고 하였다.
    테스트케이스 2,3,4 번이 실패하였고, 거꾸로 탐색하면서 오는 경우도 있어서 도전했으나 실패하였다.

    접근 방법이 살짝 달랐다.

    단어 방문여부를 나타내기 위한 checked 배열을 선언해주고,
    dfs인자로 begin, target, words, checked, d(깊이)를 보내준다.

    모든 단어를 돌면서, 아직 단어를 방문하지 않았는데, begin과 두 자리의 값만 같은 경우,
    target과 그 수가 같고 answer가 깊이+1보다 크면 깊이+1로 업데이트 해준다.
    target과 그 수가 같지 않으면 방문 처리 후, dfs, 방문 처리 해제 순으로 진행한다.

*/
#include <string>
#include <string.h>
#include <vector>

using namespace std;
int answer = 51;

void dfs(string begin, string target, vector<string> words, bool checked[], int d) {

    // 모든 단어 체크
    for(int i=0;i<words.size();i++) {
        int neq=0; 

        // 방문하지 않은 단어 중에, begin과 단어의 차이계산
        for(int j=0;j<begin.length();j++) {
            if(!checked[i] && begin[j]!=words[i][j]) neq++;
        }

        // 한 글자만 다른 경우
        if(neq==1) {

            // 그 단어가 target과 동일하고, answer이 최소값이 아니면 갱신
            if(target==words[i] && answer>d+1) {
                answer=d+1;
                return;
            }

            // 단어 방문 처리
            checked[i]=true;

            dfs(words[i], target, words, checked, d+1);

            // 단어 방문 해제 
            checked[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    // 방문 여부 체크
    bool checked[words.size()];
    memset(checked, false, sizeof(checked));

    dfs(begin, target, words, checked, 0);

    if(answer==51) answer=0;

    return answer;
}