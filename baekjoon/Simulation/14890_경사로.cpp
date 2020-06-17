/*
    구현이 너무 복잡했다..
    가로부터 체크하고 경사로를 놓은 곳을 방문체크하고 세로를 체크하는 식으로 구현하려고 했으나
    너무 복잡해서 실패했다.

    4가지 조건문을 생각해주면 된다고 한다.
    1. 땅의 높이가 같은 경우
    2. 앞의 땅이 1만큼 높은 경우
    3. 뒤의 땅이 1만큼 높은 경우
    4. 높이 차이가 2이상인 경우

    그리고 처음 입력받을 때, 행과 열을 바꾼 지도를 하나 더 생성해서 똑같은 과정을 거치면 된다고 한다.
    가로에 이미 경사로를 놓았으면 세로 체크 시 경사로가 겹칠 수도 있을 거라고 생각하고 방문체크를 해야하나 생각했는데 
    방문체크는 굳이 하지 않아도 되나보다.
    참고: https://yabmoons.tistory.com/49

    + 더 간단한 코드도 아래에 추가했다.
    참고: https://rebas.kr/788
*/
#include <iostream>

using namespace std;

int N, L;
int map[100][100];
int map2[100][100];

// 기준점에서 뒤쪽에 L길이의 경사로를 놓을 수 있는지 확인 
bool isInstall(int m[][100], int y, int x) {
    int standard=m[y][x+1]; // 기준 높이
    
    // L만큼 반복 
    for(int j=x+1;j<x+1+L;j++) {
        if(m[y][j]!=standard) return false; // 기준점이랑 높이가 다른곳이 존재하면 설치 불가
    }

    return true;
}

// 가로 기준으로 연결된 길이 몇 개 인지 확인 
int roadCnt(int m[][100]) {
    int total=0; // 연결된 길의 수 

    for(int i=0;i<N;i++) {
        bool flag=true; // 길이 연결되었는지 여부
        int beforeCnt=1;

        for(int j=0;j<N-1;j++) {
            if(m[i][j]==m[i][j+1]) beforeCnt++; // 인접한 두 곳의 높이가 같은경우 beforeCnt만 증가 
            else if(m[i][j]==m[i][j+1]+1) { // 뒤의 장소가 높이가 1 높은 경우 
                // 설치 할 수 있다면 
                if(isInstall(m, i, j)) {
                    j=j+L-1; // 설치된 이후 지점으로 좌표 옮기기 
                    beforeCnt=0;
                } else { // 설치할 수 없다면 길이 연결될 수 없으므로 바로 종료 
                    flag=false;
                    break;
                }
            } else if(m[i][j]+1==m[i][j+1]) { // 앞의 장소가 1 높은 경우 
                // beforeCnt가 L보다 커야지 경사로 설치가능 
                if(beforeCnt>=L) {
                    beforeCnt=1;
                } else { // L길이의 경사로를 설치할 수 없으므로 바로 종료 
                    flag=false;
                    break;
                }
            } else if(abs(m[i][j]-m[i][j+1])>=2) { // 두 장소의 높이차가 2이상이면 어차피 길 연결 불가이기 때문에 종료
                flag=false;
                break;
            }
        }

        if(flag) total++; // 길이 연결될 수 있는 경우 total 증가
    }

    return total;
}

int main(void) {

    cin >> N >> L;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            map2[j][i]=map[i][j]; // 세로 체크를 따로 구현하지 않기 위함
        }
    }

    cout << roadCnt(map)+roadCnt(map2) << "\n";

    return 0;
}

// 간단한 코드
#include <cstdio>

int N, L, ans;
int map[100][100];

void slope(int i, bool c) {
    int cnt=1;
    for (int j=0; j<N-1; j++) {
        int d = c == 1 ? map[i][j+1]-map[i][j] : map[j+1][i]-map[j][i];
        if (d == 0) cnt++; // 두 곳의 차이가 0이면 cnt증가 
        else if (d == 1 && cnt >= L) cnt = 1; // 올라가는 경사로 
        else if (d == -1 && cnt >= 0) cnt = -L+1; // 내려가는 경사로(카운트를 경사로 길이 만큼 음수로 만든다 이미 음수이면 내려가는 경사로를 설치하고 있는 중이다.)
        else return; // 나머지 경우는 길이 연결될 수 없음
    }
    if (cnt >= 0) ans += 1; // cnt가 0이상이면 길이 연결된 것이다.
}

int main() {
    scanf("%d %d", &N, &L);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        slope(i, 1); // 가로 체크
        slope(i, 0); // 세로 체크
    }

    printf("%d\n", ans);
    return 0;
}
