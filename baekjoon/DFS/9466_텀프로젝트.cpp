/*
    DFS를 사용하여 back edge를 이용해야 한다고 한다.
    이런방식은 익숙하지 않아 풀지 못하였다.

    방문 여부를 체크하는 2개의 배열(visit, isCycle)을 두고,
    그래프의 연결관계를 나타내는 student 배열을 둔다.

    visit은 0인 경우 방문 전
            1인 경우 방문 중
            -1인 경우 방문이 끝났고, 더이상 방문할 필요가 없다는 뜻이다.
    
    isCycle은 true이면 사이클을 이루는 노드
              false이면 사이클을 이루지 않는 노드이다.

    학생 2를 처음 방문하면 visit[2]는 1이 된다. 
    이 상태에서 누군가가 또 학생 2를 방문하면 사이클이 존재한다는 의미이다.
    이 경우 isCycle[2]를 true로 바꿔준다.

    재귀가 끝나면, visit을 -1로 바꿔주면 된다.

    참고: https://hugssy.tistory.com/55
*/
#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
int student[100001]; // 연결관계를 나타냄
int visit[100001]; // 방문 상태를 나타냄
bool isCycle[100001]; // 사이클 여부를 나타냄 

void dfs(int x) {
    // 이미 사이클을 형성하고 있거나, 방문이 끝나, 더 이상 방문할 필요가 없는 경우 종료
    if(isCycle[x]==true || visit[x]==-1) return;

    // 방문 전이면 방문 중으로 바꿔줌
    if(visit[x]==0) visit[x]=1;
    // 이미 방문 중인데 또 탐색하게 되면 사이클이 형성되는 것을 뜻한다.
    else if(visit[x]==1) {
        isCycle[x]=true;
        cnt++;
    }

    // 해당 노드와 연결된 곳부터 다시 탐색 
    dfs(student[x]);

    // 탐색이 끝나면 더 이상 방문할 필요가 없다는 걸 나타냄 
    visit[x]=-1;
}

int main(void) {
    int testCase;

    cin >> testCase;

    for(int k=0;k<testCase;k++) {
        cin >> n;

        cnt=0;
        memset(student, 0, sizeof(student));
        memset(visit, 0, sizeof(visit));
        memset(isCycle, false, sizeof(isCycle));

        for(int i=1;i<=n;i++) {
            cin >> student[i];
        }

        for(int i=1;i<=n;i++) {
            if(visit[i]==0) // 방문 전이면 dfs 실행
                dfs(i);
        }

        cout << n-cnt << '\n';
    }


    return 0;
}