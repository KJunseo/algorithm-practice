/*
    sort를 할 때, 정렬 기준을 잘 세워주면 된다고 생각했다.
    먼저 모든 수들의 가장 앞자리 수가 큰 순서로 정렬하고, 
    만약 가장 앞자리 수가 같으면 그 다음 수를 비교한다.
    이때 3과 30 같은 수가 문제이다. 303 보다는 330이 크기 때문이다.

    간단한건데 생각을 못해냈다.
    먼저 numbers를 모두 string으로 바꿔 벡터에 넣고,
    compare 할 때, a+b 와 b+a를 비교해주면 되는 거였다. ex. 30 + 3 && 3 + 30
    모두 0일 경우는 예외처리로 0를 return 해주면 된다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if(a+b > b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> temp;
    
    for(auto e : numbers) {
        temp.push_back(to_string(e));
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    if(temp[0]=="0") return "0";
    
    for(int i=0;i<temp.size();i++) {
        answer+=temp[i];
    }
    
    return answer;
}