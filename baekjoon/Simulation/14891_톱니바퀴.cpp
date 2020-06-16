/*
    문제 이해를 잘못해서 시간을 날렸다..
    처음에 톱니바퀴가 회전하고, 그 회전한 톱니바퀴 기준으로 양 옆 톱니바퀴를 회전시켜려 했다.
    하지만 문제가 원하는 것은 회전하기 전 톱니바퀴를 기준으로 양 옆 톱니바퀴를 회전시키는 것이었다.
    따라서 입력받은 톱니바퀴를 바꾸기 전에 양 옆 톱니바퀴부터 돌리니까 통과하였다.
*/
#include <iostream>
#include <deque>

using namespace std;

int K;
deque<int> cogwheel[5];

// 왼 쪽 톱니바퀴 돌리기
void checkBefore(int num, int dir) {
    if(dir==1) {
        // 왼쪽을 돌릴 수 있으면 
        if(num-2>=1 && cogwheel[num-2][2]!=cogwheel[num-1][6]) checkBefore(num-1, -1);

        // 반 시계 방향 
        cogwheel[num-1].push_back(cogwheel[num-1].front());
        cogwheel[num-1].pop_front();
    } else if(dir==-1) {
        // 왼쪽을 돌릴 수 있으면 
        if(num-2>=1 && cogwheel[num-2][2]!=cogwheel[num-1][6]) checkBefore(num-1, 1);

        // 시계 방향 
        cogwheel[num-1].push_front(cogwheel[num-1].back());
        cogwheel[num-1].pop_back();
    }
}

// 오른쪽 톱니바퀴 돌리기
void checkAfter(int num, int dir) {
    if(dir==1) {
        // 오른쪽을 돌릴 수 있으면 
        if(num+2<=4 && cogwheel[num+2][6]!=cogwheel[num+1][2]) checkAfter(num+1, -1);

        // 반 시계 방향
        cogwheel[num+1].push_back(cogwheel[num+1].front());
        cogwheel[num+1].pop_front();

    } else if(dir==-1) {
        // 오른쪽을 돌릴 수 있으면 
        if(num+2<=4 && cogwheel[num+2][6]!=cogwheel[num+1][2]) checkAfter(num+1, 1);

        // 시계 방향 
        cogwheel[num+1].push_front(cogwheel[num+1].back());
        cogwheel[num+1].pop_back();
    }
}

int main(void) {

    for(int i=1;i<=4;i++) {
        for(int j=0;j<8;j++) {
            int temp;

            scanf("%1d", &temp);
            cogwheel[i].push_back(temp);
        }
    }

    cin >> K;

    for(int i=0;i<K;i++) {
        int num, dir; 

        cin >> num >> dir;

        if(dir==1) {
            // 양 옆을 먼저 돌리고
            if(num-1>=1 && cogwheel[num][6]!=cogwheel[num-1][2]) checkBefore(num, dir);
            if(num+1<=4 && cogwheel[num][2]!=cogwheel[num+1][6]) checkAfter(num, dir);

            // 시계 방향 
            cogwheel[num].push_front(cogwheel[num].back());
            cogwheel[num].pop_back();
        } else if(dir==-1) {
            // 양 옆을 먼저 돌리고 
            if(num-1>=1 && cogwheel[num][6]!=cogwheel[num-1][2]) checkBefore(num, dir);
            if(num+1<=4 && cogwheel[num][2]!=cogwheel[num+1][6]) checkAfter(num, dir);

            // 반 시계 방향 
            cogwheel[num].push_back(cogwheel[num].front());
            cogwheel[num].pop_front();
        }
    }

    int sum=0;
    if(cogwheel[1][0]==1) sum+=1;
    for(int i=2;i<=4;i++) {
        if(cogwheel[i][0]==1) {
            sum+=2<<(i-2);
        }
    }

    cout << sum << "\n";

    return 0;
}