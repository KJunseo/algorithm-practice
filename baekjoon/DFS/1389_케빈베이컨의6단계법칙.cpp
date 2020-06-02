/*
    DFS로 풀어보려고 하였으나 실패하였다.
    DFS/BFS 나 플로이드 와샬 알고리즘으로 풀 수 있다.

    플로이드 와샬로 풀 때는 바로 가는 경우가 없으면 거쳐서 가게 하고,
    바로 가는 경우가 있거나, 이미 탐색된 경로가 있으면, 최솟값으로 업데이트한다.

    dfs풀이를 밑에 첨부하였다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int relation[101][101];

void floyd() {
    // k: 거쳐가는 노드
    for(int k=1;k<=N;k++) {
        // i: 출발 노드
        for(int i=1;i<=N;i++) {
            // j: 도착 노드
            for(int j=1;j<=N;j++) {
                if(i==j) continue; // 자기 자신으로 가는 경로는 무시 
                else if(relation[i][k]&&relation[k][j]) {

                    // 바로가는 경우가 없으면 
                    if(relation[i][j]==0) 
                        relation[i][j]=relation[i][k]+relation[k][j];
                    // 바로 가는 경우가 있거나 이미 탐색된 경로가 있으면, 최솟값으로 업데이트
                    else 
                        relation[i][j]=min(relation[i][j], relation[i][k]+relation[k][j]);
                }
            }
        }
    }
}

int main(void) {

    cin >> N >> M;

    for(int i=0;i<M;i++) {
        int person1, person2;

        cin >> person1 >> person2;

        relation[person1][person2]=relation[person2][person1]=1;
    }

    floyd();

    int result=100;
    int person;
    for(int i=1;i<=N;i++) {
        int sum=0;
        for(int j=1;j<=N;j++) {
            sum+=relation[i][j];
        }
        
        if(result>sum) {
            result=sum;
            person=i;
        }
    }

    cout << person << endl;

    return 0;
}

// dfs
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int N, M, person, ans=101;
int cnt[101];
vector<vector<int> > relation(101);
 
void dfs(int num, int d) {

    if(cnt[num]!=0) {
        cnt[num]=min(d, cnt[num]);
    } else {
        cnt[num]=d;
    }
 
    for(int j=0;j<relation[num].size();j++) {
        int next=relation[num][j];

        if(cnt[next]==0 || cnt[next]>d+1) {
            dfs(next, d+1);
        }
    }
}
 
int main() {

    cin >> N >> M;

    for(int i=0;i<M;i++) {
        int person1, person2;

        cin >> person1 >> person2;

        relation[person1].push_back(person2);
        relation[person2].push_back(person1);
    }
 
    // 1번 노드부터 탐색 
    for(int i=1;i<=N;i++) {
        
        memset(cnt, 0, sizeof(cnt));

        // 각 노드들로 가는 최소 카운트 계산
        for(int j=0;j<relation[i].size();j++) {
            dfs(relation[i][j], 1);
        }
 
        int sum=0;
        for(int j=1;j<=N;j++) {
            if(j==i) continue;
            
            sum+=cnt[j];
        }
      
        if(ans>sum) {
            ans=sum;
            person=i;
        }
    }
 
    cout << person << endl;

    return 0;
}