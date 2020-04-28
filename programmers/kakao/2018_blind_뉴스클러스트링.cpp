/*
    중 난이도 문제였지만, 그렇게 어렵다는 생각은 들지 않았다.
    set_union, set_intersection 만 사용할 줄 알면 쉽게 풀 수 있었다.
    각 집합은 두글자 씩 떼서 벡터에 넣고, 두 집합을 set_union, set_intersection 써서
    합집합, 교집합을 구한후, 자카드 유사도 공식에 넣어주면 된다.
    주의할 점은 int/int는 정수형으로 나오기 때문에 double로 바꿔줘서 풀었다.

    문제 의도는 multiset(중복 허용하는 set)을 사용해서 푸는 것이었다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> makeSet(string str) {
    vector<string> s;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    for(int i=0;i<str.length()-1;i++) {
        bool flag = false;
        string temp="";
        temp+=str[i];
        temp+=str[i+1];
        
        for(int j=0;j<2;j++) {
            if(temp[j]<'a' || temp[j]>'z') {
                flag=true;
                break;
            }
        }
        
        if(flag) continue; 
        s.push_back(temp);
    }
    
    sort(s.begin(), s.end());
    
    return s;
}

int solution(string str1, string str2) {
    double answer = 0;
    vector<string> s1, s2;
    vector<string> un, inter;
    
    s1=makeSet(str1);
    s2=makeSet(str2);
    
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(un));
    
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(inter));
    
    if(un.size()==0) return 65536;
    
    answer = (double)inter.size()/(double)un.size();
    
    return answer*65536;
}