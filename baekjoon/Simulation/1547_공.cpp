/*
    Bronze 3 답게 쉬운 문제였다.
    근데 문제 설명에 공이 없어질 경우 -1을 출력하라는 설명은 왜있는지 모르겠다. 이것때문에 헷갈렸다.
    입력 받은 x나 y 둘 중 하나가 현재 공이 있는 컵의 번호와 같다면, 반대 컵으로 정답을 업데이트해주면 된다.
*/
#include <iostream>

using namespace std;

int M;

int main(void) {
    int ans=1;

    cin >> M;

    for(int i=0;i<M;i++) {
        int x, y;

        cin >> x >> y;

        if(x==ans) ans=y;
        else if(y==ans) ans=x;
    }

    cout << ans << "\n";

    return 0;
}