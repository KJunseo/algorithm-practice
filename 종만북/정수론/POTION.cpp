/*
    두 가지 풀이가 존재했다.
    첫 번째 풀이가 직관적이라고 하지만 required를 구하는 식을 아직도 잘 이해하지 못했다..
        i번째 재료가 put[i]/recipe[i] 배 들어갔으므로, 다른 재료들도 최소한 그만큼은 들어가야한다. 
        즉 recipe[j] * (put[i]/recipe[i])
        (recipe[i] - 1)는 올림을 위한 것이라고 한다

    두 번째 풀이
    모든 재료에 대해 recipe[i] * Y(유리수)가 정수인 최소의 Y를 이용한다.
    따라서 Y의 분모는 recipe[]의 모든 수들의 약수가 되어야한다. 즉, recipe[]의 모든 수들의 약수를 분모로 둔다.

    각 재료의 최대 공약수(b)를 구하고, 원래 레시피를 1/b 분량으로 나눈다.
    b는 모든 재료들의 약수이므로 recipe[i]/b 는 항상 정수이다. 
    만든 분량이 put[i]/recipe[i] 이상이 될때까지 1/b를 반복해서 만들어준다.

    이 문제는 공식을 만들어 적용하는 것을 이해하는 게 어려웠다.(나에게는)
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n;

// 시뮬레이션 
vector<int> solveSimulation(const vector<int>& recipe, vector<int> put) {

    int size = recipe.size();
    vector<int> ret(size);

    // recipe에 적힌 양보다 적게 들어간 재료가 있으면 recipe에 적힌 만큼은 넣어줌 
    for(int i = 0; i < size; i++) {
        ret[i] = max(recipe[i] - put[i], 0);
        put[i] += ret[i];
    }

    // 비율이 맞을 때 까지 각 재료 추가 
    while(true) {

        // 냄비에 재료를 더 넣지 않아도 될 때까지 반복 
        bool ok = true;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {

                // i 번째 재료에 의하면 모든 재료는 put[i] / recipe[i] = X배 이상은 넣어야 한다.
                // 따라서 put[j]는 recipe[j] * X 이상의 정수가 되어야 한다.
                // (recipe[i] - 1)을 더해주는 것은 올림을 하기 위함 
                int required = (put[i] * recipe[j] + recipe[i] - 1) / recipe[i];

                // 더 넣어야 하는가?
                if(required > put[j]) {
                    ret[j] += required - put[j];
                    put[j] = required;
                    ok = false;
                }
            }
        }

        if(ok) break;
    }

    return ret;
}

// 두 수의 최대 공약수
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 분수 a/b보다 같거나 큰 최소의 자연수 반환
int ceil(int a, int b) {

    return (a + b -1) / b;
}

// 유클리드 알고리즘 
vector<int> solve(const vector<int>& recipe, const vector<int>& put) {

    int size = recipe.size();

    // 모든 재료의 최대 공약수를 구함 
    int b = recipe[0];
    for(int i = 1; i < size; i++) {
        b = gcd(b, recipe[i]);
    }

    int a = b; // 최소 1배(b/b)는 만들어야 하기 때문에 b로 초기화 
    // (put[i]*b)/recipe[i]의 같거나 큰 최소의 자연수를 구해서 비교 
    for(int i = 0; i < size; i++) {
        a = max(a, ceil(put[i] * b, recipe[i]));
    }

    // a/b 배 분량 만들기 
    vector<int> ret(size);
    for(int i = 0; i < size; i++) {
        ret[i] = recipe[i] * a / b - put[i];
    }

    return ret;
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        vector<int> recipe;
        for(int i = 0; i < n; i++) {
            int amount;
            cin >> amount;

            recipe.push_back(amount);
        }

        vector<int> put; 
        for(int i = 0; i < n; i++) {
            int amount;
            cin >> amount;

            put.push_back(amount);
        }

        // vector<int> ret = solveSimulation(recipe, put); // 시뮬레이션 
        vector<int> ret = solve(recipe, put); // 유클리드 
        for(int i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}