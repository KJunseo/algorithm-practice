/*  
    문자열을 정렬해서 차례대로 넣으면서 수가 달라지면 사이에 넣는 방식으로 구현하려했다.

    팰린드롬을 만드는 방법은 2가지가 있다.
    1. 모든 문자가 짝수 일 때 -> 정렬 후 각 문자의 개수의 반 만큼 더해주고 출력 후 거꾸로 출력
    2. 하나의 문자만 홀수 일 때 -> 거꾸로 출력해 주기 전 홀수였던 문자 중간에 출력

    알파벳이 각각 몇개인지 카운트하고,
    홀수 갯수를 세면서 만약 2개이상되면 Sorry Hansoo
    그게 아니라면 알파벳과 카운트를 벡터에 넣는다.
    각 알파벳 갯수/2 만큼 string에 넣고
    한 번 출력 후, 홀수가 하나있으면 홀수 출력 후 거꾸로 출력
    없다면 그냥 거꾸로 출력한다.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

char name[50];
int alphabet[26];
string ans;
vector < pair<char, int> > v;
int main(void) {

    cin >> name;

    for(int i=0;i<strlen(name);i++) {
        alphabet[name[i]-'A']++;
    }

    char c='A';
    int checkOdd=0;
    vector <pair <char,int> > odd;

    for(int i=0;i<26;i++) {
        if(alphabet[i]%2==1) {
            checkOdd++;
            odd.push_back(make_pair(c, alphabet[i]));
        }
        if(checkOdd>1) {
            cout << "I'm Sorry Hansoo\n";
            return 0;
        }
        v.push_back(make_pair(c, alphabet[i]));
        c++;
    }

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].second/2;j++) {
            ans+=v[i].first;
        }
    }

    cout << ans;
    if(!odd.empty()) cout << odd[0].first;
    reverse(ans.begin(),ans.end());
    cout << ans;

    return 0;
}