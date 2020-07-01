/*
    공백 기준으로 숫자를 분리해야하기 때문에 stringstream을 사용했다.
    그 후 sort하고 맨 처음과 맨 끝 값을 answer에 붙여 출력했다.
*/
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp="";
    vector<int> num;
    
    while(ss >> temp) {
        num.push_back(stoi(temp));
    }
    
    sort(num.begin(), num.end());
    
    answer+=to_string(num[0]);
    answer+=' ';
    answer+=to_string(num[num.size()-1]);
    
    return answer;
}