/*
    입력받은 날짜를 전부 일 단위로 바꾼 후, % 연산을 이용하여 요일을 찾아냈다.
    1점 밖에 얻지 못했다.
*/
#include <string>

using namespace std;

int eachDate[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[]={"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
string solution(int a, int b) {
    string answer="";
    int total=0;
    
    for(int i=1;i<a;i++) {
        total+=eachDate[i];
    }
    
    total+=b;
    
    if((total%7)-1==-1) {
        answer=day[6];
    } else {
        answer=day[(total%7)-1];
    }
    
    return answer;
}