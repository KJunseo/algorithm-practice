/*
    풀이 코드를 참고하여 풀었다. 카라츠바 빠른 곱셈도 완벽히 이해하지 못해서 그런지 어려웠다.

    성별을 남:1, 여:0으로 표현하면 남성-남성이 만났을 때만 곱의 결과가 1이 나온다. 
    따라서 모든 사람이 포옹을 하려면 곱을 더한 값이 0이어야한다.
    
    개인적으로 엄청 힘든 문제였다. 안보고 구현하기 힘들 것 같다.
    나중에 다시 한번 풀어봐야겠다.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;

// 각 자릿수 곱의 결과가 저장된 벡터를 이용해 올림 처리 
// void normalize(vector<int>& num) {
//     num.push_back(0);

//     for(int i=0;i+1<num.size();i++) {
//         if(num[i]<0) {
//             int borrow=(abs(num[i])+9)/10;
//             num[i+1]-=borrow;
//             num[i]+=borrow*10;
//         } else {
//             num[i+1]+=num[i]/10;
//             num[i]%=10;
//         }
//     }

//     뒤의 쓸모없는 0 제거 
//     while(num.size()>1 && num.back()==0) {
//         num.pop_back();
//     }
// }

// 두 긴 자연수의 곱을 반환
// multiply([3, 2, 1], [6, 5, 4]) = 123 * 456 = 56088 = [8, 8, 0, 6, 5]
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size()+b.size()+1, 0);

    // 새로운 벡터에 각 자리수의 곱 저장 
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            c[i+j] += a[i] * b[j];
        }
    }

    // normalize(c); // 자릿수 올림(이 문제에서는 각 자리가 0 또는 1이므로 두 자리수 까지 가지 않으므로 올림은 생략)

    return c;
}

// a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size()+1, b.size()+k));

    for(int i=0;i<b.size();i++) {
        a[i+k]+=b[i];
    }

    // normalize(a);
}

// a -= b (a>=b를 가정)
void subFrom(vector<int>& a, const vector<int>& b) {
    for(int i=0;i<b.size();i++) {
        a[i]-=b[i];
    }

    // normalize(a);
}

// 카라츠바의 빠른 곱셈(두 정수의 곱을 반환)
// a와 b가 256자리 수라면 
// a * b = a1 * b1 * 10^256 + (a1 * b0 + a0 * b1) * 10^128 + a0 * b0
//       = z2 * 10^256 + z1 * 10^128 + z0
//
// (a0 + a1) * (b0 + b1) = (a0 * b0) + (a1 * b0 + a0 * b1) + (a1 * b1)
//
// z2 = a1 * b1
// z0 = a0 * b0
// z1 = (a0 + a1) * (b0 + b1) - z0 - z2
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size();
    int bn = b.size();

    // a가 b보다 작은 경우 바꿔서 계산
    if(an<bn) return karatsuba(b, a);

    // a나 b가 0인 경우 빈 벡터 리턴
    if(an==0 || bn==0) return vector<int>();
    
    // a가 비교적 짧은 경우 O(n^2) 곱셈 사용 
    if(an <= 50) return multiply(a, b);

    int half = an/2;

    // a와 b를 반으로 나눈다.
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
    vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());

    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);
    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);

    // a0 = a0 + a1
    addTo(a0, a1, 0);
    // b0 = b0 + b1
    addTo(b0, b1, 0);

    // z1 = (a0 * b0) - z0 - z2
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    // result = z0 + z1 * 10^half + z2 * 10^(half * 2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half+half);

    return ret;
}

int hugs(const string& members, const string& fans) {
    int N = members.size();
    int M = fans.size();

    vector<int> N1(N), N2(M);

    // 맴버들의 성별을 1과 0으로 나타내기
    for(int i=0;i<N;i++) {
        N1[i] = (members[i] == 'M') ? 1 : 0;
    }

    // 팬들의 성별을 1과 0으로 나타내기
    for(int i=0;i<M;i++) {
        N2[M-i-1] = (fans[i] == 'M') ? 1 : 0;
    }

    vector<int> ret = karatsuba(N1, N2); // 카라츠바의 빠른 곱셈을 이용하여 곱하기
    int allHugs = 0;
    
    // 값이 0이면 모두 포옹이 가능한 상태
    for(int i=N-1;i<M;i++) {
        if(ret[i]==0) allHugs++;
    }

    return allHugs;
}

int main(void) {

    string members, fans;

    cin.sync_with_stdio(false);

    cin >> C;

    for(int t=0;t<C;t++) {
        cin >> members >> fans;

        cout << hugs(members, fans) << "\n";
    }

    return 0;
}