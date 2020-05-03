/*
    길이가 1인 키로 검사 unique한 속성은 제거
    남은 속성들로 길이가 2인 키 생성 unique한 속성은 제거
    남은 속성들로 길이가 3인 키 생성 unique한 속성은 제거
    ...

    이런식으로 풀이하려고 하였는데, 실패했다..

    가능한 모든 조합을 만들고, 조건은 만족시키는 조합을 세어야한다고 한다.
    dfs 또는 bit를 이용하여 중복을 검사한다. 
    순서는 [가능한 모든 조합 만들기 -> 중복 검사하여 슈퍼키 집합 만들기 -> 부분집합 검사하여 최소성 만족하는 집합 구하기] 이다.

    비트셋을 이용하는 풀이를 봤는데 너무 어려웠다..(https://jayrightthere.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%9B%84%EB%B3%B4%ED%82%A4-1)
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countBit(int x) {
    int cnt=0;
    while(x) {
        if(x&1) cnt++;
        x=x>>1;
    }
    return cnt;
}

bool compare(int &a, int &b) {
    return countBit(a) > countBit(b);
}

// 유일성 체크 
bool check(vector<vector<string>> relation, int rowSize, int colSize, int bit) {
    // 한 속성씩 비교
    for(int i=0;i<rowSize-1;i++) {
        for(int j=i+1;j<rowSize;j++) {
            bool flag=true;
            for(int k=0;k<colSize;k++) {
                if((bit&(1<<k))==0) continue; // 포함되어 있지 않은 경우 continue
                if(relation[i][k]!=relation[j][k]) { // 포함된 요소이며, 다른 row와 칼럼을 비교해서 같지 않으면  
                    flag=false;
                    break;
                }
            }
            if(flag) return false; // 같은 경우 false 리턴
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowSize = relation.size(); // 전체 튜플 갯수 
    int colSize = relation[0].size(); // 각 튜플의 속성 갯수
    vector<int> candidateKey; // 후보키 집합 
    
    // 비트셋 사용(각 자리수로 해당 속성이 포함되는지 표시)
    /*
        ex. 0000 -> {}
            0001 -> {100}
            0101 -> {100, computer}
    */
    for(int i=1;i<(1<<colSize);i++) {

        // 유일성을 만족하면 후보키 집합에 넣음
        if(check(relation, rowSize, colSize, i)) { 
            candidateKey.push_back(i);
        }
    }
    
    sort(candidateKey.begin(), candidateKey.end(), compare); // 집합의 크기 순으로 정렬(1의 갯수가 가장 작은게 마지막)
    
    while(!candidateKey.empty()) {
        int key=candidateKey.back();
        answer++;
    
        for(auto it=candidateKey.begin();it!=candidateKey.end();) {
            if((key&(*it))==key) { // 작은 집합을 부분집합으로 가지고 있는 경우 삭제
                candidateKey.erase(it);
            } else it++;
        }
    }
    
    return answer;
}