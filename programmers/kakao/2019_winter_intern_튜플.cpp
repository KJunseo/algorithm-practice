/*
    문자열을 다루는 게 익숙하지 않아 고생한 문제이다.
    처음에는 stringstream도 써보려고 하고 token으로 나눠 보려고도 시도 했으나 다 실패했다.

    문자열에는 총 4가지 경우가 있다.
    1. 숫자: 벡터에 넣어주면 된다.
    2. { : 무시해주면 된다.
    3. , : ',' 문자는 {} 내부에도 존재하고, 외부에도 존재한다. 
            외부에 존재하는 경우는 index조작으로 제거해준다.
            따라서 내부에 존재하는 경우만 처리하면 된다.
            내부에 , 를 만나면, 임시벡터에 현재까지 숫자를 넣어주면 된다.
    4. } : } 문자를 만나면, 우선 숫자를 넣어줘야한다. 예를 들어 {1,2,3} 인 경우,
            ,를 만났을 때 숫자를 넣는다고 해도 1, 2는 넣을 수 있지만 3을 넣지 못하기 때문이다.
            따라서 }를 만났을 때 숫자를 넣어준다.
            그 후, } 문자는 한 집합의 끝을 의미하므로, 임시벡터 자체를 결과벡터에 넣어주면 된다.

    그 후, 결과벡터를 길이순으로 정렬 후, 제일 처음 요소를 answer에 넣어준다.
    마지막으로, 결과벡터를 전부 순회하면서, answer에 해당 숫자가 없는 경우만 추가해주면 된다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 길이 순으로 정렬 
bool compare(vector<int> a, vector<int> b) {
    if(a.size()<b.size()) return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector <vector<int> > numbers; // 전체 집합을 담아주는 결과 벡터
    vector <int> temp; // 한 집합({})을 담아주는 임시벡터
    string tempNum; // 숫자가 2자리 이상인 경우도 있기 때문에 임시 string을 이용
    
    for(int i=1;i<s.length()-1;i++) {

        if(s[i]=='{') { // 무시 
            continue;
        } else if(s[i]=='}') { // 한 집합의 마지막 숫자를 삽입 후, 임시 벡터 전체를 결과 벡터에 삽입 
            temp.push_back(atoi(tempNum.c_str()));
            tempNum="";
            numbers.push_back(temp);
            temp.clear();
            i++; // 외부 , 를 skip하기 위한 인덱스 조작 
        } else if(s[i]==',') { // 임시 벡터에 숫자를 넣어줌
            temp.push_back(atoi(tempNum.c_str()));
            tempNum="";
        } else { 
            tempNum+=s[i];
        }
    }
    
    sort(numbers.begin(), numbers.end(), compare); // 길이 순 정렬 
    
    answer.push_back(numbers[0][0]); // 제일 처음 요소 삽입
    
    // answer에 존재하지 않는 원소만 삽입
    for(int i=1;i<numbers.size();i++) {
        for(int j=0;j<numbers[i].size();j++) {
            if(find(answer.begin(), answer.end(), numbers[i][j])==answer.end()) {
                answer.push_back(numbers[i][j]);
            }
        }
    }
    
    return answer;
}