/*
    정확성은 모두 통과하였지만, 효율성에서 실패했다.
    union-found를 사용해야한다고 한다.

    빈 방인 경우는 바로 배정해주고, 배정된 방의 부모로 그 다음방을 배정한다.
    빈 방이 아닌 경우, 그 방의 부모를 계속 찾아가서 빈 방을 찾으면 배정해준다.

    이렇게 간단하게 구현하는 게 정말 대단한 것 같다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;

long long getParent(long long num) {
    if(m[num]==0) return num;
    
    return m[num]=getParent(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i=0;i<room_number.size();i++) {
        long long parent=getParent(room_number[i]);
        answer.push_back(parent);
        m[parent]=parent+1;
    }
    
    return answer;
}

// 정확성은 통과 했지만, 효율성에서 실패한 시도
/*vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<bool> check(k, false);
    
    for(int i=0;i<room_number.size();i++) {
        if(!check[room_number[i]]) {
            check[room_number[i]]=true;
            answer.push_back(room_number[i]);
        } else {
            int k=room_number[i]+1;
            while(true) {
                if(!check[k]) {
                    check[k]=true;
                    answer.push_back(k);
                    break;
                }
                k++;
            }
        }
    }
    
    return answer;
}*/