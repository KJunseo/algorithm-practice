/*
    깔끔하지 않은 느낌이 있긴하지만 혼자 풀어냈다.
    한 글자식 잘라서 처리했고, 10인 경우는 두 자리이기 때문에 
    string으로 받아 char을 더해나가는 식으로 구현했다.

    토큰화로 풀 수도 있다고 한다.

    stringstream ss(dartResult);

    int score;
    char bonus;
    char option;

    ss >> score;

    bonus = ss.get();
    option = ss.get();

    if (option != '*' && option != '#') {
        ss.unget();
    }
*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    vector<int> result;
    int answer = 0;
    string num="";
    
    for(int i=0;i<dartResult.length();i++) {
        if(dartResult[i]>='0' && dartResult[i]<='9')
            num+=dartResult[i];
        else if(dartResult[i]=='S') {
            result.push_back(stoi(num));
            num="";
        } else if(dartResult[i]=='D') {
            result.push_back((int)pow(stoi(num), 2));
            num="";
        } else if(dartResult[i]=='T') {
            result.push_back((int)pow(stoi(num), 3));
            num="";
        } else if(dartResult[i]=='*') {
            bool flag=false;
            int temp1;
            
            if(result.size()>1) {
                temp1=result.back();
                result.pop_back();
                temp1*=2;
                flag=true;
            }
            
            int temp2=result.back();
            result.pop_back();
            temp2*=2;
            
            result.push_back(temp2);
            
            if(flag) 
                result.push_back(temp1);

        } else if(dartResult[i]=='#') {
            int temp=result.back();
            result.pop_back();
            temp*=-1;
            result.push_back(temp);
        }
    }
    
    for(int i=0;i<result.size();i++) 
        answer+=result[i];  
    
    return answer;
}