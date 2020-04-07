/*
    백준에서 풀었던 숫자야구와 완전히 똑같았다.

    세자리 수이므로 1000 크기의 배열을 만들어주고,
    3자리가 아니거나, 중복된 숫자가 있거나, 0을 가지고 있는 경우 false 처리해준다.

    123부터 987까지 돌면서, 해당 수와, 입력받은 수를 비교해서, 
    자리수는 다르지만 같은 수가 있는 경우 ball
    자리수도 같고, 수도 같으면 strike 를 ++해주고

    그 값들이 입력받은 strike, ball 수와 같은경우 answer을 + 해준다.
*/
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool checked[1000];
int solution(vector<vector<int>> baseball) {
    int answer = 0;

    memset(checked, true, sizeof(checked));

    for(int i=123;i<=987;i++) {
        string temp = to_string(i);
        if(temp[0]==temp[1] || temp[0]==temp[2] || temp[1]==temp[2]) checked[i]=false;
        if(temp[0]=='0' || temp[1]=='0' || temp[2]=='0') checked[i]=false;        
    }

    for(int l=0;l<baseball.size();l++) {
        string num=to_string(baseball[l][0]);
        int strike=baseball[l][1];
        int ball=baseball[l][2];

        for(int i=123;i<=987;i++) {
            int tempStrike=0;
            int tempBall=0;

            if(checked[i]) {
                string temp=to_string(i);

                for(int j=0;j<3;j++)
                    for(int k=0;k<3;k++) {
                        if(j==k && num[j]==temp[k]) tempStrike++;
                        if(j!=k && num[j]==temp[k]) tempBall++;
                    }

                if(tempStrike!=strike || tempBall!=ball) checked[i]=false;
            }
        } 
    }

    for(int i=123;i<=987;i++) {
        if(checked[i]) answer++;
    }

    return answer;
}