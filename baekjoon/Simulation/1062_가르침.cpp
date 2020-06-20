/*
    조합(dfs)을 이용해서 풀 수 있었다.
    알파벳 26개 중에 K개의 글자를 조합(dfs)을 이용해서 고르고
    입력받은 문자열을 셀 수 있는지 확인하면 된다.
    이 때 모든 문자열은 anta___tica로 구성되어 있으므로 a, c, i, n, t 는 항상 K개 중에 포함되어 있어야한다.
*/ 
#include <iostream>
#include <vector>

using namespace std;

int N, K;
int ans;
bool selected[26];
vector<string> str;

void checkRead() {
    int cnt=0;
    for(int i=0;i<str.size();i++) {
        bool flag=false;
       
        for(int j=0;j<str[i].length();j++) {

            // 입력받은 각각의 문자열을 한 글자씩 비교
            if(!selected[str[i][j]-97]) {
                flag=true;
                break;
            }
        }
        if(!flag) cnt++;
    }
    if(ans<cnt) ans=cnt;
}

// 조합. 알파벳에서 K개의 글자 고르기
void dfs(int idx, int cnt) {

    // k개를 골랐으면 입력받은 문자열을 몇 개나 셀 수 있는지 확인
    if(cnt==K) {
        checkRead();
        return ;
    }

    // K개의 글자 고르기
    for(int i=idx;i<26;i++) {
        if(selected[i]==true) continue;
        selected[i]=true;

        dfs(i, cnt+1);
        selected[i]=false;
    }
}

int main(void) {

    scanf("%d %d", &N, &K);

    if(K<5) {
        printf("%d\n", 0);
        return 0;
    } else if(K==26) {
        printf("%d\n", N);
        return 0;
    }

    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;

        str.push_back(temp);
    }

    selected['a'-97]=true; // a
    selected['c'-97]=true; // c
    selected['i'-97]=true; // i
    selected['n'-97]=true; // n
    selected['t'-97]=true; // t

    dfs(1, 5); // a는 항상 포함이므로 b부터 시작 & 5개의 문자는 항상 포함이므로 cnt는 5부터 시작

    printf("%d\n", ans);

    return 0;
}