/*
    어려워서 풀이를 참고했다.
    가능한 모든 조합을 만들고 정렬 -> 유일성을 만족하는 키이면 -> 해당 키를 부분 집합으로 가진 나머지 키를 삭제(정렬된 상태기 때문)

    공식 풀이는 dfs와 bit를 사용하게 되어있었다. next_permutation을 이용하여 조합을 만들 수 있기 때문에 그렇게 구현해보았다.
    
    1. dfs
        vector<string> combination;

        void dfs(int k, string comb) {
            for(int i = k; i < col; i++) {
                comb += to_string(i);
                combination.push_back(comb);
                dfs(i+1, comb);
                comb = comb.substr(0, comb.length()-1);
            }
        }

    2. bit
        https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2019_blind_%ED%9B%84%EB%B3%B4%ED%82%A4.cpp

        다시 봐도 잘 이해가 안된다..

    이 문제는 나중에 또 다시 풀어봐야 할듯.. 퓨
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(string& a, string& b) {
    if(a.length() != b.length()) return a.length() < b.length();
    
    return a < b;
}

// 조합 만들기 
vector<int> combination(int n, int k) {
    vector<int> ret;
    
    for(int i = 0; i < n-k; i++) ret.push_back(0);
    for(int i = 0; i < k; i++) ret.push_back(1);
    
    return ret;
}

// 후보키 조건 확인 
bool isUnique(vector<vector<string>>& relation, string key) {
    map<string, int> check;
    for(int i = 0; i < relation.size(); i++) {
        string temp = "";
        for(int j = 0; j < key.length(); j++) {
            int num = key[j] - '0';
            temp += relation[i][num] + " ";
        }
        
        if(check[temp]) return false;
        check[temp]++;
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int n = relation[0].size();
    vector<string> keys;
    
    // 모든 키의 조합 만들기
    for(int k = 1; k <= n; k++) {
        vector<int> comb = combination(n, k);
        
        do {
            string key = "";
            for(int i = 0; i < comb.size(); i++) {
                if(comb[i] == 1) {
                    key += to_string(i);
                }
            }

            keys.push_back(key);

        } while(next_permutation(comb.begin(), comb.end()));
    }

    // 만들어진 조합 정렬(길이가 짧고 숫자가 작은 순서대로) 
    sort(keys.begin(), keys.end(), compare);
    
    for(int i = 0; i < keys.size(); i++) {
        
        // 유일성을 만족한다면
        if(isUnique(relation, keys[i])) {
            
            // 최소성을 만족시키기 위해 해당 키를 부분 집합으로 가지고 있는 나머지 키 삭제
            for(int j = keys.size()-1; j >= i; j--) {
                bool check = true;
                
                for(int k = 0; k < keys[i].length(); k++) {
                    
                    // 발견하지 못했다면 해당 키를 부분집합으로 가지고 있지 않으므로 더 확인할 필요가 없다.
                    if(keys[j].find(keys[i][k]) == string::npos) {
                        check = false;
                        break;
                    }
                }
                
                // 해당 키를 부분집합으로 가지고 있는 경우 삭제
                if(check) keys.erase(keys.begin()+j);
            }
            
            i--; // 키를 하나 지웠으므로 감소
            answer++; // 후보키를 하나 찾았으므로 증가 
        }
    }
    
    return answer;
}