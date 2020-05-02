/*
    길이순으로 정렬 후, 맨 첫 문자열부터 한 글자씩 떼어,
    그 글자로 시작하는 문자열의 갯수를 세고, 그 갯수가 하나 이상이면 중단 후, 문자를 하나 더 붙여서,
    결국 검색하는 문자가 단어에 하나만 포함될 때까지의 횟수를 세면 되지 않을까 했다.
    예제 케이스를 모두 통과하고, 테스트케이스 5번까지 통과하길래 맞나보다 싶었는데, 
    6, 8, 12, 13, 16, 17, 20 에서 시간초과가 났다.

    모든 문자열을 비교하려고 하면 시간초과가 날 수 밖에 없다고 한다.
    트라이라는 자료구조를 사용하거나, 사전 순 정렬 후 인접 단어만 비교하면 된다고 한다.(사전 순 정렬하면 어떤 단어와 앞부분이 가장 많이 일치하는 단어는 인접한 두 단어 중 하나이기 때문에)

    인접 단어만 비교해보니 통과하였다.

    트라이 사용 방법은 아래에 첨부하였다.(참고: https://dev-dream-world.tistory.com/77)
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    int cnt = 0;

    sort(words.begin(), words.end()); // 사전 순 정렬
    
    for(int i=0;i<words.size();i++) {
        string sub;
        
        for(int j=1;j<=words[i].length();j++) {
            sub=words[i].substr(0, j); // 한 글자씩 늘려가면서 비교하기 위한 문자열
            answer++; // 입력 횟수 ++
            cnt=0;
            
            if(i==words.size()-1){ // 마지막 단어일 경우 다음 단어가 없으므로 전 단어만 비교 
                for(int k=i-1;k<=i;k++) {
                    if(words[k].find(sub)==0) cnt++;
                }
            } else if(i>0 && i!=words.size()-1) { // 중간 단어일 경우 앞뒤 모두 비교 
                for(int k=i-1;k<=i+1;k++) {
                    if(words[k].find(sub)==0) cnt++;
                }
            } else if(i==0){ // 첫 단어인 경우 전 단어가 없으므로 다음 단어만 비교
                for(int k=0;k<=1;k++) {
                    if(words[k].find(sub)==0) cnt++;
                }
            } 

            if(cnt==1) break; // cnt가 1이면 입력 종료
        }
    }
    
    return answer;
}


// 트라이 사용
/*
1번 예제를 트라이를 사용해서 나타내면 아래와 같이 된다.

         root
          |
          g(count==3)
         /  \
        o(2) u(1)
        |    |
        n(1) i(1)
        |    |
        e(1) l(1)
             |
             d(1)
*/
#include <cstring>

const int length = 26;

typedef struct TriNode {
    int count = 0; // 현재 학습 된 문자가 몇개인지 알려주는 변수
    bool terminate = false; // 문자의 끝을 알려주는 변수
    TriNode *child[length];

    // 생성자
    TriNode() {
        memset(child, 0, sizeof(child));
    }

    // 소멸자
    ~TriNode() {
        for(auto &node : child) {
            if(node) {
                delete node;
            }
        }
    }

    void insert(const char *key) {
        if(*key==0) this->terminate=true; // 마지막 문자인 경우
        else {
            const int next = *key-'a'; // 소문자 인덱스로 변환

            if(child[next]==NULL) child[next] = new TriNode(); // 현재 문자가 생성되어 있지 않은 경우면 새로운 문자 인덱스 트리 생성

            // 다음 문자로 인덱스 트리 생성
            child[next]->count++;
            child[next]->insert(key+1);
        }
    }

    int find(const char *key, const int cnt) {
        const int next= *key-'a';

        if(*key==0 || child[next]==NULL) return cnt-1; // 끝 문자인 경우 끝 문자 전 문자만 입력하면 됨

        // 해당 문자로 이어지는 문자열이 없는 경우(count==1) 탐색 종료.(다른 트리에 속하기 때문에)
        if(child[next]->count==1) return cnt;

        return child[next]->find(key+1, cnt+1);
    }

} Tri;

int solution(vector<string> words) {
    int answer = 0;
    Tri *tri = new Tri();

    for(auto word : words) {
        auto current = word.c_str();
        tri->insert(current);
    }

    for(auto word : words) {
        auto current = word.c_str();
        answer+=tri->find(current, 1);
    }

    delete tri;

    return answer;
}
