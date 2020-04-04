/*
    hash를 써보려 했으나, 굳이 안써도 될 것 같아서 find를 이용하였다.
    먼저 sort를 해준 후, 해당 수와 그 바로 다음 수를 find를 써서 비교하여 값이 0(접두사)으로 나온 경우,
    answer을 flase로 바꾸고 멈춰주니 통과했다.

    substr이나 unordered_map을 이용할 수도 있다.

    효율성은 unordered_map이 가장 좋았다.
*/
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

// 내가 풀이한 방법
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    bool flag=false;
    for(int i=0;i<phone_book.size();i++) {
        for(int j=i+1;j<phone_book.size();j++) {
            if(phone_book[j].find(phone_book[i])==0) {
                answer=false;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    
    return answer;
}

// substr을 이용한 방법
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size()-1;i++) {
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())) {
            answer=false;
            break;
        }
    }
    
    return answer;
}

// unordered_map(hash_table 기반의 hash container)을 이용한 방법
bool solution(vector<string> phone_book) {
    bool answer = true;
    bool flag = false;
    unordered_map <string, int> um;
    
    // phone book안의 전화번호를 unordered_map에 저장
    for(int i=0;i<phone_book.size();i++) {
        um[phone_book[i]]=1;
    }
    
    // phone book안의 전화번호를 모두 검색
    for(int i=0;i<phone_book.size();i++) {
        string phone_num="";
        
        for(int j=0;j<phone_book[i].size();j++) {
            phone_num+=phone_book[i][j]; // 각 전화번호를 한자리씩 더해줌(ex. 119인 경우 -> 1, 11, 119)

            // 만들어진 번호가 unordered_map에 존재는 하지만, phone book의 번호와 다른 경우 answer=false
            if(um[phone_num] && phone_num!=phone_book[i]) {
                answer=false;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    
    return answer;
}