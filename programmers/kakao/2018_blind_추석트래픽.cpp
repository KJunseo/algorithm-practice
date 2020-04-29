/*
    문자열을 잘라서, ms로 바꾸어 반복문을 사용해서 풀어보려고 하였으나 실패했다.
    요청량이 변하는 순간은 각 로그의 시작과 끝 부분에서만 달라진다. 따라서 각 로그별로 두 번의 연산만 하면 된다.

    초단위로 시작-끝 시간을 벡터에 넣어준다.
    각 로그의 끝 시간을 기준으로 1초간 포함되는 요청의 수를 센다.

    오차를 줄이기 위해 절대값을 사용한다.
*/
#include <string>
#include <vector>
#include <algorithm>

#define abs(x) x<0 ? -x : x

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double> > sec;
    
    if(lines.size()==1) return 1;
    
    // 초로 시작, 완료 저장 
    for(int i=0;i<lines.size();i++) {
        double h = stod(lines[i].substr(11, 2))*3600;
        double m = stod(lines[i].substr(14, 2))*60;
        double s = stod(lines[i].substr(17, 6));
        double t = stod(lines[i].substr(24, 5));
        
        double totalSecEnd=h+m+s;
        double totalSecStart=totalSecEnd-t+0.001;
        
        sec.push_back(make_pair(totalSecStart, totalSecEnd));
    }
    
    // 각 로그의 끝 시간을 기준으로 1초간 포함된 로그 수 세기 
    for(int i=0;i<sec.size();i++){
    	double begin = sec[i].second;
    	double end = begin+0.999;

    	int cnt=0;
    	for(int j=i;j<sec.size();j++){
            double t1 = sec[j].second-begin;
            double t2 = sec[j].first-end;
    		if(abs(t1)>=0.001 && abs(t2)<=0.001) cnt++;
    	}

    	answer=max(answer, cnt);
    }
    
    return answer;
}