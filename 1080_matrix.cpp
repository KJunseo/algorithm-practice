#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector <string> A,B;
int result, row, col;
bool flag = true;

// 같은지 안 같은지 검사 
void check() {
    for(int i=0;i<row;i++) {
        if(flag) {
            for(int j=0;j<col;j++) {
                if(A[i][j]!=B[i][j]) {
                    printf("%d\n", -1);
                    flag=false;
                    break;
                }
            }
        }
    }
}

// 3x3 씩 A 행렬의 값 변경 
void change() {
    for(int i=0;i<row-2;i++) {
        for(int j=0;j<col-2;j++) {
            if(A[i][j]!=B[i][j]) {
                result++;
                
                for(int k=0;k<3;k++) {
                    for(int l=0;l<3;l++) {
                        if(A[i+k][j+l]=='0') A[i+k][j+l] = '1';
                        else A[i+k][j+l] = '0';
                    }
                }
            }
        }
    }
}

int main(void) {
    string temp;

    scanf("%d %d", &row, &col);

    for(int i=0;i<row;i++) {
        cin >> temp;
        A.push_back(temp);
    }

    for(int i=0;i<row;i++) {
        cin >> temp;
        B.push_back(temp);
    }

    // 3x3 미만의 행렬일 경우, 같은지 안 같은지만 검사하면 됨
    if(row>=3 && col>=3) {
        change();
    } 

    check();

    if(flag) printf("%d\n", result);

    return 0;
}