/*
    +1점
    각 자리수합을 구하고 원래 수를 합으로 모듈러연산 해본다.
*/
bool solution(int x) {
    int sum=0;
    int origin=x;
    
    while(x>0) {
        sum+=x%10;
        x/=10;
    }
    
    return origin%sum==0 ? true : false;
}