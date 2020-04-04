/*
    처음에는 서류심사 기준 오름차순 정렬 후, 면접 랭킹을 거꾸로 비교해가면서
    기존 면접 랭킹보다 높은 랭킹이 존재할 시, 선발되지 못한다는 식으로 구현했으나 시간초과
    -> 서류심사 랭킹 1위를 기준으로 잡고, 면접 랭킹을 순서대로 비교하여 높은 랭킹이 존재하면 
        선발 후, 기준 랭킹 업데이트를 하는 방식으로 구현하였음
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int tc_num;
    int v_num;
    int document, interview;
    scanf("%d", &tc_num);

    vector <pair <int, int> > ranking[tc_num];
    int result[tc_num];

    for(int i=0;i<tc_num;i++) {
        scanf("%d", &v_num);
        for(int j=0;j<v_num;j++) {
            scanf("%d %d", &document, &interview);
            ranking[i].push_back(make_pair(document, interview));
        }

        sort(ranking[i].begin(), ranking[i].end());

        result[i]=1; // 첫 번째 사람 선발 
        int interviewRank = ranking[i][0].second; // 첫번째 사람 인터뷰 성적 

        for(int j=1;j<v_num;j++) {

            // 높은 랭킹 값을 가지고 있으면 선발 후, 기준 값 업데이트
            if(ranking[i][j].second < interviewRank) {
                result[i]++;
                interviewRank = ranking[i][j].second;
            }
        }

        printf("%d\n", result[i]);
    }

    return 0;
}
