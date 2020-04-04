/*
    처음에는 그냥 수를 벡터로 입력받아서 내림차순 정렬 후, k만큼 빼고 입력받았던 순서를 기준으로 오름차순 정렬해주면 되는거 아닌가?
    라고 생각하고 구현하여 테스트케이스를 통과하길래 맞은줄 알았지만, 틀렸다고 떴다.

    반례를 찾아보니, 6 2 / 391123 일 때, 내가 짠 코드는 1을 두개 삭제하여 3923이 출력되지만, 실제로는 3과 1을 뺀, 9123이 더 큰 수이다.
    
    덱(deque)를 사용해야 한다고 한다. 덱은 스택과 큐를 합친 형태로, 양쪽에서 모두 삽입/삭제를 할 수 있는 자료구조라고 한다.
    k가 0이 아니고, 덱안의 수가 다음 수보다 작으면 덱안의 수를 pop해준다. 반대의 경우는 push해준다.

*/
#include <stdio.h>
#include <queue>
#define MAX 500000

using namespace std;

char number[MAX];
int main(void) {
    int n,k;
    char temp;
    deque <char> dq;

    scanf("%d %d", &n ,&k);
    scanf("%s", number);

    for(int i=0;i<n;i++) {
        while(k>0 && !dq.empty() && dq.back() < number[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(number[i]);
    }

    // k만큼 지우지 못해도, 입력받은 숫자의 길이가 끝났으면 루프문이 종료되기 때문에
    // 덱의 크기에서 남은 k의 수를 뺀 값 만큼만 출력해준다.
    for(int i=0;i<dq.size()-k;i++) {
        printf("%c", dq[i]);
    }

    return 0;
}