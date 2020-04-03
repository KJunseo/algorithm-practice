/*
    처음에 가장 작은 수 보다 큰 값은 고려하지 않아도 된다고 생각했다가 틀렸다.
    그래서 가장 큰 수와 비교하니까 시간초과가 나버렸다 ㅎㅎ..

    수학문제였다.
    어떤 수를 m으로 나누었을 때 나머지가 r이라면, v[i] = m*temp[i]+r 이다.

    우리는 m을 구해야하기 때문에 r을 없애준다.

    나머지를 없애주려면 같은 나머지를 가진 수를 빼줘야한다.
    v[i]-v[i-1] = m*(temp[i]-temp[i-1]) + (r-r)

    -> 입력 받은 n개의 수를 오름차순 정렬 후, v[i]-v[i-1]의 최대공약수를 구하고,
    최대공약수의 약수를 오름차순 정렬한다.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long number[100];
vector <int> result;
int GCD(long long a, long long b) {
    if(a%b==0) return b;
    return GCD(b, a%b);
}

int main(void) {

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%lld", &number[i]);
    }

    sort(number, number+n);

    // 오름차순으로 정렬된 수들의 차를 구해서, 최대공약수를 구한다.
    int gcd=number[1]-number[0];
    for(int i=2;i<n;i++) {
        gcd = GCD(gcd, number[i]-number[i-1]);
    }

    // 최대 공약수의 약수를 구한다.
    // ex 100인 경우 -> 1 2 4 5 20 25 50 100
    // 1 2 4 5 만 구해주면, 100/1, 100/2, 100/3, 100/4, 100/5 로 나머지 약수들을 구할 수 있다
    for(int i=2;i*i<=gcd;i++) {
        if(gcd%i==0) {
            result.push_back(i);
            result.push_back(gcd/i);
        }
    }
    result.push_back(gcd); // 1을 포함하지 않고, for문을 돌렸기 때문에 마지막에 더해줘야 한다. 

    sort(result.begin(), result.end());

    result.erase(unique(result.begin(), result.end()), result.end()); // 중복을 제거한다.

    for(int i=0;i<result.size();i++) {
        printf("%d ", result[i]);
    }

    return 0;
}