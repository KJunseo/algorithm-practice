/*
    dp문제이다.
    피보나치 처럼 늘어나는 것을 알 수 있다
*/
int dp[2001];

long long solution(int n) {    
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++) {
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    
    return dp[n];
}