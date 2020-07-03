/*
    dp문제이다.
    그림을 그려보면

    n=1 -> 1가지
    n=2 -> 2가지
    n=3 -> 3가지
    n=4 -> 5가지 

    3부터 피보나치로 증가한다. 즉 dp[n] = fibo(n-1)+fibo(n-2) 이다.
*/
int dp[60001];

int solution(int n) {
    int answer = 0;
    
    if(n==1) return 1;
    else if(n==2) return 2;
    
    if(dp[n]>0) return dp[n];
    
    return dp[n] = (solution(n-1) + solution(n-2))%1000000007;
}