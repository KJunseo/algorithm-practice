/*
    오름차순 sorting 후, 첫 번째 작업을 먼저 수행하고,
    모든 요청이 종료될 때까지 반복하면서, 짧은 수행시간 순으로 진행하였으나, 실패하였다.. 
    아직 구현 능력이 많이 부족한 것 같다...

    들어온 시간 순으로 sorting 하고,
    작업 소요 시간 기준으로 min heap을 만들고,
    큐가 차 있거나, 남은 작업이 있을 시 반복문을 돌리면서,
    현재 시간을 기준으로, 현재 시간보다 작업 요청 시점이 작은 요소들을 모두 큐에 넣고,
    큐가 비어있지 않으면, 작업 소요 시간이 작은 순으로 작업을 수행한다.
*/
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, index = 0, time = 0;
    int num=jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, compare> pq; // 작업 소요시간 기준으로 min heap 
    
    sort(jobs.begin(), jobs.end());

    // 작업할 요소가 남아 있거나, 큐가 비어있지 않다면 
    while (index<num || !pq.empty()) {

        // 작업할 요소가 남아 있고, 작업할 요소가 현재 시간보다 작거나 같다면 
        if (index<num && time>=jobs[index][0]) {
            pq.push(jobs[index++]); // 우선순위 큐에 추가 
            continue; // 현재 시간보다 요청 시점이 작은 작업을 모두 넣기 위함 
        }
    
        // 큐가 비어있지 않다면
        if (!pq.empty()) {
            time+=pq.top()[1]; // 작업 소요시간이 가장 작은 요소를 완료했다고 생각하고, 현재 시간 업데이트
            answer+=time-pq.top()[0]; // 작업을 하나 완료했으므로 현재시간에서 해당 작업의 요청 시점을 뺀 값을 answer에 더해준다.
            pq.pop(); // 작업 완료했으니 큐에서 제거
        } else time = jobs[index][0]; // 큐가 비어 있는 경우, 다음 작업의 요청 시점을 현재 시간으로
    }
    
    return answer/num;
}