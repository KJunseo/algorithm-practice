/*
    timetable을 정렬 하고,
    9시부터 시작하여, 시간을 기준으로 풀려고 시도하였다.
    현재 시간 기준으로 이전에 도착한 크루들을 m만큼 태우고,
    t만큼 시간을 업데이트 해주면서 계산하려고 하였으나, 구현을 실패하였다..

    시간을 모두 분으로 바꿔 풀이한 풀이를 보았다.
    크루들의 도착 시간을 분으로 바꿔 벡터에 저장한 후 오름차순 정렬한다.
    그 후 버스 정원에 맞게 크루들을 차례로 태운다.
    마지막 버스인 경우 콘이 무조건 타야하므로, 
    마지막 버스가 크루들로 가득 찬 경우, 가장 마지막에 탄 크루보다 1분 일찍 도착하고,
    마지막 버스에 자리가 있는 경우, 버스가 도착한 현재 시간에 도착하면 된다.

    이제 얼핏 풀이 방향은 맞게 생각하는 것 같은데, 구현하는 것에 어려움을 느낀다..
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> mtable;
    int time=540; // 09:00
    
    // 크루들의 도착 시간을 분으로 바꿔서 저장 
    for(int i=0;i<timetable.size();i++) {
        int hour = stoi(timetable[i].substr(0,2));
        int min = stoi(timetable[i].substr(3,2));
        mtable.push_back(hour*60+min);
    }
    
    sort(mtable.begin(), mtable.end());
    
    int idx=0; // 현재까지 탄 크루의 인덱스
    int conn=0; // 콘이 탈 시간
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=idx;j<mtable.size();j++) {
            if(mtable[j]<=time) {
                idx++;
                cnt++;
            }
            if(cnt==m) break; // 버스 정원이 가득 찬 경우
        }
        
        // 마지막 버스이면(콘이 무조건 타야하는 버스)
        if(i==n-1) {
            if(cnt==m) // 콘이 타야하는데 버스가 가득 차 있는 경우 
                conn=mtable[idx-1]-1; // 타 있는 마지막 사람보다 1분 빠르게 도착하기
            else // 자리가 비어있으면 현재 시간 딱 맞춰서 도착하기
                conn=time;
        }
        
        time+=t;
    }
    
    int hour = conn/60;
    if(hour<10) 
        answer+= "0";
    
    answer+= to_string(hour) + ":";
    
    int min = conn%60;
    if(min<10) 
        answer+="0";
    
    answer+= to_string(min);
    
    return answer;
}