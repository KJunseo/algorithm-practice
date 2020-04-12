/*
    먼저 들어온 트럭이 먼저 나가기 때문에 큐를 사용했다.
    현재 다리의 무게에 다음 트럭의 무게를 더한 값이 지탱 가능한 무게 보다 작고, 
    다리에 올라가 있는 트럭 수가 다리 길이 보다 작을 때만,
    다리에 트럭을 올려서 진행하려 하였으나, 
    남은 거리를 계산하는 로직을 구현하는 것을 실패했다..
    

    풀이는 아래와 같다.
    한 반복문 당(1초의 흐름을 뜻함)
    다리에 올라와 있는 모든 트럭의 남아 있는 거리를 1씩 감소시킨다. 도착 시는 해당 트럭을 다리에서 빼준다.

    남아 있는 트럭이 있고, 다리가 트럭 무게를 지탱할 수 있는 경우 트럭을 다리에 새로 올린다.
    이때, 다리에 트럭의 무게도 더해주고, 그 트럭이 가야하는 거리도 업데이트해준다.
    (각 트럭마다 건너야하는 길이는 모두 같으므로 bridge_length로 업데이트 해준다.)

    대기 상태인 트럭과, 다리 위의 트럭이 모두 없는 경우 종료한다.  
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total=0; // 현재 다리에 올라가 있는 트럭의 총 무게 
    queue<int> remain; // 각 트럭 당 남아있는(가야하는) 다리 길이
    queue<int> bridge; // 현재 다리 위에 있는 트럭 
    queue<int> truck;
    
    for(int i=0;i<truck_weights.size();i++) {
        truck.push(truck_weights[i]);
    }
    
    while(true) {
        int num=bridge.size(); // 현재 다리 위에 있는 트럭의 수 
        
        for(int i=0;i<num;i++) {
            int distance=remain.front(); // 트럭이 가야하는 거리
            remain.pop();
            
            // 도착했다면 
            if(distance<=1) {
                total-=bridge.front(); // 다리 위의 총 무게에서 트럭 무게 빼주기 
                bridge.pop(); // 다리에서 트럭 빼주기 
                continue;
            }
            
            remain.push(distance-1); // 도착하지 않았다면 길이를 1만큼 빼줌 
        }
        
        // 남아있는 트럭이 있고, 다리 위에 트럭을 올렸을 때 무게를 지탱할 수 있는 경우 
        if(!truck.empty() && total+truck.front()<=weight) {
            bridge.push(truck.front()); // 다리에 트럭을 올림 
            total+=truck.front(); // 다리 위의 트럭 총 무게를 트럭 무게 만큼 증가
            remain.push(bridge_length); // 다리에 올린 트럭의 남은 길이를 더해줌 
            truck.pop(); 
        }
        
        answer++; // 1초 흐름 
        
        // 남은 트럭이 없고, 다리 위에도 트럭이 없는 경우 종료 
        if(truck.empty() && bridge.empty()) {
            break;
        }
    }
    
    return answer;
}