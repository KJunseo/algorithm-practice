/*
    문자열 검색 문제인데, 중복만 제거해주면 되는 것이었다.
    KMP알고리즘을 사용하였다. KMP알고리즘 구현방법은 생각나지 않아 찾아보고 하였고, 문제에 맞게 조건만 고쳐주니 통과했다.

    KMP는 주어진 pattern으로 prefix == suffix의 최대 값을 찾고,
    document와 pattern을 비교하면서,
    같으면 다음 문자로 넘어가고, 패턴의 끝까지 동일하면 카운트해주었다.
    같지 않으면, pattern을 검사하는 index를 'precix==suffix' 테이블 값으로 바꿔주어 중간단계를 뛰어넘어준다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int cnt=0;

// prefix == suffix 중 가장 큰 값을 가진 것을 찾는다.
vector <int> makeTable(string pattern) {
    int patternSize = pattern.size();

    vector <int> table(patternSize, 0);

    int j=0;
    for(int i=1;i<patternSize;i++) {
        while(j>0 && pattern[i]!=pattern[j]) {
            j=table[j-1];
        }
        if(pattern[j]==pattern[i]) {
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string document, string pattern) {
    vector <int> table = makeTable(pattern);

    int documentSize = document.size();
    int patternSize = pattern.size();

    int j=0;
    for(int i=0;i<documentSize;i++) {
        while(j>0 && document[i]!=pattern[j]) { // 중간 단계를 스킵하는 부분
            j=table[j-1];                       // while문을 쓰는 이유는 최대로 스킵하기 위함! 
        }
        if(document[i]==pattern[j]) {
            if(j==patternSize-1) {
                cnt++;
                j=0;
            } else {
                j++;
            }
        }
    }
}

int main(void) {
    string document;
    string pattern;

    getline(cin, document);
    getline(cin, pattern);

    kmp(document, pattern);

    printf("%d\n", cnt);

    return 0;
}