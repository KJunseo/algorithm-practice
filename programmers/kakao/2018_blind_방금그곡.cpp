/*
    문제의 설명을 보고 힌트를 얻어서,
    우선 재생시간에 따라 악보를 반복시켜서 실행되는 총 악보를 구하였다.
    그 악보를 이용하여, 멜로디와 비교해서 멜로디가 포함되는 경우,
    재생 시간 길이가 더 긴쪽을 정답으로 체크했다.

    테스트 케이스 8, 26, 28번을 통과하지 못했다.

    m = "ABC"
    musicinfos = ["13:00,13:15,BOOOM,ABC#DEFABC#DEFABC"]

    이런 경우를 고려하지 못했기 때문인데 find를 한 번만 써서 구현했었기 때문에 ABC# 을 만나면 종료해버렸기 때문이었다.
    따라서, #을 만났을 경우, 그 다음부터 다시 m을 탐색하도록 하였다.
*/
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 재생 시간을 구하는 부분 
int playTime(string musicinfos) {
    int minute=0;
    int startHour=stoi(musicinfos.substr(0, 2));
    int endHour=stoi(musicinfos.substr(6, 2));
    int startMin=stoi(musicinfos.substr(3, 2));
    int endMin=stoi(musicinfos.substr(9, 2));

    if(endHour-startHour>0) {
        endMin+=60*(endHour-startHour);
        minute=endMin-startMin;
    } else {
        minute=endMin-startMin;
    }
    return minute;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int answerTime=0;
    vector<int> time;
    vector<string> original;
    vector<string> title;
    vector<string> transformation;
    
    for(int i=0;i<musicinfos.size();i++) {
        int minute=playTime(musicinfos[i]); // 재생시간 구하기
        time.push_back(minute);
        
        istringstream ss(musicinfos[i]);
        string token;
        
        int cnt=0;
        while(getline(ss, token, ',')) {
            if(cnt==2) title.push_back(token); // 제목 분리
            else if(cnt==3) original.push_back(token); // 악보 분리
            cnt++;
        }
        
        int index=0;
        string music="";
        // 재생 시간 만큼 악보 반복재생하여 총 악보 구하기
        for(int j=0;j<minute;j++) {
            music+=original[i][index];
            if(original[i][index+1]=='#') j--;
            index++;
            if(index==original[i].length()) index=0;
        }
        transformation.push_back(music);
        
        // m이 총 악보에 포함되는 지 탐색하기
        index=transformation[i].find(m);
        while(index!=-1 && transformation[i][index+m.length()]=='#'){
            index=transformation[i].find(m, index+1);
        }

        if(index!=-1 && transformation[i][index+m.length()]!='#'){
            if(answer=="") {
                answer=title[i];
                answerTime=time[i];
            }
            else if(time[i]>answerTime) {
                answerTime=time[i];
                answer=title[i];
            }
        }
    }
    
    if(answer=="") answer="(None)";
    
    return answer;
}

    