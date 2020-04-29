/*
    2점을 받긴 했지만 풀었다.
    십진수를 n진법으로 변환하려면,
    십진수를 n으로 나눈 나머지를 저장해두고, 몫을 나누는 수로 바꿔주는 과정을
    몫이 0보다 작아질 때까지 반복 후, 저장된 값들을 reverse 해주면 된다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string marks = "0123456789ABCDEF";
    string str = "0";
    string answer = "";
    
    for(int i=0;i<t*m;i++) {
        int num=i;
        string temp="";
        while(num>0) {
            temp+=marks[num%n];
            num/=n;
        }
        reverse(temp.begin(), temp.end());
        str+=temp;
    }
  
    for(int i=0;i<t;i++)
        answer+=str[(p-1)+(i*m)];
    
    
    return answer;
}