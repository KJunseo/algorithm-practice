/*
    일단 연산자의 종류를 set으로 저장하고 next_permutation을 통해 우선 순위 경우의 수를 만들었고
    숫자도 따로 벡터에 저장해놓고 계산하려고 하였다.

    erase와 insert를 사용해서 계산 결과를 업데이트 해주었다.
    푼 사람이 8명 밖에 없었는데 9번째로 풀어서 기분이 좋았다.
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    set<char> s;
    vector<char> all_op;
    vector<char> op;
    vector<long long> num;
    
    string temp="";
    for(int i=0;i<expression.length();i++) {
        if(!isdigit(expression[i])) {
            s.insert(expression[i]); // 총 사용된 연산자 종류를 알아내기 위함 
            all_op.push_back(expression[i]); // 사용된 모든 연산자와 그 순서를 저장 
            num.push_back(stoi(temp)); // 계산해야 하는 숫자를 순서대로 저장 
            temp="";
        } else temp+=expression[i];
    }
    num.push_back(stoi(temp)); 
    
    // next_permutation을 사용하기 위해 벡터에 넣음 
    set<char>::iterator it;
    for(it=s.begin();it!=s.end();it++) {
        op.push_back(*it);
    }
    
    do {
        // 벡터의 erase를 사용하기 위해 임시 벡터 생성
        vector<char> temp_op = all_op; 
        vector<long long> temp_num = num;
        
        for(int i=0;i<op.size();i++) { // 연산자 우선 순위대로 반복 
            for(int j=0;j<temp_op.size();j++) { // 원래 연산사 순서
                if(temp_op[j]==op[i]) { // 현재 체크하는 연산자와 원래 순서의 연산자가 같은 경우
                    long long temp;
                    if(op[i]=='*') {
                        temp=temp_num[j]*temp_num[j+1]; // 연산자 기준으로 양 옆 곱하기 
                        i--; // 동일한 연산자가 있을 수도 있기 때문에 다시 해당 연산자부터 탐색
                    } else if(op[i]=='+') {
                        temp=temp_num[j]+temp_num[j+1]; // 연산자 기준으로 양 옆 더하기
                        i--; // 동일한 연산자가 있을 수도 있기 때문에 다시 해당 연산자부터 탐색
                    } else if(op[i]=='-') {
                        temp=temp_num[j]-temp_num[j+1]; // 연산자 기준으로 양 옆 빼기
                        i--; // 동일한 연산자가 있을 수도 있기 때문에 다시 해당 연산자부터 탐색
                    }
                    
                    temp_op.erase(temp_op.begin()+j); // 사용한 연산자 삭제 
                    temp_num.erase(temp_num.begin()+j, temp_num.begin()+j+2); // 계산한 두 숫자 삭제 
                    temp_num.insert(temp_num.begin()+j, temp); // 계산된 새로운 숫자 삽입 
                    
                }
            }
        }
        
        // 절대값이 가장 큰 값으로 업데이트
        if(answer<abs(temp_num.back())) {
            answer=abs(temp_num.back());
        }
         
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}