/*
    시작점에서 bfs로 높이 차이가 height 이하인 곳만 탐색 후,
    사다리를 하나씩 추가하고 다시 bfs를 돌리는 방식으로 생각했었는데, 구현하지 못했다.
    어려웠다.

    mst문제라고 한다.(최소 신장 트리)
    : 노드 간 연결성을 보장하면서 노드 사이를 잇는 거리/비용 등을 최소로 하는 그래프를 의미

    1. 사다리가 없이 이동이 가능한 그룹들 만들기
    2. 서로 다른 그룹 간의 모든 거리 구하기
    3. 정렬 후, 사다리 설치 최소 비용 구하기
*/
import java.util.*;

class 지형이동 {

    // 상, 하, 우, 좌 이동 
    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};
    int[] parent; // 공통 구역을 찾아줄 배열
    int[][] check; // 구역을 나눠줄 배열 
    ArrayList<Node> list; // 서로 다른 구역의 차이를 저장하는 리스트
        
    // 좌표를 나타내는 클래스
    public class Dot {
        int x;
        int y;
        
        public Dot(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }
    
    // 서로 다른 두 구역과, 두 구역의 차이를 저장할 클래스
    public class Node {
        int first;
        int second;
        int diff;
        
        public Node(int first, int second, int diff) {
            this.first = first;
            this.second = second;
            this.diff = diff;
        }
    }
    
    // 공통 구역을 찾기 위한 메서드 
    // (union-found의 부모를 찾는 메서드)
    public int findParent(int value) {
        if(value == parent[value]) return value;
        return parent[value] = findParent(parent[value]);
    }
    
    // 두 구역을 합쳐주는 메서드
    // (union-found의 부모를 합쳐주는 메서드)
    public void union(int first, int second) {
        first = findParent(first);
        second = findParent(second);
        
        if(first<second) parent[second]=first;
        else parent[first]=second;
    }
    
    public int solution(int[][] land, int height) {
        int answer = 0;
        int len = land.length;
        
        check = new int[len][len];
        
        for (int i=0;i<len;i++) 
            Arrays.fill(check[i], -1);
        
        list = new ArrayList<>();
        
        int area = -1;
        
        // 1. 사다리가 없이 이동이 가능한 그룹들 만들기
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {
                
                if(check[i][j]>=0) continue; // 이미 구역이 정해져 있는 경우 skip
                
                area++; 
                
                Queue<Dot> q = new LinkedList<>();
                
                q.add(new Dot(i, j));
                
                check[i][j] = area; // 구역을 정해준다.
                
                while(!q.isEmpty()) {
                    Dot cur = q.poll(); // 현재 좌표 
                    
                    // 상, 하, 좌, 우로 움직인다. 
                    for (int dir=0;dir<4;dir++) {
                        
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        
                        // 배열을 벗어나는 범위면 무시 
                        if(nx<0 || ny<0 || nx==len || ny==len) continue;
                        
                        // 이미 구역이 정해져있다면 무시 
                        if(check[nx][ny]>=0) continue;
                        
                        // 지형의 차이가 height보다 크다면 무시 
                        if(Math.abs(land[nx][ny]-land[cur.x][cur.y])>height) continue;
                        
                        // 같은 구역으로 넣어줌 
                        check[nx][ny] = area;

                        // 탐색을 위해 큐에 넣어줌 
                        q.add(new Dot(nx, ny));
                    }
                }
            }
        }
        
        // 2. 서로 다른 그룹 간의 모든 거리 구하기
        parent = new int[area+1]; // 만들어진 총 구역의 수 만큼 공통 구열 배열 초기화
        
        for(int i=0;i<parent.length;i++) 
            parent[i] = i;
        
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {

                // 상, 하, 좌, 우 탐색 
                for(int dir=0;dir<4;dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    
                    // 범위를 벗어나면 무시 
                    if(nx<0 || ny<0 || nx==len || ny==len) continue;

                    // 같은 구역이면 무시 
                    if(check[i][j]==check[nx][ny]) continue;

                    // 다른 구역일 경우 두 구역과 두 구역의 차이를 list에 저장 
                    list.add(new Node(check[i][j], check[nx][ny], Math.abs(land[i][j]-land[nx][ny])));
                }
            }
        }
        
        // 3. 정렬 후, 사다리 설치 최소 비용 구하기
        // 구역 차이, 현재구역, 다음구역 순으로 정렬 
        Collections.sort(list, new Comparator<Node>() {
            
            @Override
            public int compare(Node n1, Node n2) {
                
                if(n1.diff<n2.diff) {
                    return -1;
                }else if (n1.diff==n2.diff) {
                    if (n1.first<n2.first) return -1;
                    else return 1;
                } else {
                    return 1;
                }
            }
        });
            
                             
        int cnt = 0; // 공통 구역을 찾을 때마다 갯수를 늘려줌 
                            
        // 구역 차이가 최소인 경우부터 공통구역 탐색 
        for(Node n : list) {
            
            // 현재 구역과 다음 구역이 같지 않다면 
            if(findParent(n.first)!=findParent(n.second)) {
                
                union(n.first, n.second); // 두 구역을 합쳐준다.
                
                answer+=n.diff; // 그때 발생하는 비용을 더해준다.
                
                if(++cnt==area) break; // 공통 구역의 갯수가 전체구역-1 일때 종료
            }
        }                      
        
        return answer;
    }
}
