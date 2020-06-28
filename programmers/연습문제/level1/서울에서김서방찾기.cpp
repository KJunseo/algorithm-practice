/*
    +1점
    길이가 1000이하고 한 번밖에 나오지 않으므로 그냥 완전 탐색으로 Kim이 나올 때 까지 찾는다.

    find 함수를 사용해도 된다. 
*/
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    
    for(int i=0;i<seoul.size();i++) {
        if(seoul[i]=="Kim") {
            return "김서방은 " + to_string(i) +"에 있다";
        }
    }
    
    return " ";
}