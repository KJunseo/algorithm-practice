/*
    이분 탐색으로도 풀 수 있다고 하지만, 그리디 연습 중이어서 그리디로 구현해보았다.

    책의 범위를 큰 값을 기준으로 오름차순으로 정렬하고(오름차순 정렬 시 뒤의 값들은 어차피 앞의 값보다 크기 때문에 무관해지기 때문)
    정렬된 범위를 a~b까지 돌아가면서 만약 비어있으면 학생에게 빌려준다.

    * 테스트 케이스를 여러개 받을 수 있기 때문에, 비어있는지 확인하는 bool 배열과, vector, cnt들은 테스트 케이스마다 초기화 해줘야한다.
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

bool checked[MAX];

bool compare(pair<int,int> &a, pair<int,int> &b) {
    if(!(a.second == b.second))
        return a.second < b.second;

    return a.first < b.first;
}

int main(void) {
    int test_num; // 테스트 케이스의 수 
    int n; // 책의 수(1부터 시작)
    int m; // 책을 빌리기 원하는 학생의 수
    int a,b; // 각 학생이 빌리기 원하는 책의 범위

    scanf("%d", &test_num);

    for(int i=0;i<test_num;i++) {
        scanf("%d %d", &n, &m);

        vector < pair<int,int> > d;
        int cnt=0;
        fill(checked, checked+MAX, false);

        for(int j=0;j<m;j++) {
            scanf("%d %d", &a, &b);
            d.push_back(make_pair(a,b));
        }

        sort(d.begin(), d.end(), compare);

        for(int j=0;j<m;j++) {
            for(int k=d[j].first;k<=d[j].second;k++) {
                if(!checked[k]) {
                    checked[k]=true;
                    cnt++;
                    break;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}