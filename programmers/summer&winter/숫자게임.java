/*
    이분 매칭으로 풀어야한다고 생각했다.
    A나 B나 크기가 같으므로, 두 배열을 내림차순 정렬 후,
    B가 A보다 큰 경우 경로 표시를 해주었다.
    그 후, dfs로 경로 표시 된 배열을 통해
    이분매칭을 진행한다.

    정확성은 모두 통과했는데, 효율성에서 모두 시간 초과가 났다.

    풀이를 확인해보니 이분매칭을 사용한 것이아니고, 엄청 간단했다..
    너무 어렵게 생각했나 싶다.

    c++로만 알고리즘 연습을 하다가 자바로 하려니까 벡터나 이런 것들 사용방법이 조금 달라서 헷갈린다..
*/
import java.util.*;

class Solution {
    
    public int solution(int[] A, int[] B) {
        int answer = 0;
        int size = A.length;
        
        // 내림차순 정렬
        Integer [] newA = Arrays.stream(A).boxed().toArray(Integer[]::new);
        Integer [] newB = Arrays.stream(B).boxed().toArray(Integer[]::new);
        
        Arrays.sort(newA, Collections.reverseOrder());
        Arrays.sort(newB, Collections.reverseOrder());

        // B가 A보다 큰 경우, 값 증가 후, B의 인덱스 증가
        // 반대 경우 A의 인덱스만 증가
        for(int i=0, j=0;i<size;i++) {
            if(newB[j]>newA[i]) {
                answer++;
                j++;
            }
        }
        
        return answer;
    }
}


// 이분 매칭(효율성 통과 못함)
class Solution2 {
    int size=0;
    ArrayList<Integer> mapping[];
    boolean[] check;
    int[] d;
    
    // 매칭 가능 여부 확인 
    boolean dfs(int x) {
        for(int i=0;i<mapping[x].size();i++) {
            int temp = mapping[x].get(i); // 현재 노드와 연결된 모든 노드 차례로 
      
            if(check[temp]) continue; // 이미 처리한 노드는 무시 
            check[temp] = true;
            
            // 비어있거나, 비어있지 않아도 다른 곳에 들어갈 수 있다면 
            // 해당 노드와 매칭 
            if(d[temp]==0 || dfs(d[temp])) {
                d[temp] = x;
                return true;
            }
        }
        
        return false;
    }
    
    public int solution(int[] A, int[] B) {
        int answer = 0;
        size = A.length;
        mapping = new ArrayList[size];
        check = new boolean[size];
        d = new int[size];
        
        Integer [] newA = Arrays.stream(A).boxed().toArray(Integer[]::new);
        Integer [] newB = Arrays.stream(B).boxed().toArray(Integer[]::new);
        
        Arrays.sort(newA, Collections.reverseOrder());
        Arrays.sort(newB, Collections.reverseOrder());
        
        // 가능한 경우 모두 더해줌
        for(int i=0;i<size;i++) {
            mapping[i] = new ArrayList<Integer>();
            for(int j=0;j<size;j++) {
                if(newB[i]>newA[j]) {
                    mapping[i].add(j);
                }
            }
        }
        
        // 매칭 할 때 마다, 방문 확인 초기화 
        for(int i=0;i<size;i++) {
            Arrays.fill(check, false); 
            if(dfs(i)) {
                answer++;
            }
        }
        
        return answer;
    }
}