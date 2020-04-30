/*
    풀긴하였지만... +1점...
    반복문으로 넣을까 하다가, 26개라서 그냥 map에 집어넣고 시작을 하였다.(반복문으로 넣어주는 게 나을거같다.)
    한 글자씩 더해가면서, 처음 보는 문자열이 나오면 map에 추가해주고,
    처음 보는 문자열이 나오기 직전의 문자열의 값을 answer에 넣어주었다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    map<string, int> m={
        {"A", 1}, {"B", 2}, {"C", 3}, {"D", 4}, {"E", 5}, {"F", 6}, {"G", 7}, {"H", 8}, {"I", 9}, {"J", 10}, {"K", 11}, {"L", 12}, {"M", 13}, {"N", 14}, {"O", 15}, {"P", 16}, {"Q", 17}, {"R", 18}, {"S", 19}, {"T", 20}, {"U", 21}, {"V", 22}, {"W", 23}, {"X", 24}, {"Y", 25}, {"Z", 26}
    };
    vector<int> answer;
    string last="";
    int index=27;
    
    for(int i=0;i<msg.length();i++) {
        string temp="";
        temp+=msg[i];
        
        for(int j=i+1;j<=msg.length();j++) {            
            temp+=msg[j];
            if(m.find(temp)==m.end()) {
                m.insert(make_pair(temp, index));
                answer.push_back(m.at(temp.substr(0, temp.length()-1)));
                index++;
                break;
            }
            i++;
        }
    }
    
    return answer;
}