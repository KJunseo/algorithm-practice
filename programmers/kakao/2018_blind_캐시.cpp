/*
    큐를 사용하여 구현하려고 시도했다.
    테스트케이스 11, 18, 20 에서 실패하였다.
    아마 cache hit 된 문자열만 업데이트 해줘야하는데,
    큐를 돌면서 그렇지 않은 것들 까지 업데이트가 되버린 경우가 있어서 그런가 예상해보지만 잘 모르겠다.

    큐 대신 벡터를 사용해서 구현하였다.
    cache hit이 있으면, 벡터에서 해당요소 삭제 후, 맨 끝으로 올려주었다.
    cache miss이면 가장 처음 요소를 삭제 후, 마지막에 새로운 요소를 삽입하였다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    
    if(cacheSize==0) 
        return 5*cities.size();
    
    for(int i=0;i<cities.size();i++) {
        int j=0;
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        for(j=0;j<v.size();j++) {
            if(cities[i]==v[j]) {
                v.erase(v.begin()+j);
                v.push_back(cities[i]);
                answer++;
                break;
            }
        }
        if(j==v.size()) {
            answer+=5;
            if(v.size()>=cacheSize) 
                v.erase(v.begin());
            v.push_back(cities[i]);
        }
    }
    
    return answer;
}


// 큐를 사용하여 직접 구현 시도하였으나 실패한 코드
/*
#include <queue>

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> q;
    
    if(cacheSize==0) 
        return answer=5*cities.size();
    
    for(int i=0;i<cities.size();i++) {
        int j=0;
        
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        for(j=0;j<q.size();j++) {
            string temp=q.front();
            q.pop();
            
            if(temp==cities[i]) {
                q.push(cities[i]);
                answer++;
                break;
            } else {
                q.push(temp);
            }
        }
        if(j==q.size()) {
            answer+=5;
            if(q.size()>=cacheSize)
                q.pop();
            q.push(cities[i]);
        }
    }
    
    return answer;
}
*/