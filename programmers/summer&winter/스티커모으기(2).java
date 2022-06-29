/*
    dfs를 사용하는 문제라고 생각했다.
    
    뭔가를 잘못했는지 통과하지 못하여 풀이를 봤는데 DP를 사용한다.
    DP는 거의 구현 할 줄 몰라서 이해하는데 어려움을 겪었다.

    dp배열에 저장하는 값은 i번째까지 스티커를 조건에 맞게 잘 뜯은 경우의 최대값이다.
    
    ... i-2 i-1 i ... 로 보면
    i번째 스티커를 뜯으려면 i-1번째 스티커를 뜯을 수 없다. 따라서 dp[i-2]+sticker[i] 가 된다.
    i번째 스티커를 뜯지 않으면 i-1번째 스티커를 뜯던지 말던지 관계가 없으므로 dp[i-1] 이다.
    두 값의 최대값이 dp[i]의 값이다.

    위의 방법은 스티커배열이 일직선인 경우이다.
    원형인 경우는 첫 번째 스티커를 뜯냐 안뜯냐 2가지 경우로 나누어진다.
    따라서 각각 경우에 따라 일직선때 사용한 방법을 적용하면 된다.
*/

class 스티커모으기 {
    public int solution(int sticker[]) {

        if(sticker.length==1) return sticker[0]; // 스티커가 하나 뿐인 경우도 생각 

        int [] dp1 = new int[sticker.length];
        int [] dp2 = new int[sticker.length];
        
        // 첫 번째 스티커를 뜯는 경우 
        dp1[0]=sticker[0]; 
        dp1[1]=sticker[0]; // 두 번째 스티커는 첫 번째 스티커를 이미 뜯었으므로 뜯을 수 없기 때문에 sticker[0] 값이다. 
        
        for(int i=2;i<sticker.length-1;i++) {
            dp1[i]=Math.max(dp1[i-1], dp1[i-2]+sticker[i]);
        }
        
        // 첫 번째 스티커를 뜯지 않는 경우
        dp2[0]=0;
        dp2[1]=sticker[1];
        
        for(int i=2;i<sticker.length;i++) {
            dp2[i]=Math.max(dp2[i-1], dp2[i-2]+sticker[i]);
        }

        return Math.max(dp1[sticker.length-2], dp2[sticker.length-1]);
    }
}


// dfs 로 시도하다가 실패
/*class Solution {
    boolean [] visit = new boolean[100000];
    int total;
    int answer;
    int num;
    int [] s = new int[total];

    void dfs(int sum, int cnt) {
        
        if(cnt==num) {
            System.out.println();
            if(answer<sum) answer=sum;
            return ;
        }
        
        for(int i=0;i<total;i++) {
            if(visit[i]) continue;
            
            if(i==0) visit[total-1]=true;
            else visit[i-1]=true;
            visit[i]=true;
            if(i+1>=total) visit[0]=true;
            else visit[i+1]=true;
            sum+=s[i];
            
            dfs(sum, cnt+1);
            
            if(i==0) visit[total-1]=false;
            else visit[i-1]=false;
            visit[i]=false;
            if(i+1>=total) visit[0]=false;
            else visit[i+1]=false;
            sum-=s[i];
        }
        
    }
    
    public int solution(int sticker[]) {
        total=sticker.length;
        s=sticker.clone();
        
        if(sticker.length==1) num=1;
        else num=sticker.length/2;
        
        dfs(0, 0);

        return answer;
    }
}*/
