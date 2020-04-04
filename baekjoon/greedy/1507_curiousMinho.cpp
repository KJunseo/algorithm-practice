/*
    처음에는 입력받은 값을 오름차순으로 정렬하여 하나씩 넣으며 비교해보려 했는데 구현하다 보니 다른방법으로 하게되었다.

    플로이드 와샬을 이용하여, 직접가는 것과 거쳐가는 것의 값을 비교하여 두 개의 값이 동일할 경우는 어차피 거쳐가면 되기 때문에
    직접 가는 경우를 없애주면 된다. 

    만약 거쳐가는 길보다 직접가는 길이 클 경우는 -1을 출력해줘야한다. 

    플로이드 와샬 알고리즘은 인터넷에서 찾았지만, 이 문제를 해결하기 위한 알고리즘은 혼자 생각해낸 것에 만족한다.
*/
#include <stdio.h>
#define MAX 21

int a[MAX][MAX];
bool v[MAX][MAX]={false, };
int main(void) {
    int n;
    int sum=0;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j || i==k || k==j) {
                    continue;
                } 
                if(a[i][k]+a[k][j]==a[i][j]) {
                    v[i][j]=true;
                } else if(a[i][k]+a[k][j]<a[i][j]) {
                    printf("%d\n", -1);
                    return 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!v[i][j]) 
                sum+=a[i][j];
        }
    }

    printf("%d\n", sum/2);

    return 0;
}