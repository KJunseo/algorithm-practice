/*
    빨간 타일을 기준으로 생각하였다.
    처음에는 모든 빨간타일을 가로로만 배치하여서 시작하였다.
    빨간 타일을 기준으로 갈색타일이 빨간 타일을 둘렀을 때, 갯수가 일치하면 return하였다.
    일치하지 않는다면, 높이를 1늘리고, 높이만큼 가로를 나누어서 반복진행했다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int width=red;
    int height=1;

    while(width>=1) {
        if(width<height) break;
        if(red%height==0) {
            if((width*2)+(height*2)+4==brown) {
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }
        }

        height++;
        width=red/height;
    }

    return answer;
}