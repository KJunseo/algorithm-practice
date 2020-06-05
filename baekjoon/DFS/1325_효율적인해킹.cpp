/*
    DFS로 풀었다.
    처음에는 쉽다고 생각했는데 생각보다 여러번 틀렸다..
    dfs에서 방문체크 위치가 문제였다.
    테스트케이스도 잘됐었는데 솔직히 아직도 뭔 차이인지 잘 모르겠다.
*/
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int maxValue, value;
vector<int> computer[10001];
vector<int> answer;
vector<pair<int, int> > result;
int visit[10001];

void dfs(int x) {

    visit[x]=true;

    for(int i=0;i<computer[x].size();i++) {
        int y=computer[x][i];

        if(!visit[y]) {
            value++;
            dfs(y);
        }
    }

    if(maxValue<value) maxValue=value;

}

int main(void) {

    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++) {
        int from, to;
        scanf("%d %d", &to, &from);

        computer[from].push_back(to);
    }

    for(int i=1;i<=N;i++) {
        value=0;
        memset(visit, false, sizeof(visit));
        dfs(i);

        result.push_back(make_pair(value, i));
    }

    for(int i=0;i<result.size();i++) {
        if(result[i].first==maxValue)
            printf("%d ", result[i].second);
    }

    return 0;
}