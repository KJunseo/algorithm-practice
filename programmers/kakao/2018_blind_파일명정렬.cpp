/*
    이 문제는 정말로 문제가 설명하는 순서대로 구현만 하면 되는 문제였다.
    file을 하나로 관리하기 위해 구조체를 만들어 파일명을 분리시켜서 저장하였다.

    * 일반 sort를 쓰면 안된다는 데 왜 통과가 되는지 모르겠다.
*/
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct fileName {
    int index; // 입력 순서 
    string head;
    int number;
    string tail;
};

bool compare(const fileName &a, const fileName &b) {
    if(a.head<b.head) return true; // head 사전순 
    else if(a.head==b.head) {
        if(a.number<b.number) return true; // 숫자 오름차순 
        else if(a.number==b.number) {
            if(a.index<b.index) return true; // 입력순
            return false;
        }
        return false;
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> result;
    
    for(int i=0;i<files.size();i++) {
        fileName temp;
        
        // 입력 순서 저장 
        temp.index=i;
        
        // head 부분 분리 
        string h="";
        int index=0;
        for(int j=index;j<files[i].length();j++, index++) {
            if(!isdigit(files[i][j])) h+=files[i][j];
            else break;
        }
        transform(h.begin(), h.end(), h.begin(), ::tolower);
        temp.head=h;
        
        // number 부분 분리 
        string num="";
        for(int j=index;j<files[i].length();j++, index++) {
            if(isdigit(files[i][j])) num+=files[i][j];
            else break;
        }
        temp.number=stoi(num);
        
        // tail 부분 분리 
        string t=files[i].substr(index);
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        temp.tail=t;
        
        result.push_back(temp);
    }
    
    stable_sort(result.begin(), result.end(), compare);
    // sort(result.begin(), result.end(), compare);
    
    // 원래 파일명의 값을 그대로 넣어주기 위해 구조체의 index사용
    for(int i=0;i<files.size();i++) 
        answer.push_back(files[result[i].index]);
    
    
    return answer;
}