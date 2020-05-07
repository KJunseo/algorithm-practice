/*
    복잡한 구현 문제였다.
    먼저 기둥인지 보인지 확인하고, 기둥일 때 추가, 삭제. 보 일때 추가, 삭제를 구현해주려고 했다.
    기둥과 보 각각 시작점과 끝점을 저장하는 벡터를 만들고, 삽입 가능한 경우 벡터에 넣어주었다.
    하지만, 삭제하는 부분을 어떻게 구현할 지 감이 안왔다. 삭제할 경우도 모양이 유지되는 지 확인 해야하기 때문이다.

    기둥을 나타내는 배열과, 보를 나타내는 배열을 생성한 후,
    조건을 만족하면 각각 삽입한다.

    삭제 시는, 먼저 삭제했다고 가정하고, 나머지 요소들을 모두 삭제-원상복구 해보면서, 원상복구 할 수 없는 경우가 있으면
    삭제할 수 없는 경우므로 무시한다.
*/
#include <string>
#include <vector>

using namespace std;
 

int N;
int block[101][101][2]; // block[][][0]: 기둥 / block[][][1]: 보

// 삽입 할 수 있는지 확인 
bool isInsert(int x, int y, int type) {
    if(type==0) { // 기둥
        if(y == 0) return true; // 기둥이 바닥에 있으면 삽입 가능 
        else if((x-1>=0 && block[x-1][y][1]==1) || block[x][y][1]==1) return true; // 보의 한쪽 끝에 있는 경우
        else if(y-1>=0 && block[x][y-1][0]==1) return true; // 다른 기둥 위에 있는 경우
        
        return false;
    } else { // 보 
        if((y-1>=0 && block[x][y-1][0]==1) || (x+1<=N && y-1>= 0 && block[x+1][y-1][0]==1)) return true; // 한 쪽 끝이 기둥 위인 경우 
        else if(x-1>=0 && x+1<=N && block[x-1][y][1]==1 && block[x+1][y][1]==1) return true; // 양 끝이 다른 보에 연결된 경우 
        
        return false;   
    }
}
 
// 삭제 가능한지 확인(모든 요소를 다 삭제해보다가 다시 삽입 할 수 없는 경우가 있으면 삭제할 수 없는 경우임)
bool isErase() {   
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            for(int k=0;k<2;k++) {
                if(block[i][j][k]==1) { 
                    block[i][j][k] = 0; // 먼저 지워봄 
                    
                    if(!isInsert(i, j, k)) { // 다시 삽입하려 할 때, 삽입 할 수 없으면 
                        block[i][j][k] = 1; // 원상복구 
                        return false;
                    }
                    
                    block[i][j][k] = 1; // 원상복구 
                }
            }
        }
    }
    
    return true;
}
 
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for(int i=0;i<build_frame.size();i++) {
        int x = build_frame[i][0]; // x좌표
        int y = build_frame[i][1]; // y좌표 
        int type = build_frame[i][2]; // 0: 기둥 / 1: 보
        int act = build_frame[i][3]; // 0: 삽입 / 1: 삭제
        
        if(type==0) { // 기둥 
            if(act==1) { // 삽입 
                if(isInsert(x, y, 0)) {
                    block[x][y][0] = 1;
                }
            } else { // 삭제 
                block[x][y][0] = 0;
                if(!isErase()) {
                    block[x][y][0] = 1;
                }
            }
        } else if(type==1) { // 보
            if(act==1) { // 삽입
                if(isInsert(x, y, 1)) {
                    block[x][y][1] = 1;
                }
            } else { // 삭제 
                block[x][y][1] = 0; // 삭제했다고 가정하고 
                if(!isErase()) { // 남은 요소들을 삭제해봄
                    block[x][y][1] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < 2; k++) {
                if(block[i][j][k] == 1) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    
                    answer.push_back(temp);
                }
            }
        }
    }
    
    return answer;
}



// 삭제 구현 못한 코드

/*#include <algorithm>

vector<vector<pair<int, int> > > p; // 기둥 
vector<vector<pair<int, int> > > b; // 보

bool compare(vector<int> a, vector<int> b) {
    if(a[0]<b[0]) return true;
    else if(a[0]==b[0]) {
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1]) {
            if(a[2]<b[2]) return true;
            else return false;
        } else return false;
    } else return false;
    
    return false;
}

bool checkP(int x, int y) {
    pair<int, int> ps = make_pair(x, y);
    pair<int, int> pe = make_pair(x, y+1);
    bool flag=false;
    
    for(int i=0;i<p.size();i++) {
        pair<int, int> start=make_pair(p[i][0].first, p[i][0].second);
        pair<int, int> end=make_pair(p[i][1].first, p[i][1].second);
        
        if(ps==start && pe==end) {
            return false;
        } else if(ps==end) {
            return true;
        }
    }
    
    for(int i=0;i<b.size();i++) {
        pair<int, int> start=make_pair(b[i][0].first, b[i][0].second);
        pair<int, int> end=make_pair(b[i][1].first, b[i][1].second);
     
        if(start==ps || start==pe || end==ps || end==pe) flag=true;
    }
    
    if(y==0 || flag) {
        return true;
    } 
    
    return false;
}

bool checkB(int x, int y) {
    pair<int, int> ps = make_pair(x, y);
    pair<int, int> pe = make_pair(x+1, y);
    bool flag=false;
    
    for(int i=0;i<b.size();i++) {
        pair<int, int> start1=make_pair(b[i][0].first, b[i][0].second);
        pair<int, int> end1=make_pair(b[i][1].first, b[i][1].second);
        
        for(int j=i+1;j<b.size();j++) {
            pair<int, int> start2=make_pair(b[j][0].first, b[j][0].second);
            pair<int, int> end2=make_pair(b[j][1].first, b[j][1].second);            
            if(end1==ps && start2==pe) return true;
        }
        
        if(ps==start1 && pe==end1) return false;
    }
    
    for(int j=0;j<p.size();j++) {
        pair<int, int> start=make_pair(p[j][0].first, p[j][0].second);
        pair<int, int> end=make_pair(p[j][1].first, p[j][1].second);
        
        if(ps==end || pe==end) return true;
    }
    return false;
    
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    
    for(int i=0;i<build_frame.size();i++) {
        vector<pair<int, int> > temp;
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        
        // 기둥인 경우
        if(build_frame[i][2]==0) {
            if(build_frame[i][3]==0) { // 삭제하는 경우 
                // p.erase();
            } else if(build_frame[i][3]==1) { // 설치하는 경우 
                if(checkP(x, y)) { // 세울 수 있는 경우
                    temp.push_back(make_pair(x, y));
                    temp.push_back(make_pair(x, y+1));
                    p.push_back(temp);
                }
            }
        } else if(build_frame[i][2]==1) { // 보인 경우 
            if(build_frame[i][3]==0) { // 삭제하는 경우
                //b.erase();
            } else if(build_frame[i][3]==1) { // 설치하는 경우 
                if(checkB(x, y)) { // 세울 수 있는 경우
                    temp.push_back(make_pair(x, y));
                    temp.push_back(make_pair(x+1, y));
                    b.push_back(temp);
                }
            } 
        }
    }
    
    for(int i=0;i<p.size();i++) {
        vector<int> temp;
        temp.push_back(p[i][0].first);
        temp.push_back(p[i][0].second);
        temp.push_back(0);
        
        answer.push_back(temp);
    }
    
    for(int i=0;i<b.size();i++) {
        vector<int> temp;
        temp.push_back(b[i][0].first);
        temp.push_back(b[i][0].second);
        temp.push_back(1);
        
        answer.push_back(temp);
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}*/