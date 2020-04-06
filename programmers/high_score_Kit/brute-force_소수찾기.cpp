/*
    입력받은 문자열로 만들 수 있는 경우의 수를 모두 구해야하는데 그게 잘 생각이 안났다.
    dfs를 사용하려 했는데, 제대로 설계를 못했다..

    dfs를 사용해서 풀 수 있었다.
    ckecked를 통해 이미 사용한 수라면 넘어가도록 하였다.
    visited를 통해 방문한 수는 넘어가도록 하였다.

    dfs를 구현하는 것이 아직 잘 안된다..
*/
#include <string>

using namespace std;

int answer;
bool checked[7];
bool visited[10000000];

bool isPrime(int num) {
    if(num==0 || num==1) return false;
    
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) return false;
    }
    return true;
}

void dfs(string numbers, string temp) {
    
    if(temp!="" && visited[stoi(temp)]==false) {
        visited[stoi(temp)]=true;
        if(isPrime(stoi(temp))==true) {
            answer++;
        }
    }
    
    for(int i=0;i<numbers.length();i++) {
        if(checked[i]==true) continue;
        checked[i]=true;
        dfs(numbers, temp+numbers[i]);
        checked[i]=false;
    }
}

int solution(string numbers) {

    dfs(numbers, "");

    return answer;
}