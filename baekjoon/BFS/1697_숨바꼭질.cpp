/*
    BFS로 풀었다.
    갈 수 있는 경우의 수를 조건이 만족하는 경우 큐에 추가해주고
    동생 위치에 도착 시 종료시켰다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visit[100001];
void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0));
    visit[N]=true;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        if(cur.first==K) {
            printf("%d\n", cur.second);
            return;
        }

        if(cur.first+1<=100000 && !visit[cur.first+1]) {
            q.push(make_pair(cur.first+1, cur.second+1));
            visit[cur.first+1]=true;
        }

        if(cur.first-1>=0 && !visit[cur.first-1]) {
            q.push(make_pair(cur.first-1, cur.second+1));
            visit[cur.first-1]=true;
        }

        if(2*cur.first<=100000 && !visit[2*cur.first]) {
            q.push(make_pair(2*cur.first, cur.second+1));
            visit[2*cur.first]=true;
        }

    }

}

int main(void) {

    cin >> N >> K;

    bfs();

    return 0;
}