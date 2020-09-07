/*
    공백으로 나누어져있어 stringstream을 사용하면 쉽게 문자열을 분해할 수 있다고 생각했다.
    map을 사용해 uid - nickname을 연결시켜주고
    다시 반복문을 돌면서 들어오고 나가고를 출력해줬다.(똑같은 반복문, stringstream을 2번 쓴게 좀 찝찝하긴 하다.)
*/
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    
    for(int i = 0; i < record.size(); i++) {
        
        stringstream ss(record[i]);
        string command, uid, nickname;
        
        ss >> command >> uid >> nickname;
        
        string ret = "";
        if(command[0] == 'E' || command[0] == 'C') user[uid] = nickname;
    }
    
    for(int i = 0; i < record.size(); i++) {
        
        stringstream ss(record[i]);
        string command, uid, nickname;
        
        ss >> command >> uid >> nickname;
        
        string ret = "";
        if(command[0] == 'E') {
            ret += user[uid];
            ret += "님이 들어왔습니다.";
            answer.push_back(ret);
        } else if(command[0] == 'L') {
            ret += user[uid];
            ret += "님이 나갔습니다.";
            answer.push_back(ret);
        }
    }
    
    return answer;
}