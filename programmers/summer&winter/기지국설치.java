/*
    기지국이 이미 세워진 곳을 기준으로 현재 기지국에 의해 덮혀지지 않은 부분을 갯수를 세어
    빈 곳의 갯수로 해결하려 하였다.

    첫 번째 기지국이 커버할 수 있는 범위 전 까지 빈 곳의 수를 세고 빈 곳의 수에 따라 기지국을 추가한다고 생각하였다.
*/
class 기지국설치 {
    public int solution(int n, int[] stations, int w) {
        int answer=0;
        int idx=0; 
        int cover=w*2+1; // 기지국이 커버 할 수 있는 범위
        
        if(stations.length==n) return 0;
        
        for(int i=0;i<stations.length;i++) {
            int temp = stations[i];

            int cnt = temp-w-1-idx; // 빈 공간 갯수(이전 기지국의 끝 부터 현재 기지국이 커버할 수 있는 첫 부분 전 까지)

            // 빈 공간이 1 이상이면 
            if(cnt>0) {
                answer+=cnt/cover;
                if(cnt%cover>0) answer++;
            }

            idx=temp+w;
        }
        
        // 마지막 기지국 이후에도 빈 공간이 있을 수 있기 때문에 체크 
        if(idx<n) {
            int cnt=n-idx;
            
            answer+=cnt/cover;
            if(cnt%cover>0) answer++;
        }

        return answer;
    }
}
