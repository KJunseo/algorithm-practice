/*
    동적 계획법의 구현 패턴을 읽고나서 풀어보니 동적 계획법이 조금은 감이 오는 것 같았다.
    또 참조형 변수를 사용하여 값을 자동으로 변경시키는 부분도 흥미로웠다.
*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int C;
int n;
int board[100][100];
int cache[100][100];

int jump(int y, int x) {

    // 기저 사례: board를 벗어난 경우 0
    if(y>=n || x>=n) return 0;

    // 기저 사례: 도착점에 도착한 경우 1
    if(y==n-1 && x==n-1) return 1;

    // 메모이제이션
    int& ret = cache[y][x]; // 참조형 변수 사용 
    if(ret!=-1) return ret;

    int jumpSize = board[y][x];

    return ret = (jump(y, x+jumpSize) || jump(y+jumpSize, x)); // 오른쪽이나 아래로 이동
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {

        // 캐시 저장소 초기화
        memset(cache, -1, sizeof(cache));

        cin >> n;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> board[i][j];
            }
        }

        cout << (jump(0, 0) == 1 ? "YES" : "NO") << "\n";
    }

    return 0;
}