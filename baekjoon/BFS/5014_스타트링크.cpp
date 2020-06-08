/*
    BFS를 사용하여 풀었다.
    2차 배열에서 상 하 좌 우를 가는 것과 유사하게
    U, -D가 움직이는 경우의 수 이므로 U, -D와 함께 방문체크, 범위 체크를 하면 된다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int building[1000001];
int visit[1000001];
vector<int> go;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visit[x]=true;

    while(!q.empty()) {
        int y=q.front();
        q.pop();

        if(y==G) {
            cout << visit[y]-1 << endl;
            return;
        }

        for(int i=0;i<go.size();i++) {
            int ny=y+go[i];

            if(ny<1 || ny>F) continue;

            if(visit[ny]) continue;

            visit[ny]=visit[y]+1;
            q.push(ny);
        }
    }

    cout << "use the stairs" << endl;
}

int main(void) {

    cin >> F >> S >> G >> U >> D;

    go.push_back(U);
    go.push_back(-D);

    bfs(S);

    return 0;
}