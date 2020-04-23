/*
    각각 경우의 누적합을 기억하면서 최대값을 찾아주려하였으나,
    중간 값을 없애주는 작업을 구현하지 못했다.

    ex.         7
            3       8
        8       1       0

    위와 같은 삼각형이 주어졌다고 하면, 3번째 줄의 1은 3에서 사용될 수도 있고, 8에서 사용될 수도 있다.
    이런 경우 둘 중 큰 값만 남겨야한다. 생각은 올바르게 하였으나 이 부분 구현을 실패했다..
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int> > s(triangle.size());

    s[0].push_back(triangle[0][0]);

    for(int i=1;i<triangle.size();i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) {
                s[i].push_back(s[i-1][j]+triangle[i][j]);
            } else if(j==i) {
                s[i].push_back(s[i-1][j-1]+triangle[i][j]);
            } else {
                int temp=max(s[i-1][j-1] + triangle[i][j], s[i-1][j] + triangle[i][j]);
                s[i].push_back(temp);
            }
        }
        if (i==triangle.size()-1) answer = *max_element(s[i].begin(), s[i].end());
    }

    return answer;
}