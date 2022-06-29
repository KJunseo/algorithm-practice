/*
    그냥 오름차순 정렬해서 계산하면 되는거 아닌가..? 했는데 실제로 그랬다.
    +1점 밖에 얻지 못했다 ㅎ..
*/

import java.util.*;

class 예산 {
    public int solution(int[] d, int budget) {
        int answer = 0;
        
        Arrays.sort(d);
        
        for(int i=0;i<d.length;i++) {
            int current_cost = d[i];
            
            if(budget-current_cost<0) break;
            
            budget-=current_cost;
            answer++;
        }
        
        return answer;
    }
}
