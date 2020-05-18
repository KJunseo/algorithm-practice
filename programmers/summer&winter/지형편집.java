/*
    set을 사용하여 검사해야하는 층만 골라냈다.
    그 후, set에 해당하는 층을 기준으로 블럭을 채워보면서 최솟값을 찾게 코드를 짰다.

    그러나 정확성에서 6개, 효율성에서 6개가 틀렸다.

    풀이에서는 parametric search를 사용해서 풀었다.
    parametric search를 처음 들어봤다.
    이진탐색을 응용한 느낌이라고 한다. 원하는 실수의 범위에서 이진탐색을 진행하는 방법이다.
    이진탐색은 Mid의 값이 찾는 값인지가 중요하고, parametric search는 원하는 조건을 만족하는 가장 알맞은 값을 오차 범위 내에서 찾을 때 사용한다. 
    결정 문제인지 아닌지의 차이이며 정답 후보가 연속적으로 나타난다.

    이 문제의 경우는 가장 낮은 층 ~ 가장 높은 층을 기준으로 parametric search를 적용한다.
    중간 층을 찾아 중간과 중간 바로 다음 층을 기준으로 비용 계산을 하고,
    같으면 종료, 첫번째 비용이 크면 start를 mid+1로, 두 번째 비용이 크면 끝을 mid로 업데이트 한다.
    가장 알맞은 층을 구해, 해당 층의 비용을 구하면 된다.
*/

public class 지형편집 {
    
    // 비용 계산 
    long getCost(long mid, int[][] land, int P, int Q) {
        long cost = 0;
        
        for(int i=0;i<land.length;i++) {
            for(int j=0;j<land[i].length;j++) {
                if(land[i][j]>mid) cost+=(land[i][j]-mid)*Q;
                else if(land[i][j]<mid) cost+=(mid-land[i][j])*P;
            }
        }
        
        return cost;
    }
    
    public long solution(int[][] land, int P, int Q) {
        long start = Long.MAX_VALUE;
        long end = 0;
        long mid = 0;
        
        // 가장 낮은 층, 가장 높은 층 구하기 
        for(int i=0;i<land.length;i++) {
            for(int j=0;j<land[i].length;j++) {
                start=Math.min(start, land[i][j]);
                end=Math.max(end, land[i][j]);
            }
        }
            
        // parametric search
        while(start<=end) {
            mid=(start+end)/2; // 중간 층 
            
            if(start==end) break;
            
            long cost1 = getCost(mid, land, P, Q);
            long cost2 = getCost(mid+1, land, P, Q);
            
            if(cost1==cost2) break;
            else if(cost1<cost2) end=mid;
            else start=mid+1;
        }
        
        return getCost(mid, land, P, Q);
    }
}
/*
실패한 풀이 
import java.util.*;

public class 지형편집 {
    public long solution(int[][] land, int P, int Q) {
        long answer = Long.MAX_VALUE;
        Set<Integer> set = new HashSet<>();
        List<Integer> list = new ArrayList<>();
        
        for(int i=0;i<land.length;i++) {
            for(int j=0;j<land[i].length;j++) {
                set.add(land[i][j]);
                list.add(land[i][j]);
            }
        }
        
        Iterator<Integer> it_s = set.iterator();
        
		while (it_s.hasNext()) {
            int temp = it_s.next();
            long ans=0;
            
            for(int i=0;i<list.size();i++) {
                int diff = temp-list.get(i);
                
                if(ans>answer) break;
                
                if(diff>0) {
                    ans+=(diff*P);
                } else if(diff<0) {
                    diff*=-1;
                    ans+=(diff*Q);
                }
            }
            
            if(ans>0 && answer>ans) {
                answer=ans;
            }
		}
        
        return answer;
    }
}*/