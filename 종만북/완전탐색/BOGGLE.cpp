/*
    완전 탐색에 등장하는 문제지만, 완전 탐색으로 풀고 제출하면 시간초과가 나버린다.
    DP 문제이다.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int C, N;
char board[5][5];
string words[10];

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string& word) {

    if(y<0 || x<0 || y>=5 || x>=5) return false;

    if(board[y][x]!=word[0]) return false;

    if(word.size()==1) return true;

    for(int i=0;i<8;i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(hasWord(ny, nx, word.substr(1))) return true;
    }

    return false;
}

int main(void) {

    cin.sync_with_stdio(false);

    cin >> C;

    for(int k=0;k<C;k++) {
        
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                cin >> board[i][j]; 
            }
        }

        cin >> N;

        for(int i=0;i<N;i++) {
            cin >> words[i];
        }

        for(int i=0;i<N;i++) {

            bool flag = false;

            for(int r=0;r<5;r++) {
                for(int c=0;c<5;c++) {
                    if(hasWord(r, c, words[i])) {
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            cout << words[i] << " " << (flag ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}