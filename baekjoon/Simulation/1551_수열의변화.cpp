/*
    벡터를 사용해서 풀었다. ,로 구분하여 정수를 입력받고
    벡터 크기-1만큼 돌면서 a[i+1]-a[i] 연산을 수행하였다.
*/
#include <iostream>
#include <vector>

using namespace std;

int N, K;
int num;
vector<int> sequence, nsequence;

int main(void) {

    cin >> N >> K;

    for(int i=0;i<N-1;i++) {
        scanf("%d,", &num);
        sequence.push_back(num);
    }
    scanf("%d", &num);
    sequence.push_back(num);

    for(int i=0;i<K;i++) {
        nsequence.clear();
        for(int j=0;j<sequence.size()-1;j++) {
            nsequence.push_back(sequence[j+1]-sequence[j]);
        }
        sequence.clear();
        sequence.assign(nsequence.begin(), nsequence.end());
    }

    for(int i=0;i<sequence.size()-1;i++) {
        printf("%d,", sequence[i]);
    }
    printf("%d", sequence[sequence.size()-1]);

    return 0;
}