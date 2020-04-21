/*
    차량 진입 지점 중 가장 작은 시점부터, 가장 큰 시점까지 반복문을 통해 탐색하면서,
    각 지점에서 겹치는 차들을 확인하고, 모두 탐색되면 종료시키려고 하였다.
    answer을 어디서 ++ 시키는지가 헷갈렸다.

    먼저 진출 시점을 기준으로 정렬한다.
    그 후, 가장 앞의 차량 진출 시점에 카메라를 설치한다.
    현재 카메라 위치보다 진입 시점이 앞에있는 차량들은 이미 해당 카메라로 감시가 가능하다.
    따라서, 차량의 진입 시점이 현재 카메라보다 뒤에 올 경우만 answer을 ++하고, 
    카메라의 위치를 해당 차량은 진출시점으로 바꿔준다.

    참 생각해내는 게 어렵다..
*/
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1]<b[1]) return true;
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer=1;
    
    sort(routes.begin(), routes.end(), compare); // 진출 기점을 기준으로 정렬 
    
    int camera=routes[0][1]; // 첫 카메라 위치
    
    for(int i=1;i<routes.size();i++) {

        // 현재 카메라 보다, 뒤의 시점에서 진입시
        if(routes[i][0]>camera) { 
            camera=routes[i][1]; // 해당 차량의 진출시점에 카메라 설치
            answer++;
        }
    }
    
    return answer;
}