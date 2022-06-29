/*
    새로 추가된 선의 왼쪽에는 0, 오른쪽에는 1이 추가되는 규칙이 있었다.
    그래서 새로 추가되었음을 뜻하는 boolean을 이용하여
    Pair<선의 종류, 새로추가여부> 를 구현하여, ArrayList에 삽입하는 식으로 구현하였다.
    마지막 테스트 케이스 하나에서 시간초과가 나고 나머지는 모두 통과했다.

    이 문제는 처음 0을 기준으로 떨어진 길이가 같은 요소들이 서로 대칭구조를 이룬다.
    또 선의 총 갯수는 홀 수이다.
    따라서 중앙에 0부터 --해가면서 반대되는 값을 append해주면 된다.

    완전 이진 트리로도 구현할 수 있다고 한다.
*/

class 종이접기 {
    public int[] solution(int n) {
        StringBuilder sb=new StringBuilder("0");

        for(int i=1;i<n;i++) {
            String str=sb.toString();
            
            sb.append(0); // 중앙 0 

            // 중앙 부터 거꾸로 순회하면서 반대값을 append 
            for (int j=str.length()-1;j>=0;j--) {
                if (str.charAt(j)=='1')
                    sb.append(0);
                else
                    sb.append(1);
            }
            
        }

        int[] answer = new int[sb.length()];

        for (int i=0;i<answer.length;i++)
            answer[i]=sb.charAt(i)-'0';

        return answer;
    }
}

/* 마지막 케이스 통과 못한 풀이
import java.util.*;

class Pair {
    Integer key;
    Boolean value;
    
    public Pair(Integer key, Boolean value) {
        this.key = key;
        this.value = value;
    }
    
    public Integer getKey() {
        return key;
    }
    
    public Boolean getValue() {
        return value;
    }
    
    public void setKey(Integer key) {
        this.key = key;
    }
    
    public void setValue(Boolean value) {
        this.value = value;
    }
}

class Solution {
    public int[] solution(int n) {

        List<Pair> list = new ArrayList<>();

        list.add(new Pair(0, false));
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<list.size();j++) {
                if(list.get(j).getValue()==false) {
                    list.get(j).setValue(true);
                    list.add(j, new Pair(0, false));
                    list.add(j+2, new Pair(1, false));
                    j=j+3;
                }
            }
        }
        
        int[] answer = new int[list.size()];
        for(int i=0;i<answer.length;i++) {
            answer[i]=list.get(i).getKey();
        }
        
        return answer;
    }
}
*/
