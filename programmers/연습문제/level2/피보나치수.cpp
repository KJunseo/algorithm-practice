/*
    재귀로 풀었다가 시간초과가 났다.
    dp로 해야할 것 같았다. dp로 하니 시간초과는 안났는데 7번부터 틀렸다고 나왔다.

    알아보니 결과값에 %1234567 해주면 틀리고 d[x]를 계산하는 부분에 %1234567를 해줘야했다;;
*/

int d[100001];

int dp(int x) {
    if(x==1 || x==2) return 1;
    
    if(d[x]!=0) return d[x];
    
    return d[x]=(dp(x-1)+dp(x-2))%1234567;
}

int solution(int n) { 
    
    return dp(n);
}