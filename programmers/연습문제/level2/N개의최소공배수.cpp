/*
    최대 공약수, 최소 공배수 구하는 법은 공식처럼 사용하였고
    arr에서 하나씩 꺼내면서 최소 공배수 구한 값을 다시 arr에 넣고 
    arr가 하나가 남을 경우 그게 N개 수 중 최소공배수가 된다.
*/
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b!=0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int solution(vector<int> arr) {
    while(arr.size()>1) {
        int a=arr.back();
        arr.pop_back();
        
        int b=arr.back();
        arr.pop_back();
        
        arr.push_back(lcm(a, b));
    }
    
    return arr.front();
}