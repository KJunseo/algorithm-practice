/*
    이분 탐색 이용
    1. 벡터에 엄청 작은 수를 넣음
    2. 벡터에 가장 마지막 수와 입력받은 수를 비교하여 입력받은 수가 더 크면 삽입 후, lis 증가.
    3. 벡터의 가장 마지막 수와 입력받은 수를 비교하여 입력받은 수가 작으면 lower_bound로 입력받은 수가 들어갈 최적의 위치를 찾고 교체한다.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

int main(void) {
    int n;
    int temp;
    int cnt=0;
    scanf("%d", &n);

    vector <int> result;

    result.push_back(-INF);
    for(int i=0;i<n;i++) {
        scanf("%d", &temp);
        if(result.back()<temp) {
            result.push_back(temp);
            cnt++;
        } else {
            auto it=lower_bound(result.begin(), result.end(), temp);
            *it=temp;
        }
    }

    printf("%d\n", cnt);

    return 0;
}