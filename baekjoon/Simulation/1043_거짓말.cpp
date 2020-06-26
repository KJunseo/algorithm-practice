/*
    union-found가 생각이 안나서 삽질을 했다..
    각 파티마다 진실을 아는 사람이 하나라도 포함되면 그 파티에 참여한 모든 사람들이 진실을 안다고 생각하면 된다.
    따라서 union으로 각 파티의 모든 멤버를 연결시키고
    모든 파티를 탐색하면서 해당 파티에 참여한 사람들과, 진실을 아는 사람들의 부모가 하나라도 같은 경우 과장할 수 없다고 생각하면 된다.

    reference: https://seokjin2.tistory.com/44
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[51];
vector<int> truth; // 진실을 아는 사람 집합 
vector<vector<int> > party(50); // 각 파티에 참여한 사람들 집합 

// 부모를 찾는 함수 
int findParent(int x) {
    if(parent[x]==x) return x;
    return x=findParent(parent[x]);
}

// 부모를 합치는 함수 
void Union(int x, int y) {
    x=findParent(x);
    y=findParent(y);
    parent[x]=y;
}

int main(void) {
    int truthNum;

    scanf("%d %d", &N, &M);

    scanf("%d", &truthNum);

    // 진실을 아는 사람 입력받기 
    for(int i=0;i<truthNum;i++) {
        int person;
        scanf("%d", &person);

        truth.push_back(person);
    }

    // 제일 처음에는 자기자신이 부모
    for(int i=1;i<=N;i++) parent[i]=i;

    for(int i=0;i<M;i++) {
        int peopleNum;

        scanf("%d", &peopleNum);
        
        int prev;
        int person;
        for(int j=0;j<peopleNum;j++) {
            if(j>0) { // 각 파티에 참여한 모든 사람을 한 집합으로 묶는다.
                prev=person;
                scanf("%d", &person);
                Union(prev, person);
            } else {
                scanf("%d", &person);
            }

            party[i].push_back(person);
        }
    }

    for(auto& list : party) { // 모든 파티를 순회하면서 
        bool flag=false;

        for(auto& person : list) { // 해당 파티의 모든 멤버들과
            if(flag) break;

            for(auto& t : truth) { // 진실을 아는 멤버들의 
                if(findParent(person)==findParent(t)) { // 부모가 하나라도 같다면, 즉 같은 집합이 하나라도 있다면
                    flag=true; // 과장해서 말할 수 없다.
                    break;
                }
            }
        }
        if(flag) M--;
    }

    printf("%d\n", M);

    return 0;
}