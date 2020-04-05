/*
    그냥 진짜 완전 무식하게 풀었다.
    맞긴 했지만 더 간단한 방법이 있을게 분명하다는 생각이 들었다.

    간단하게 처음 벡터를 반복전까지만 초기화 해주고,
    answers 크기만큼 index를 증가시키면서 index % '해당 index의 각각 수포자의 값'과 비교해주면 되는 문제다.

    max_element 라는 함수도 처음봤다. 주소를 리턴하므로, *를 붙여주면 값을 참조할 수 있다.

    가장 큰 값을 가지고 있는 수포자를 answer에 넣어주면 된다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> three = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3);
    int result=0;
    
    for(int i=0;i<answers.size();i++) {
        if(answers[i]==one[i%one.size()]) cnt[0]++;
        if(answers[i]==two[i%two.size()]) cnt[1]++;
        if(answers[i]==three[i%three.size()]) cnt[2]++;
    }

    result = *max_element(cnt.begin(), cnt.end());
    
    for(int i=0;i<3;i++) {
        if(result==cnt[i]) answer.push_back(i+1);
    }
    
    return answer;
}

// 내가 풀이한 방법
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one, two, three;
    int cntOne=0;
    int cntTwo=0;
    int cntThree=0;
    int result=0;

    int idx=1;
    for(int i=0;i<answers.size();i++) {
        one.push_back(idx);
        idx++;
        if(idx==6) idx=1;
    }

    idx=1;
    for(int i=1;i<=answers.size();i++) {
        if(idx!=2 && i%2==0) {
            two.push_back(idx);  
            idx++;
        } else two.push_back(2);
        if(idx==2) idx=3;
        if(idx==6) idx=1;
    }

    for(int i=0;i<answers.size();i++) {
        if(i%10==0 || i%10==1) three.push_back(3);
        else if(i%10==2 || i%10==3) three.push_back(1);
        else if(i%10==4 || i%10==5) three.push_back(2);
        else if(i%10==6 || i%10==7) three.push_back(4);
        else if(i%10==8 || i%10==9) three.push_back(5);
    }

    for(int i=0;i<answers.size();i++) {
        if(answers[i]==one[i]) cntOne++;
        if(answers[i]==two[i]) cntTwo++;
        if(answers[i]==three[i]) cntThree++;
    }

    if (cntOne>cntTwo) {
        if (cntOne > cntThree) {
            answer.push_back(1);
        } else if(cntOne==cntThree) {
            answer.push_back(1);
            answer.push_back(3);
        } else {
            answer.push_back(3);
        }
    } else if(cntTwo==cntOne) {
        if(cntOne==cntThree) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        } else if(cntOne<cntThree) {
            answer.push_back(3);
        } else {
            answer.push_back(1);
            answer.push_back(2);
        }
    } else {
        if (cntTwo > cntThree) {
            answer.push_back(2);
        } else if(cntTwo==cntThree) {
            answer.push_back(2);
            answer.push_back(3);
        } else {
            answer.push_back(3);
        }
    }

    return answer;
}