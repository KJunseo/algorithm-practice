/*
    +1점
    최대공약수는 유클리드 호제법을 사용한다.
    최소공배수는 최대공약수를 만든 함수를 이용한다.
*/
#include <vector>

using namespace std;

// 최대 공약수 
int gcd(int a, int b) {
    int c;
    
    while(b!=0) {
        c=a%b;
        a=b;
        b=c;
    }
    
    return a;
}

// 최소 공배수 
int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    
    return answer;
}