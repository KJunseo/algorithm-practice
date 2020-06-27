/*
    처음보고 쉽네 라고 생각했는데 생각보다 계속 틀렸다;;
    문제 이해를 잘못했다..

    무조건 이동 가능한 좌표만 준다고 생각했는데 그게 아니었다..
*/
#include <iostream>

using namespace std;

int visit[7][7];
string go;
int p_row, p_col; // 이전 값 
int s_row, s_col; // 시작 값 
int row, col; // 현재 값 

int main(void) {
    cin >> go;

    p_row=go[1]-'1'+1;
    p_col=go[0]-'A'+1;;

    // 시작 지점 세팅
    s_row=p_row;
    s_col=p_col;

    for(int i=0;i<36;i++) {

        if(i==35) { // 마지막 요소면 시작점을 넣어줘서 이전 값과 비교하기 
            row=s_row;
            col=s_col;
        } else {
            cin >> go;

            row=go[1]-'1'+1;
            col=go[0]-'A'+1;
        }

        // 방문 하지 않은 상태이면서 동시에 나이트가 이동할 수 있는 곳이면 방문 처리
        if(!visit[row][col]) {
            if(((abs(row-p_row)==1 && abs(col-p_col)==2) || (abs(row-p_row)==2 && abs(col-p_col)==1))) {
                visit[row][col]=true;
                p_row=row;
                p_col=col;
            } else {
                cout << "Invalid\n";
                return 0;
            }
        } else {
            cout << "Invalid\n";
            return 0;
        }

    }

    cout << "Valid\n";
    
    return 0;
}