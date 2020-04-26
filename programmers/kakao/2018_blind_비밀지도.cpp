/*
    bitset을 이용하여 구현하였다. 그러나 +1점 밖에 받지 못했다 ㅎ..

    비트연산을 다루는 문제였다.
    두 지도가 겹치는 것이므로 OR(|) 연산을 사용한다.
    나누기 2(>>1)를 하면서 10진수를 2진수로 바꿔서 계산한 후 answer벡터에 넣는다.
*/
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0;i<n;i++) {
        int temp = arr1[i]|arr2[i];
        string ans="";
        for(int j=0;j<n;j++) {
            if(temp%2==0) ans=' '+ans;
            else ans='#'+ans;
            temp=temp>>1;
        }
        answer.push_back(ans);
    }
    
    return answer;
}

// +1점 풀이 ..
#include <bitset>

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;
    string line="";
    string temp;
    
    for(int i=0;i<arr1.size();i++) {
        temp=bitset<16>(arr1[i]).to_string();
        for(int j=16-n;j<temp.length();j++) {
            line+=temp[j];
        }
        map1.push_back(line);
        line="";
    }
    
    for(int i=0;i<arr2.size();i++) {
        temp=bitset<16>(arr2[i]).to_string();
        for(int j=16-n;j<temp.length();j++) {
            line+=temp[j];
        }
        map2.push_back(line);
        line="";
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map1[i][j]=='1' || map2[i][j]=='1') {
                line+='#';
            } else {
                line+=' ';
            }
        }
        answer.push_back(line);
        line="";
    }
    
    return answer;
}