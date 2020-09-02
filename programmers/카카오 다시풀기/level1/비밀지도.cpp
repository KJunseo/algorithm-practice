/*
    bitset을 이용하여 각 배열을 이진수로 변환하고 주어진 조건에 맞게 지도를 완성하였다.

    예전에 풀이를 참고하여 풀었던(https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2018_blind_%EB%B9%84%EB%B0%80%EC%A7%80%EB%8F%84.cpp) 것 같은데 풀이 방법은 달랐지만 혼자 풀었다.
*/
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        string ret = "";
        string a = bitset<16>(arr1[i]).to_string().substr(16-n);
        string b = bitset<16>(arr2[i]).to_string().substr(16-n);
        
        for(int j = 0; j < n; j++) {
            if(a[j] == '1' || b[j] == '1') ret += '#';
            if(a[j] == '0' && b[j] == '0') ret += ' ';
        }
        
        answer.push_back(ret);
    }
    
    return answer;
}