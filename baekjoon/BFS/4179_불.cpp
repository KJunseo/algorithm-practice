/*
    BFS를 사용하여
    지훈이가 움직일 수 있는 거리와, 불이 퍼질 수 있는 거리를 각각 계산하여
    탈출구를 기준으로 
    1. 지훈이가 탈출구에 도달할 수 있다면(j_visit!=0)
    1-1. 불이 퍼질 수 있다면 지훈이가 가는데 걸린 거리보다 더 늦게 도착한다면 최솟값으로 업데이트
    1-2. 불이 퍼질 수 없다면 지훈이가 가는 거리의 최솟값으로 업데이트

    이런식으로 풀이하려하였으나 실패했다.
    
    풀이를 참고해도 비슷한 방식으로 푼 거 같은데 구현이 어디서 잘못된 거 같다..

    불을 먼저 bfs시키고 지훈이를 bfs 시킬 때 불과 비교해가면서 시켜야한다고 한다.
*/
#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int R, C;
char map[MAX][MAX];
int f_visit[MAX][MAX]; // 불 bfs 기록
int j_visit[MAX][MAX]; // 지훈이 bfs 기록 

queue<pair<int, int> > fq; // 불 큐
queue<pair<int, int> > jq; // 지훈이 큐 

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// 불 bfs 
void bfs_fire(){
    while(!fq.empty()){
        int y = fq.front().first;
        int x = fq.front().second;
        fq.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0 || ny>=R || nx<0 || nx>=C) continue; // 범위를 벗어나면 스킵 
            
            // 벽이 아니고, 아직 불이 방문하지 않았다면 
            if(map[ny][nx]!='#' && !f_visit[ny][nx]){
                fq.push(make_pair(ny, nx));
                f_visit[ny][nx]=f_visit[y][x]+1;
            }
        }
    }
}

// 지훈이 bfs 
void bfs_jh(){    
    while(!jq.empty()){
        int y = jq.front().first;
        int x = jq.front().second;
        jq.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위를 벗어나는 순간 탈출 한 것 
            if(ny<0 || ny>=R || nx<0 || nx>=C){
                cout << j_visit[y][x] << "\n";
                return;
            }
            
            // 이동할 수 있는 곳이고 지훈이가 아직 방문하지 않았다면 
            if(map[ny][nx]=='.' && !j_visit[ny][nx]){
                // 불보다 지훈이가 먼저 그 곳을 갈 수 있거나 아에 불이 없는 경우
                if(f_visit[ny][nx]>j_visit[y][x]+1 || !f_visit[ny][nx]){
                    jq.push(make_pair(ny, nx));
                    j_visit[ny][nx]=j_visit[y][x]+1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}

int main(void) {
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
            
            // 지훈이 좌표를 큐에 담음 
            if(map[i][j]=='J') {
                jq.push(make_pair(i, j));
                j_visit[i][j]=true;
            } 
            // 불의 모든 좌표를 큐에 담음 
            if(map[i][j]=='F') {
                fq.push(make_pair(i, j));
                f_visit[i][j]=true;
            }

        }
    }
    
    bfs_fire(); // 불 bfs
    bfs_jh(); // 지훈이 bfs 
    
    return 0;
}