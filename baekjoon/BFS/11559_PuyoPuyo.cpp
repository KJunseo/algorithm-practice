/*
    BFS로 풀었다.
    풀긴 했는데 좀 지저분하게 푼 것 같다ㅎㅎ..

    1. 게임판 입력 받기
    2. 상하좌우로 4개 이상 붙어 있는 공간 찾기
    3. 4개 이상인 공간들 블럭 삭제
    4. 삭제된 블럭 채우기
    5. 바뀐 게임판에서 삭제 할 수 있는 부분이 있는지 탐색
        yes -> 2번으로 돌아감
        no -> 반복한 횟수 출력
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt;
char field[12][6];
char temp[12][6];
int visit[12][6];
int prevVisit[12][6];
int dy[]={1, -1, 0, 0};
int dx[]={0, 0, -1, 1};

// 상 하 좌 우로 연결된 부분 탐색 
void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x]=true;

    while(!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];

            if(ny<0 || nx<0 || ny>=12 || nx>=6) continue;

            if(field[ny][nx]=='.') continue;

            if(field[ny][nx]!=field[cur.first][cur.second]) continue;

            if(visit[ny][nx]) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx]=true;
        }
    }
}

// 삭제된 블럭 채우기
void afterCycle() {
    vector<char> v;

    for(int j=0;j<6;j++) {
        v.clear();
        for(int i=11;i>=0;i--) {
            if(field[i][j]!='.') {
                v.push_back(field[i][j]);
            }
        }

        while(v.size()<12) {
            v.push_back('.');
        }

        for(int i=0;i<12;i++) {
            char temp=v.back();
            v.pop_back();
            field[i][j]=temp;
        }
    }
}

// 상하좌우 연결된 블럭 갯수 세기 
int getCount() {
    int cnt=0;
    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            if(visit[i][j]==1) cnt++;
        }
    }
    return cnt;
}

int main(void) {

    // 게임판 입력 받기
    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            scanf("%1c", &field[i][j]);
            temp[i][j]=field[i][j];
        }
        getchar();
    }

    // 연쇄 작용 카운트 
    while(true) {

        // 초기화
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                visit[i][j]=0;
                prevVisit[i][j]=0;
                temp[i][j]=field[i][j];
            }
        }    

        // 상하좌우로 4개 이상 붙어 있는 공간 찾기
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(field[i][j]=='.') continue;
                bfs(i, j);

                if(getCount()>=4) {
                    for(int i=0;i<12;i++) {
                        for(int j=0;j<6;j++) {
                            if(visit[i][j]==1) visit[i][j]=2;
                            prevVisit[i][j]=visit[i][j];
                        }
                    }
                } else {
                    for(int i=0;i<12;i++) {
                        for(int j=0;j<6;j++) {
                            visit[i][j]=prevVisit[i][j];
                        }
                    }
                }
            }
        }    
        
        // 4개 이상인 공간들 블럭 삭제
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(visit[i][j]==2) field[i][j]='.';
            }
        }      

        // 삭제된 블럭 채우기
        afterCycle();

        // 더 터질 부분이 있는지 확인 
        bool flag=false;
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(temp[i][j]!=field[i][j]) {
                    flag=true;
                }
            }
        }      
        
        if(!flag) break;
        else {
            for(int i=0;i<12;i++) {
                for(int j=0;j<6;j++) {
                    temp[i][j]=field[i][j];
                }
            }    
        }

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}