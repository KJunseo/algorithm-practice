/*
    BFS로 풀었다.
    처음에 cin을 사용했다가 시간초과가 나버려 모두 scanf로 바꿔주니까 통과할 수 있었다.
    사건 발생 순서를 양방향이 아닌 단방향으로 연결하고, 입력받은 s를 올바른 순서, 반대 순서로 bfs를 돌려주면 된다.
    다른 풀이를 보니 대부분 이 문제를 플로이드 와샬로 풀었다.
    밑에 플로이드 와샬 풀이를 추가하였다.
    플로이드 와샬이 시간이 훨씬 적게 걸리긴 하였다.
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, k, s;
vector<int> all[401];
int visit[401];

bool bfs(int case1, int case2) {

    memset(visit, 0, sizeof(visit));

    queue<int> q;
    q.push(case1);
    visit[case1]=true;

    while(!q.empty()) {
        int cur=q.front();
        q.pop();

        if(cur==case2) {
            return true;
        }

        for(int i=0;i<all[cur].size();i++) {
            int y=all[cur][i];

            if(visit[y]) continue;

            visit[y]=visit[cur]+1;
            q.push(y);
        }
    }
    return false;
}

int main(void) {

    scanf("%d %d", &n, &k);

    for(int i=0;i<k;i++) {
        int before, after;
        scanf("%d %d", &before, &after);
        
        all[before].push_back(after);
    }

    scanf("%d", &s);

    for(int i=0;i<s;i++) {
        int case1, case2;
        scanf("%d %d", &case1, &case2);

        if(bfs(case1, case2)) {
            printf("%d\n", -1);
        } else if(bfs(case2, case1)) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", 0);
        }
    }

    return 0;
}


// 플로이드 와샬
#include <stdio.h>
#include <vector>
#define MAX 401

using namespace std;

int n, k, s;
int map[401][401];

void floyd() {
    for(int k=1;k<=n;k++) { // 중간점
        for(int i=1;i<=n;i++) { // 시작점 
            for(int j=1;j<=n;j++) { // 끝점
                if(i==j || i==k || j==k) continue;

                if(map[i][j]==0) {
                    if(map[i][k]==1 && map[k][j]==1) map[i][j]=1;
                    else if(map[i][k]==-1 && map[k][j]==-1) map[i][j]=-1;
                }
            }
        }
    }
}

int main(void) {

    scanf("%d %d", &n, &k);

    for(int i=0;i<k;i++) {
        int before, after;
        scanf("%d %d", &before, &after);

        map[before][after]=-1; // before가 after보다 빠르다는 뜻
        map[after][before]=1; //after가 before보다 느리다는 뜻
    }

    floyd();

    scanf("%d", &s);

    for(int i=0;i<s;i++) {
        int case1, case2;
        scanf("%d %d", &case1, &case2);

        printf("%d\n", map[case1][case2]);
    }
}