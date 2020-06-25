/*
    분명히 맞았다고 생각했는데 계속 틀렸다;;;
    반례하고 다 맞아서 뭐가 문젠가 했는데 도는 방향을 잘못했었다..
*/
#include <iostream>
#include <vector>

using namespace std;

struct Robot {
    int x;
    int y;
    char dir;
};

int A, B;
int N, M;
int board[101][101];

void spinLeft(Robot &r) {
    if(r.dir=='E') {
        r.dir='N';
    } else if(r.dir=='S') {
        r.dir='E';
    } else if(r.dir=='W') {
        r.dir='S';
    } else if(r.dir=='N') {
        r.dir='W';
    }
}

void spinRight(Robot &r) {
    if(r.dir=='E') {
        r.dir='S';
    } else if(r.dir=='S') {
        r.dir='W';
    } else if(r.dir=='W') {
        r.dir='N';
    } else if(r.dir=='N') {
        r.dir='E';
    }
}

int main(void) {

    cin >> A >> B;

    cin >> N >> M;

    vector<Robot> robot(N+1);
    for(int i=1;i<=N;i++) {
        scanf("%d %d %c", &robot[i].x, &robot[i].y, &robot[i].dir);
        board[robot[i].y][robot[i].x]=i;
    }

    for(int i=0;i<M;i++) {
        int robot_num;
        char command;
        int repeat;

        cin >> robot_num >> command >> repeat;

        for(int j=0;j<repeat;j++) {
            if(command=='L') {
                spinLeft(robot[robot_num]);
            } else if(command=='R') {
                spinRight(robot[robot_num]);
            } else if(command=='F') {
                int ny=robot[robot_num].y;
                int nx=robot[robot_num].x;

                if(robot[robot_num].dir=='E') {
                    nx++;
                } else if(robot[robot_num].dir=='S') {
                    ny--;
                } else if(robot[robot_num].dir=='W') {
                    nx--;
                } else if(robot[robot_num].dir=='N') {
                    ny++;
                }

                if(ny<1 || ny>B || nx<1 || nx>A) {
                    printf("Robot %d crashes into the wall\n", robot_num);
                    return 0;
                }

                if(board[ny][nx]!=0) {
                    printf("Robot %d crashes into robot %d\n", robot_num, board[ny][nx]);
                    return 0;
                }

                board[robot[robot_num].y][robot[robot_num].x]=0;
                robot[robot_num].y=ny;
                robot[robot_num].x=nx;
                board[robot[robot_num].y][robot[robot_num].x]=robot_num;
            }
        }
    }

    printf("OK\n");
    return 0;
}