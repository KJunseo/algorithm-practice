/*
    dfs로 구현하려고 했다.
    dfs를 구현하는게 생각보다 잘 안된다. 이 경우는 고른 숫자의 순서가 중요하지 않기 때문에
    그냥 골랐다, 안골랐다만 체크해준다. 

    dfs말고 에라토스테네스의 체나 3중 for문으로도 풀 수 있다.
*/
class Solution {
    
    int answer=0;
    
    // 반복 수, 총 합, 고른 숫자의 갯수, 숫자 배열
    void dfs(int x, int sum, int cnt, int[] nums) {

        // 3개의 수를 고르면 종료 
        if(cnt==3) {
            boolean flag=false;

            // 소수 판별
            for(int i=2;i<=Math.sqrt(sum);i++) {
                if(sum%i==0) {
                    flag=true;
                    break;
                }
            }

            // 소수인 경우 anwer++
            if(!flag) answer++;
            return;
        }
        
        if(x==nums.length-1) return; // 3개를 다 고르지 못하였어도, 모든 배열을 검사한 경우 종료해야함 
        
        dfs(x+1, sum+nums[x+1], cnt+1, nums); // 해당 수를 선택한 경우 
        dfs(x+1, sum, cnt, nums); // 해당 수를 선택하지 않은 경우 
        
    }
    
    public int solution(int[] nums) {

        dfs(0, nums[0], 1, nums); // 첫 번째 수를 더한 경우
        dfs(0, 0, 0, nums); // 첫 번째 수를 더하지 않은 경우 

        return answer;
    }
}