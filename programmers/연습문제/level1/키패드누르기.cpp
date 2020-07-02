/*
    2020 카카오 인턴십 1번 문제였다.
    그 때 쉽다고 생각했는데 답이 제대로 안나와 시간을 많이 잡아먹었었다..
    그런데 다시 풀어보니 쉽게 해결했다.

    먼저 휴대폰을 배열로 생각하고 각 번호의 좌표를 미리 정해놓았다.
    그 후 1, 4, 7이면 무조건 왼쪽
    3, 6, 9면 무조건 오른쪽
    그 외의 숫자는 좌표 차이 계산을 통해 왼손이 더 가까우면 왼손, 오른손이 더 가까우면 오른손으로 설정해주었고
    같은 경우 왼손잡이는 왼쪽, 오른손 잡이는 오른쪽으로 정해주었다.

    풀이를 비교해보니 방식은 비슷하게 푼 것 같다.
*/
#include <string>
#include <vector>

using namespace std;

pair<int, int> phone[]= {
    {3, 1},
    {0, 0},
    {0, 1}, 
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left=make_pair(3, 0);
    pair<int, int> right=make_pair(3, 2);
    
    for(int i=0;i<numbers.size();i++) {
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7) {
            left=phone[numbers[i]];
            answer+='L';
        } else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9) {
            right=phone[numbers[i]];
            answer+='R';
        } else {
            int l=abs(left.first-phone[numbers[i]].first) + abs(left.second-phone[numbers[i]].second);
             int r=abs(right.first-phone[numbers[i]].first) + abs(right.second-phone[numbers[i]].second);
            
            if(l<r) {
                left=phone[numbers[i]];
                answer+='L';
            } else if(l>r) {
                right=phone[numbers[i]];
                answer+='R';
            } else if(l==r) {
                if(hand=="left") {
                    left=phone[numbers[i]];
                    answer+='L';
                } else if(hand=="right") {
                    right=phone[numbers[i]];
                    answer+='R';
                }
            }
        }
    }
    
    
    return answer;
}