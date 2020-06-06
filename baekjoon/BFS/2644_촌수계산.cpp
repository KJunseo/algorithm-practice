/*
    BFS로 풀었다.
    가족 관계를 양방향으로 연결하고, bfs를 돌리면 답이 나온다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from, to;
vector<int> v[100];
int visit[100];

void bfs() {
    queue<int> q;
    q.push(from);

    while(!q.empty()) {
        int x=q.front();
        q.pop();

        if(x==to) {
            cout << visit[x] << endl;
            return;
        }

        for(int i=0;i<v[x].size();i++) {
            int y=v[x][i];

            if(visit[y]) continue;

            visit[y]=visit[x]+1;
            q.push(y);
        }
    }
    cout << -1 << endl;
}

int main(void) {

    cin >> n;

    cin >> from >> to;

    cin >> m;

    for(int i=0;i<m;i++) {
        int p1, p2;
        cin >> p1 >> p2;

        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }

    bfs();

    return 0;
}