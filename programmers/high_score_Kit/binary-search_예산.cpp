/*
    이분탐색으로 풀었다.
    알고리즘은 금방 생각했는데, 효율성테스트에서 계속 걸렸다 ㅎ..
    그래서 먼저 전체 예산을 더해보고, 통과하면 return 그게 아니라면,
    bianry search를 한 번 수행했다고 생각하고, 반으로 나눠서 재귀로 풀었다.
    재귀말고, 반복문으로 풀 수도 있는 것 같다.

    다른 사람의 풀이를 봤는데 엄청 간단한 풀이가 있었다.. 밑에 첨부하였다.
*/
#include <string>
#include <vector>

using namespace std;

int maxNum=0;
void binarySearch(int M, vector<int> budgets, int start, int end) {
    long sum=0;

    if(start>end) return;

    int mid=(start+end)/2;

    for(int i=0;i<budgets.size();i++) {
        if(budgets[i]>mid) sum+=mid;
        else sum+=budgets[i];
    }

    if(sum==M) {
        maxNum=mid;
        return;
    } else if(sum>M) {
        binarySearch(M, budgets, start, mid-1);
    } else if(sum<M) {
        binarySearch(M, budgets, mid+1, end);
        if(maxNum<mid) maxNum=mid;
    }
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    long check=0;
    int m_num=0;

    for(int i=0;i<budgets.size();i++) {
        check+=budgets[i];
        if(m_num<budgets[i]) m_num=budgets[i];
    }

    if(check<=M) return m_num;
    else if(check>M) {
        binarySearch(M, budgets, 0, m_num-1);
    } else if(check>M) {
        binarySearch(M, budgets, m_num+1, M);
    }

    answer=maxNum;

    return answer;
}

// 간단한 풀이 
int solution(vector<int> budgets, int M) {
    int answer = 0;
    int numbers = budgets.size();

    sort(budgets.begin(),budgets.end());

    for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
        if(*itr > (M / numbers)) return M/numbers;
        else{
            M -= *itr;
            numbers--;
        }
    }

    return budgets.back();
}