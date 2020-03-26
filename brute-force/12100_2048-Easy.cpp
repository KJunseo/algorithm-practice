/*
    풀 수 있을 것 같았다.
    dfs를 사용하여 board가 0이면 뒤에숫자를 덮어쓰고, 0이 아니고, 뒤의 숫자랑 값이 같으면 두 수를 더하는 방식으로 구현하려했었다.
    접근 방법은 거의 비슷하게 하였으나 실패하였다.
    풀 수 있을 것 같아서 시간을 엄청 썼는데 결국 못해내서 속상했다.

    큐를 쓰는 풀이가 인상깊었다.
    
    1. 0이 아니면 큐에 넣고, 숫자가 있던 자리를 0으로 바꿔준다.
    2. 큐에서 하나씩 꺼내면서 제일 끝 부분부터 집어넣는다.
    3. 만약 끝의 수와 큐에서 꺼낸 수가 같으면 2배를 해준다.
    4. 그렇지 않다면 idx를 증가 또는 감소시켜 다음 자리에 수를 넣어준다.

    어떻게 저런생각을 하는지 신기하다..

*/
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int result;
int board[20][20];

void dfs(int cnt) {
    int temp[20][20];
    if(cnt==5) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                result=max(result,board[i][j]);
            }
        }
        return;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            temp[i][j]=board[i][j];
        }
    }

    for(int k=0;k<4;k++) {
        queue <int> q;

        switch(k) {
            // 오른쪽
            case 0:
                for(int i=0;i<n;i++) {
                    for(int j=n-1;j>=0;j--) {
                        if(board[i][j]) q.push(board[i][j]);
                        board[i][j]=0;
                    }

                    int idx=n-1;

                    while(!q.empty()) {
                        int num=q.front();
                        q.pop();

                        if(board[i][idx]==0) board[i][idx]=num;
                        else if(board[i][idx]==num) {
                            board[i][idx]*=2;
                            idx--;
                        } else {
                            idx--;
                            board[i][idx]=num;
                        }
                    }
                }

                break;
            // 왼쪽
            case 1:
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        if(board[i][j]) q.push(board[i][j]);
                        board[i][j]=0;
                    }

                    int idx=0;

                    while(!q.empty()) {
                        int num = q.front();
                        q.pop();

                        if(board[i][idx]==0) board[i][idx]=num;
                        else if(board[i][idx]==num) {
                            board[i][idx]*=2;
                            idx++;
                        } else {
                            idx++;
                            board[i][idx]=num;
                        }
                    }

                }
                break;
            // 위
            case 2:
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        if(board[j][i]) q.push(board[j][i]);
                        board[j][i]=0;
                    }

                    int idx=0;

                    while(!q.empty()) {
                        int num = q.front();
                        q.pop();

                        if(board[idx][i]==0) board[idx][i]=num;
                        else if(board[idx][i]==num) {
                            board[idx][i]*=2;
                            idx++;
                        } else {
                            idx++;
                            board[idx][i]=num;
                        }
                    }

                }
                break;
            // 아래
            case 3:
                for(int i=0;i<n;i++) {
                    for(int j=n-1;j>=0;j--) {
                        if(board[j][i]) q.push(board[j][i]);
                        board[j][i]=0;
                    }

                    int idx=n-1;

                    while(!q.empty()) {
                        int num = q.front();
                        q.pop();

                        if(board[idx][i]==0) board[idx][i]=num;
                        else if(board[idx][i]==num) {
                            board[idx][i]*=2;
                            idx--;
                        } else {
                            idx--;
                            board[idx][i]=num;
                        }
                    }
                }
                break;
        }

        dfs(cnt+1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                board[i][j]=temp[i][j];
            }
        }
    }

}

int main(void) {

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &board[i][j]);
        }
    }

    dfs(0);

    printf("%d\n", result);

    return 0;
}