/*
    치킨집과 일반집의 좌표를 기억하고, 
    치킨집의 치킨거리를 구한 후, m개 만큼만 남기고,
    남은 치킨집들과 일반집의 치킨거리를 계산하여, 각 일반집을 기준으로 최소 치킨거리를 기억한 후
    모두 더하는 식으로 구현하였다. TC가 모두 통과해서 맞았다고 생각했는데 틀렸다.
    반례를 찾지는 못했다..

    풀이는 아래와 같다.
    치킨집과 일반집의 좌표를 기억하고, 
    dfs를 사용하여 치킨집을 모두 돌면서 선택하거나, 선택하지 않거나이다.
    M개를 골랐다면 치킨거리를 구해 업데이트 해준다.

    구현방법은 비슷하게 갔었는데 dfs를 쓰는 것을 몰랐다. 흠..
*/
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 50
#define INF 100000000

using namespace std;

int n, m;
int result = INF;
int city[MAX][MAX];
vector <pair <int,int> > chicken, home;
bool visited[13]; // 최대 치킨집이 13개이기 때문에 

// idx: 현재 치킨 집의 수
// select: 이때까지 선택된 치킨 집의 수
void dfs(int idx, int select) { 
    if(select==m) {
        int temp=0;

        for(int i=0;i<home.size();i++) {
            int distance=INF;
            for(int j=0;j<chicken.size();j++) {
                if(visited[j]) distance=min(distance, abs(chicken[j].first-home[i].first)+abs(chicken[j].second-home[i].second));
            }
            temp+=distance;
        }
        result=min(result, temp);
        return;
    }
    if(idx==chicken.size()) return;

    visited[idx]=true;
    dfs(idx+1, select+1);
    visited[idx]=false;
    dfs(idx+1, select);
}

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &city[i][j]);

            if(city[i][j]==1) home.push_back(make_pair(i,j));
            else if(city[i][j]==2) chicken.push_back(make_pair(i,j));
        }
    }

    dfs(0,0);

    printf("%d\n", result);

    return 0;
}