/*
    +3점
    bfs가 생각나서 바로 적용해서 풀었다. 
    처음에 영역 가장자리가 0인 경우만 걸러줬었는데, 생각해보니 0이 아니라도 값이 다르면 다른 영역이므로 다른 값일 떄도 걸러줬어야했다.
*/
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int M=0, N=0;
bool visit[100][100];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

int bfs(int y, int x, vector<vector<int> > picture) {
    int area=1;
    int value=picture[y][x];
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=M || nx>=N) continue;

            if(visit[ny][nx]) continue;
            
            if(picture[ny][nx]!=value) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
            area++;
        }
    }
    
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M=m;
    N=n;

    int number_of_area=0;
    int max_size_of_one_area=0;
    
    memset(visit, 0, sizeof(visit));
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(visit[i][j]) continue;
            if(picture[i][j]==0) continue;
            int size=bfs(i, j, picture);
            
            if(size>max_size_of_one_area) max_size_of_one_area=size;
            number_of_area++;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}