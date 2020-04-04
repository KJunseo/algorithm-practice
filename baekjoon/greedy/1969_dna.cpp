/*
    오랜만에 혼자 문제 해결을 할 수 있는 문제였다.

    입력 받은 DNA들의 세로를 비교하여 가장 수가 많은 타입을 저장한다.
    그리고 다른 DNA들과 다른 곳을 비교하여 hamming distance를 계산한다.

    아무리 테스트해도 답이 잘 나와서 제출하였는데 런타임오류가 떠서 수정하였는데 틀렸습니다가 떴다.
    아무리봐도 잘못된 곳을 못 찾겠어서 그냥 다시 똑같이 처음부터 작성하서 제출하였는데 되었다.. 
    어딘가에서 실수가 있었나보다...
*/
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
    int most = 0, hd = 0; 
    vector <string> dna;
    string temp;
    string result;
    char c;

    scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
        cin >> temp;
        dna.push_back(temp);
    }
        
	for (int i = 0; i < m; i++) {
		int a = 0, t = 0, g = 0, c = 0;
		for (int j = 0; j < n; j++) {
			switch (dna[j][i]) {
			case 'A': a++; break;
			case 'T': t++; break;
			case 'G': g++; break;
			case 'C': c++; break;
			}
		}
		most = max(a > c ? a : c, g > t ? g : t);

	    if (most == a) c='A';
	    else if (most == c) c='C';
	    else if (most == g) c='G';
	    else c='T';
        
        result+=c;
	}
    cout << result << endl;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(result[j]!=dna[i][j]) hd++;
        }
    }

	printf("%d", hd);
}