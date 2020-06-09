/*
    DFS로 시도했다.
    조합을 사용하는 것 같아서, N개를 뽑는 경우부터 1개를 뽑는 경우까지 진행하면서
    인덱스와 값이 일치하면 종료시키게 하였는데 테스트케이스는 통과하였으나 시간초과가 나버렸다.

    사이클을 이용하여 dfs를 진행하여야 한다고 한다.
    사이클이 존재하면 인덱스 집합과 값의 집합이 동일하다.

    9466번 텀 프로젝트와 거의 동일하다.
*/
#include <iostream>

using namespace std;

int N, cnt;
int arr[101];
int visit[101]; // 방문 체크(0: 방문 하지 않음 / 1: 방문 중 / -1: 방문 끝남)
bool isCycle[101]; // 사이클 여부 체크

void dfs(int x) {

    if(isCycle[x] || visit[x]==-1) return; // 이미 사이클에 포함되어 있거나, 방문이 끝나 더 이상 방문할 필요가 없는 경우 

    if(!visit[x]) visit[x]=1; // 방문하지 않은 곳이면 방문 
    else if(visit[x]==1) { // 이미 방문 중인데, 또 방문하게 되면 사이클이 발생한 경우 
        isCycle[x]=true;
        cnt++;
    }

    dfs(arr[x]); // 연결된 곳에서 다시 dfs 

    visit[x]=-1; // 방문이 끝남을 표시
}

int main(void) {

    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=N;i++) {
        if(!visit[i]) dfs(i); // 이미 방문한 곳은 dfs 수행하지 않는다.
    }

    cout << cnt << "\n";

    for(int i=1;i<=N;i++) {
        if(isCycle[i]) cout << i << "\n";
    }

    return 0;
}


// 조합을 사용하여 풀어보려 하였으나 시간초과 난 코드
// #include <algorithm>
// #include <vector>

// int N;
// bool flag;
// int arr[101];
// int visit[101];
// vector<int> ans;

// void check() {
//     vector<int> idx;
//     vector<int> value;

//     for(int i=1;i<=N;i++) {
//         if(visit[i]) {
//             idx.push_back(i);
//             value.push_back(arr[i]);
//         }
//     }

//     sort(idx.begin(), idx.end());
//     sort(value.begin(), value.end());

//     if(idx==value) {
//         if(ans.size()<idx.size()) {
//             ans=idx;
//             flag=true;
//         }
//     } 
// }

// void dfs(int idx, int cnt, int num) {

//     if(cnt==num) {
//         check();
//         return;
//     }

//     for(int i=idx;i<=N;i++) {
//         if(!visit[i]) {
//             visit[i]=true;
//             dfs(i, cnt+1, num);
//             visit[i]=false;
//         }
//     }
// }

// int main(void) {

//     cin >> N;

//     for(int i=1;i<=N;i++) {
//         cin >> arr[i];
//     }

//     for(int i=N;i>=1;i--) {
//         dfs(1, 0, i);
//         if(flag) break;
//     }

//     cout << ans.size() << "\n";
//     for(int i=0;i<ans.size();i++) {
//         cout << ans[i] << "\n";
//     }
//     return 0;
// }