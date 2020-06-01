/*
    BFS로 풀었다.
    나이트인 경우 움직이는 경우의 수가 8개라서 그걸 미리 정의해두고 움직이게 하였고
    목표에 도달하면 벡터에 정답을 넣고 종료시켰다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L;
bool visit[300][300];
int cur[2];
int goal[2];
vector<int> answer;

struct Move {
    int y;
    int x;
};

Move knight[8] = {
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, 2},
    {-2, 1},
    {-1, -2},
    {-2, -1}
};

void bfs(int y, int x) {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(y, x), 0));
    visit[y][x]=true;

    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if(cur.first==goal[0] && cur.second==goal[1]) {
            answer.push_back(d);
            break;
        }

        for(int i=0;i<8;i++) {
            int ny=cur.first+knight[i].y;
            int nx=cur.second+knight[i].x;

            if(ny<0 || nx<0 || ny>=L || nx>=L) continue;

            if(visit[ny][nx]) continue;

            q.push(make_pair(make_pair(ny, nx), d+1));
            visit[ny][nx]=true;
        }
    }


}

int main(void) {

    int testNum;

    cin >> testNum;

    for(int k=0;k<testNum;k++) {
        cin >> L;

        for(int i=0;i<L;i++) {
            for(int j=0;j<L;j++) {
                visit[i][j]=false;
            }
        }

        cin >> cur[0] >> cur[1];
        cin >> goal[0] >> goal[1];

        bfs(cur[0], cur[1]);
    }

    for(int i=0;i<answer.size();i++) {
        cout << answer[i] <<endl;
    }

    return 0;
}