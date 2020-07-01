/*
    자기자신도 연속되는 것이라고 생각할 수 있으므로
    자기 자신부터 시작하여 시작점을 --해주며
    정확히 sum이 n과 동일할 때만 +해준다.
*/
int solution(int n) {
    int answer = 0;
    int sum=0;
    int idx=n;
    
    while(idx>0) {
        sum=0;
        
        for(int i=idx;i>=1;i--) {
            sum+=i;
            
            if(sum==n) {
                answer++;
                break;
            } else if(sum>n) {
                break;
            }
        }
        
        idx--;
    }
    
    return answer;
}