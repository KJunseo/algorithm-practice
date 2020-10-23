/*
<tc(input)>
2000
woni request 09:12:29
brown request 09:23:11
brown leave 09:23:44
jason request 09:33:51
jun request 09:33:56
cu request 09:34:02

풀긴 했는데 테스트케이스가 하나 뿐이라 정확한 풀이인지는 모르겠다.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

const int START = 9 * 3600;
const int END = 10 * 3600;

vector<string> answer;
map<string, bool> ans;

int convertTime(string time) {
    int h = stoi(time.substr(0, 2)) * 3600;
    int m = stoi(time.substr(3, 2)) * 60;
    int s = stoi(time.substr(6, 2));
    return h + m + s;
}

int main(void) {
    int totalTicket;
    vector<string> logs;

    scanf("%d", &totalTicket);
    for(int i = 0; i < 7; i++) {
        string log;
        getline(cin, log);
        if(log != "")
            logs.push_back(log);
    }

    string baseId;
    int base = 0;
    for(int i = 0; i < logs.size(); i++) {
        stringstream ss(logs[i]);
        string id, action, time;
        
        ss >> id >> action >> time;

        int sec = convertTime(time);

        if(!(totalTicket + 1))
            break;

        if(sec < START || sec + 60 > END)
            break;

        if(action.compare("request") == 0) {
            if(base < sec) {
                totalTicket--;
                base = sec + 60;
                baseId = id;
                ans[id] = true;
            }
        } else if(action.compare("leave") == 0) {
            if(baseId == id) {
                base = 0;
                totalTicket++;
                ans[id] = false;
            }
        }
    }

    map<string, bool>::iterator it;
    for(it = ans.begin(); it != ans.end(); it++) {
        if(it->second)
            cout << it->first << "\n";
    }

    return 0;
}