/*
    dfs를 사용하려고 했다.
    순간이동은 비용이 안들기 때문에 목적지의 반까지만 가는 방법의 최소를 구하면 된다.
    그 후 홀 수이면 한칸을 앞으로 더 가야하므로 +1을 해준다
    마지막 예제에서 시간초과가 났다.

    그래서 dp로 시도해보았다.
    dp[0]=0 / dp[1]=1(무조건 한 칸 앞으로 가야하기 때문)

    그 후는 홀수인 경우는 앞으로 한 칸
          짝수인 경우는 앞으로 한 칸 or 순간이동 중 최소로
    
    갈 수 있는 최솟값을 저장해가면서 진행했다.(n/2) 까지 
    정확성은 모두 통과하였지만, 효율성에서 시간초과가 나버렸다..
    
    효율성 부분은 풀이를 참고했다.
    0부터 생각하지 않고, n부터 생각하여 과정을 거꾸로 진행한다.
    n이 짝수면 2로 나누고, 홀 수면 1씩 빼준다
    이 과정을 0이 될때까지 진행한다. 
    이걸 거꾸로 시행해보면 순간이동을 최대로 사용가능한 경우의 수가 나온다.(최솟값)

    또 3줄짜리 코드가 있었다.. 그것도 밑에 첨부하였다.
*/

// dp(정확성만 통과)
public class 점프와순간이동 {
    
    public int solution(int n) {
        int ans=n;
        int half=n/2; 
        int[] dp = new int[half+1];
        
        if(n==1) return 1;
        
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=half;i++) {
            int forward=dp[i-1]+1;
            
            if(i%2==1) {
                dp[i]=forward;
            } else {
                dp[i]=Math.min(dp[i/2], forward);
            }
        }
        
        ans=dp[half];

        if(n%2==1) ans++;
        
        return ans;
    }
}

// 효율성까지
class 점프와순간이동2 {
    public int solution(int n) {
        int ans = 0;

        // n부터 시작하여
        while(n!=0) {
            if(n%2==0) { // 짝수인 경우 2로 나눠준다.(순간이동)
                n/=2;
            } else { // 홀수인 경우 1을 빼준다(앞으로 한 칸 전진)
                n--;
                ans++; // 배터리 소모량 
            }
        }

        return ans;
    }
}

// 3줄짜리..
// 이진수로 바꾼 것의 1의 갯수 
// 10진수를 2진수로 바꾸는 과정이 나누기 2를 계속하는 것이기 때문에
// 나머지가 남는 구간(1)은 앞으로 전진한다고 생각
// 나머지가 없는 구간(0)은 순간이동한다고 생각하면 된다 
class 점프와순간이동3 {
    public int solution(int n) {
        return Integer.bitCount(n); 
    }
}
