/*
    처음에 벡터로 구현하려고 했는데 자꾸 시간 초과가 났다.
    알아보니 중간에 insert/erase 할 때는 벡터나 덱 보다는 list가 훨씬 효율적이라고 한다.
    list를 알고리즘 때 처음 써본 것 같다.

    그래도 자꾸 틀려서 왜인가 했더니 출력할 때 테이스케이스 사이에 \n를 안 출력해줘서 그랬다ㅎㅎ..

    list.insert(iter, k) -> iter가 가리키는 위치에 k를 삽입하고 삽입한 원소를 가리키는 iter를 반환한다.
    list.erase(iter) -> iter가 가리키는 원소를 삭제하고 삭제한 원소의 다음 원소를 가리키는 iter를 반환한다.

    만약 A B C 가 있고 커서가 B에 있는 경우
    1. insert: 새로운 D를 넣으면 B의 왼편에 들어가게되야하고
    2. erase: 만약 커서 위치에서 삭제를 하려고하면 A가 삭제되어야한다

    따라서 구현할때 erase에서 --를 해주어야한다. 그렇지 않으면 B가 삭제될 것이다.

    스택을 이용한 풀이도 있어서 밑에 추가하였다.
    두 개의 스택을 만들고
    <: 첫 번째 스택 pop & 두 번째 스택 push
    >: 두 번째 스택 pop & 첫 번째 스택 push
    -: 첫 번째 스택 pop
    문자: 첫 번째 스택 push

    그리고 두 번째 스택이 만약 비어있지 않다면 차례대로 첫 번째 스택에 추가해주면 된다.

    스택이기 때문에 거꾸로 출력해줘야 답이 나온다. 그래서 나는 덱을 사용해 스택처럼 구현 후 
    출력할 때 덱의 인덱스를 이용해서 그냥 출력해주었다.
    메모리와 시간에 있어서 두 번째 방법이 훨씬 효율성이 좋았다.
*/

// list 사용 
#include <iostream>
#include <list>

using namespace std;

int main(void) {
    int testcase;

    scanf("%d", &testcase);

    for(int i=0;i<testcase;i++) {
        string str;
        cin >> str;

        list<char> password;
        list<char>::iterator cursor = password.begin();

        for(int j=0;j<str.size();j++) {
            if(str[j]=='<') {
                if(cursor!=password.begin()) cursor--; // 커서가 현재 문자열 시작점이 아니라면 왼쪽으로 이동 
            } else if(str[j]=='>') {
                if(cursor!=password.end()) cursor++; // 커서가 현재 문자열 끝점이 아니라면 오른쪽 이동 
            } else if(str[j]=='-') {
                if(cursor!=password.begin()) cursor=password.erase((--cursor)); // 이전 값을 지우기 위해 --
            } else {
                password.insert(cursor, str[j]);
                // 위의 한 줄과 아래 두줄이 같은 기능을 한다.
                /*cursor=password.insert(cursor, str[j]); 
                cursor++;*/
            }
        }

        for(auto c : password) 
            printf("%c", c);

        printf("\n");
    }

    return 0;
}

// 덱(스택) 사용
#include <iostream>
#include <deque>

using namespace std;

int main(void) {

    int testcase;

    scanf("%d", &testcase);

    for(int i=0;i<testcase;i++) {
        string str;
        cin >> str;

        deque<char> result;
        deque<char> temp;

        for(int j=0;j<str.size();j++) {
            if(str[j]=='<') {
                if(!result.empty()) {
                    temp.push_back(result.back());
                    result.pop_back();
                }
            } else if(str[j]=='>') {
                if(!temp.empty()) {
                    result.push_back(temp.back());
                    temp.pop_back();
                }
            } else if(str[j]=='-') {
                if(!result.empty()) result.pop_back();
            } else {
                result.push_back(str[j]);
            }
        }

        // 임시 스택이 비어 있지 않다면 결과 스택으로 옮겨준다.
        while(!temp.empty()) {
            result.push_back(temp.back());
            temp.pop_back();
        }

        for(int j=0;j<result.size();j++) {
            printf("%c", result[j]);
        }
        printf("\n");
    }
    return 0;
}