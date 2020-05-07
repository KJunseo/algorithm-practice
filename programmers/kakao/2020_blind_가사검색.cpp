/*
    이중 for문을 사용하면, 효율성을 절대 통과할 수 없을 것 같았다.
    2018년 문제 중에 트라이를 사용했던 것이 생각나서 트라이를 구현해보려고 했다.
    word의 문자를 트라이에 삽입하고, queries를 하나씩 find하면서, ?가 나오면 해당 모든 문자가 가능하게 하려고 했는데
    find 구현이 쉽지 않았다.

    트라이를 사용하는 것은 맞았다.
    하지만, 원래 문자열을 사용하는 트라이 하나와, 문자열을 뒤집어 만든 트라이 총 2개를 이용해야한다고 한다.
    또 단어의 길이에 따라 다른 트라이에 넣어줘야한다고 한다.
    단어 하나의 길이가 10000이므로 트라이를 총 10000개 생성한다. 

    문자열 정렬 후, 이분 탐색을 하는 방법으로 구할 수도 있다고 한다.
*/
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int length = 26; // 알파벳 소문자
struct Trie {
    int count = 0; // 이 트라이에 존재하는 단어 수
    bool terminate = false; // 문자의 끝을 나타냄
    Trie *child[length]; // 자식 노드

    // 생성자. 처음 생성 시 1을 더해줘야하므로 count=1
    Trie(): count(1) {
        memset(child, 0, sizeof(child));
    }

    // 소멸자
    ~Trie() {
        for(auto &node : child) {
            if(node) {
                delete node;
            }
        }
    }

    // 트라이에 단어 추가
    void insert(const char *key) {
        if(*key=='\0') this->terminate=true; 
        else {
            const int next = *key-'a'; 

            if(child[next]==NULL) child[next] = new Trie();  
            else child[next]->count++;
          
            child[next]->insert(key+1);
        }
    }
    
    // 단어 탐색 
    int find(const char *key) {
        const int next= *key-'a';
        
        // ?인 경우 해당 위치의 자식들을 모두 탐색하여 갯수 세기 
        if(*key=='?') {
            int temp=0;
            for (int i=0;i<length;i++){
                if (child[i]!=NULL)
                    temp+=child[i]->count;
            }
            return temp;
        }

        if(*key==0 || child[next]==NULL) return 0; 

        return child[next]->find(key+1);
    }

};

Trie* trie[10001];
Trie* r_trie[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    // words 배열을 길이 별로 트라이에 넣음 
    // ?표 시작하는 경우도 있기 때문에 반대로도 넣음 
    for(string word : words) {
        int size=word.size();
        
        auto str=word.c_str();
        if(trie[size]==NULL) trie[size]=new Trie();
        trie[size]->insert(str);
        
        reverse(word.begin(), word.end());
        
        str=word.c_str();
        if(r_trie[size]==NULL) r_trie[size]=new Trie();
        r_trie[size]->insert(str);
    }
    
    // ?로 시작하면 반대 트라이에서 찾고, 아닌 경우 그냥 트라이에서 찾음
    for(string query : queries) {
        int size=query.size();
        
        auto str=query.c_str();
        if(query[0]!='?') {
            if(trie[size]==NULL) answer.push_back(0);
            else answer.push_back(trie[size]->find(str));
        } else {
            reverse(query.begin(), query.end());
            if(r_trie[size]==NULL) answer.push_back(0);
            else answer.push_back(r_trie[size]->find(str));
        }
    }
    
    return answer;
}