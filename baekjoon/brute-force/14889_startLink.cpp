/*
    dfs로 해야하지 않을까? 라는 생각이 들었고, 처음으로 dfs를 혼자 구현하는 것에 성공했다.

    2가지의 경우의 수가 있다고 생각했다.
    1. 해당 멤버가 start팀에 속하는 경우
    2. 해당 멤버가 link팀에 속하는 경우

    모든 멤버가 둘 중 한 팀에 속하게되면, 정확이 반으로 나뉜 경우를 찾아 두 팀 능력치의 차를 구했다.
*/
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 20

using namespace std;

int n;
int minNum=40000;
int status[MAX][MAX];
int sNum;
int lNum;

void dfs(int d, vector <int> start, vector <int> link) {
    if(d==n) {
        sNum=0;
        lNum=0;
        if(start.size()==n/2 && link.size()==n/2) {
            for(int i=0;i<n/2;i++) {
                for(int j=0;j<n/2;j++) {
                    sNum+=status[start[i]][start[j]];
                    lNum+=status[link[i]][link[j]];
                }
            }
            int diff = abs(sNum-lNum);
            minNum=min(minNum, diff);
        } 
        return;
    }
    
    // start 멤버로 뽑는다.
    start.push_back(d);
    dfs(d+1, start, link);
    start.pop_back();

    // link 멤버로 뽑는다.
    link.push_back(d);
    dfs(d+1, start, link);
    link.pop_back();
}

int main(void) {
    vector <int> start;
    vector <int> link;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &status[i][j]);
        }
    }

    dfs(0, start, link);

    printf("%d\n", minNum);
    return 0;
}