/*
    외벽이 고장난 곳에서, 시계 방향 또는 반 시계 방향으로 가장 멀리 이동할 수 있는 사람 부터 
    최대로 커버할 수 있는 경우를 확인하는 식으로 하려고 했으나 실패했다.

    dist에서 1명을 고르는 방법, 2명을 고르는 방법 ... 최대 8명을 고르는 방법을 모두 고려해준다.
    각 방법마다, 취약지점을 모두 커버할 수 있는 지 체크해준다.

    시작지점부터, 친구를 한 명씩 배정해본다.
    ex. N=12 / weak=[1, 5, 6, 10] 
        1. 1-5-6-10
        2. 5-6-10-13
        3. 6-10-13-17
        ...

    만족하는 최솟값을 구한다.

    <순열>
    접근은 비슷하다. 취약지점 배치를 하나씩 미루면서, 가능한 친구 순열을 모두 돌면서 체크한다. 

    <dfs>
    dist는 정렬되어 있지 않으므로 내림차순으로 정렬하고,
    취약점을 위와같이 바꿔가면서 dfs를 실행한다.
    dfs에서 모든 취약지점이 커버되었거나, 커버 하지 못했는데, 친구를 다써버린 경우 종료한다.

    투입되지 않은 사람일 때, 커버해야하는 곳이 있으면 그 사람이 커버할 수 있는 부분까지 커버한다.
    그 후 투입된 경우 dfs와 투입하지 않은 경우 dfs를 시행한다. 
*/

// dfs
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int isWorked[8]; // 투입 여부 
int isCovered[15]; // 커버 여부 
int answer = 9;
int dfs(int cnt, vector<int> &weak, vector<int> &dist){
    bool end = true; // 모든 취약 지점이 커버 되었는지 확인 
    
    for(int i=0;i<weak.size();i++){
        if(isCovered[i]==0){ // 한 곳이라도 커버 되지 않았다면 false
            end = false;
            break;
        }
    }

    if(end) return answer = min(answer, cnt); // 모든 취약지점이 커버되었으면 최솟값 업데이트
    else if(!end && cnt>dist.size()) return -1; // 최대 친구수를 모두 투입하였어도 취약지점이 남아있으면 return -1
    
    for(int i=0;i<dist.size();i++){
        if(isWorked[i]==0){ // 투입 되지 않은 사람인 경우
            for(int j=0;j<weak.size();j++){
                if(isCovered[j]==0){ // 커버해야 하는 부분이면
                    int t = 0;
                    // 현재 체크하고 있는 취약지점부터 현재 투입한 사람이 cover할 수 있는 취약지점까지를 구해준다
                    while(j+t < weak.size() && weak[j]+dist[i] >= weak[j+t]){
                        isCovered[j+t] = 1; // 커버 완료 
                        t++;
                    }
                    break;
                }
            }

            isWorked[i] = 1; // 투입 완료
            
            dfs(cnt+1, weak, dist);
            
            isWorked[i] = 0; // 투입 x 
            
            memset(isCovered, 0, sizeof(isCovered)); // 취약지점 원상복구 

        }
    }
    return answer;
}


int solution(int n, vector<int> weak, vector<int> dist) {

    sort(dist.rbegin(), dist.rend()); // 내림차순 정렬 
    
    // dfs
    for(int i=0;i<weak.size();i++){ 
        dfs(0, weak, dist); // 현재 투입된 사람 수를 넣어주고 dfs 진행 

        // 맨 앞의 요소를 n을 더해서 맨 뒤로 옮겨줌
        int first = weak[0]+n;
        for(int j=1;j<weak.size();j++){
            weak[j-1] = weak[j];
        }
        
        weak[weak.size()-1] = first; 
    }

    if(answer > 8) answer = -1;
    return answer;
}



// 순열
vector<int> changeStartIdx(vector<int> weak, int start, int n) {
    if(start==0) return weak;

    vector<int> _ret;

    for(int i=start;i<weak.size();i++) {
        _ret.push_back(weak[i]);
    }

    for(int i=0;i<start;i++) {
        _ret.push_back(weak[i]+n);
    }

    return _ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int ret = 9;

    sort(dist.begin(), dist.end()); // 정렬 

    do {
        for(int i=0;i<weak.size();i++) {
            vector<int> _weak = changeStartIdx(weak, i, n); // 취약지점 배치 변경 

            int idx=0; // 친구 수
            int curr=_weak[0]+dist[idx]; // 커버한 범위 
            bool flag=false;

            for(int j=1;j<_weak.size();j++) {
                if(_weak[j]>curr) {
                    if(idx+1 == dist.size()) { // 커버할 수 없는 경우
                        flag=true;
                        break;
                    }
                    curr=_weak[j]+dist[++idx]; // 다음 사람이 커버한 범위 
                }
            }
            if(!flag) ret=min(ret, idx+1); // 업데이트 
        }
    } while(next_permutation(dist.begin(), dist.end())); // 다음 친구 배치

    if(ret==9) return -1;
    return ret;
}