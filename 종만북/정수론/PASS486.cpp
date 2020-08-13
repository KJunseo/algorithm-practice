/*
    아직까지 factors[n] = (factors[m] / a) * (a + 1) 의 원리는 잘 이해하지 못했다..
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int TM = 1000 * 1000 * 10;
int minFactor[TM+1]; // 각 수의 가장 작은 소인수
int minFactorPower[TM+1]; // minFactor[i]의 몇 승이 포함되어 있는가
int factors[TM+1]; // 각 수의 약수의 수

int C;
int n, lo, hi;

// 에라토스테네스의 체 
void eratosthenes() {

    minFactor[0] = minFactor[1] = -1; // 1은 예외 처리

    // 자기 자신으로 초기화 
    for(int i = 2; i <= TM; i++) {
        minFactor[i] = i;
    }

    int sqrtn = int(sqrt(TM));
    for(int i = 2; i <= sqrtn; i++) {
        if(minFactor[i] == i) {
            for(int j = i*i; j <= TM; j+=i) {

                // 아직 약수를 본 적 없는 수인 경우 i로 바꾸기
                if(minFactor[j] == j) {
                    minFactor[j] = i;
                }
            }
        }
    }
}

// 1천만 이하의 모든 수의 약수의 수를 계산하는 알고리즘
void getFactorsSmart() {
    factors[1] = 1;

    for(int num = 2; num <= TM; num++) {

        // 소수인 경우 
        if(minFactor[num] == num) {
            minFactorPower[num] = 1; // 가장 작은 소인수의 계수는 1 
            factors[num] = 2; // 소수인 경우 약수는 1과 자기자신 총 2개 뿐 
        } else {
            int p = minFactor[num]; // n의 가장 작은 소인수
            int m = num / p; // 가장 작은 소인수로 나눈 수

            if(p != minFactor[m]) { // m이 p로 나누어 떨어지지 않는 경우
                minFactorPower[num] = 1; // 더 이상 나눌 수 없다면 승수는 1 
            } else {
                minFactorPower[num] = minFactorPower[m] + 1; // 나눌 수 있다면 나누는 수의 승수 + 1
            }

            int a = minFactorPower[num];
            factors[num] = (factors[m] / a) * (a + 1);
        }
    }
}

// 단순한 방법
void getFactorsBrute() {
    memset(factors, 0, sizeof(factors));

    for(int div = 1; div <= TM; div++) {
        for(int multiple = div; multiple <= TM; multiple += div) {
            factors[multiple] += 1;
        }
    }
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    eratosthenes(); // 에라토스테네스의 체 
    getFactorsSmart(); // 1천만 이하의 모든 수 약수의 수 계산
    // getFactorsBrute();

    for(int tc = 0; tc < C; tc++) {
        cin >> n >> lo >> hi;

        int ret = 0;
        for(int i = lo; i <= hi; i++) {

            // 약수의 수가 찾는 수와 동일하다면
            if(factors[i] == n) ret++;
        }

        cout << ret << "\n";
    }

    return 0;
}