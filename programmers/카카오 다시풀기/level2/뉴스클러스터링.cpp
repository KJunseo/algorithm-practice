/*
    합집합, 교집합이 나와서 set_union, set_intersection을 사용하면 될 것 같았다.
    makeSet이라는 함수를 만들어 각 문자열을 집합으로 변환시켰고 이 과정에서 알파벳, 대소문자 등의 부가조건을 만족시켰다.
    set_union, set_intersection을 사용하기 위해 만들어진 집합을 sort해주기도 하였다.

    처음에는 합집합 교집합 둘 중 하나라도 0이게 예외처리를 해주었는데, 문제를 다시 보니 둘 다 0일 경우만 설명하고 있어서 ||을 &&로 바꾸니까 통과하였다.

    예전에 푼 방법이랑 크게 다르지 않게 푼 것 같다.(https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2018_blind_%EB%89%B4%EC%8A%A4%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%8A%B8%EB%A7%81.cpp)
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> makeSet(string s) {
    vector<string> ret;
    string str = "";
    
    for(int i = 0; i < s.length()-1; i++) {
        if(!isalpha(s[i]) || !isalpha(s[i+1])) continue;
        str += tolower(s[i]);
        str += tolower(s[i+1]);
        ret.push_back(str);
        str = "";
    }

    sort(ret.begin(), ret.end());
    
    return ret;
}

int solution(string str1, string str2) {    
    vector<string> v1 = makeSet(str1);
    vector<string> v2 = makeSet(str2);
    
    vector<string> sumOfSets;
    vector<string> intersection;
    sumOfSets.resize(v1.size()+v2.size());
    intersection.resize(v1.size()+v2.size());
    
    auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), sumOfSets.begin());
    sumOfSets.erase(it, sumOfSets.end());
    
    it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), intersection.begin());
    intersection.erase(it, intersection.end());
    

    double answer = 0;
    if(intersection.size() == 0 && sumOfSets.size() == 0) answer = 1;
    else answer = (double)intersection.size() / (double)sumOfSets.size();
    
    answer*=65536;
    
    return (int)answer;
}