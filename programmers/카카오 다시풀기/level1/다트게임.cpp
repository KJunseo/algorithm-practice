/*
    처음에는 문자열을 각각 시도로 나누어 저장한 후 계산하려고 하였다. 
    isdigit으로 하나씩 검사하여 숫자를 기준으로 substr로 나누려고 하였으나 10이 두자리라서 다른 방법으로 구현하기로 했다.

    isdigit으로 숫자부분을 + 연산으로 찾아내고
    D, 와 T를 만난 경우 각각 제곱, 세제곱을 해주었다. 이 때 숫자를 담은 문자열을 초기화해줌으로 각 시도를 구분하였다.
    만약 *, #가 있는 경우 각각 *2, *-1을 해주었다.

    map을 이용해 각 시도를 저장했다.

    이전 풀이를 보니 stringstream으로 풀 수도 있다고 한다. 알아놓으면 편할 것 같다.
    (이전 풀이: https://github.com/KJunseo/algorithm-practice/blob/master/programmers/kakao/2018_blind_%EB%8B%A4%ED%8A%B8%EA%B2%8C%EC%9E%84.cpp)

    stringstream ss(dartResult);

    int score;
    char bonus;
    char option;

    ss >> score;
    bonus = ss.get(); // 한 글자 get
    option = ss.get(); // 한 글자 get

    if(option != '*' && option != '#') {
        ss.unget(); // 포인터를 뒤로 이동(숫자를 get했기 때문)
    }
*/
#include <string>
#include <map>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    map<int, int> m;
    int answer = 0;
    int length = dartResult.length();
    int tryNum = 1;
    string num = "";
    
    for(int i = 0; i < length; i++) {
        if(isdigit(dartResult[i])) {
            num += dartResult[i];
        } else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            int score = stoi(num);
            num = "";
      
            if(dartResult[i] == 'D') {
                score = (int)pow(score, 2);
            } else if(dartResult[i] == 'T') {
                score = (int)pow(score, 3);
            } 
            
            m[tryNum++] = score;
        } else if(dartResult[i] == '*' || dartResult[i] == '#') {
            if(dartResult[i] == '*') {
                m[tryNum-1] = m[tryNum-1] * 2;
                
                if(tryNum > 2) {
                    m[tryNum-2] = m[tryNum-2] * 2;
                } 
            } else if(dartResult[i] == '#') {
                m[tryNum-1] = m[tryNum-1] * -1;
            } 
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++) {
        answer += it->second;
    }
    
    return answer;
}