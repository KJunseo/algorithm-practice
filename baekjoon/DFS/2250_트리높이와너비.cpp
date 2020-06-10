/*
    struct를 만들어서 왼쪽 오른쪽 자식을 이용해서 
    왼쪽에 몇명이 있나 오른쪽에 몇명이 있나 계산해서 풀이하려고 하였으나 실패했다.
    트리 쪽에 많이 약한 것 같다.

    이 문제에 필요한 것들은 tree, dfs, 중위순회이다

    1. 트리 생성
    2. 루트 노드 찾기(1이 루트가 아닐수가 있기 때문)
    3. dfs(중위순회)를 통해 각 레벨의 가장 왼쪽 값, 가장 오른쪽 값 구하기 
    4. 최고 너비 찾기
*/
#include <iostream>
#include <algorithm>
#define MAX 10001
#define INF 100000000

using namespace std;

// 각 노드의 정보를 담고 있음
struct tree {
    int left; // 왼쪽 자식
    int right; // 오른쪽 자식
} tree[MAX];

// 각 레벨의 가장 왼쪽, 오른쪽 값
struct storage {
    int left=INF; // 가장 왼쪽 값
    int right=0; // 가장 오른쪽 값 
} storage[MAX];

int N;
int col=1; // 노드가 위치하는 열을 나타냄
int findroot[MAX]; // 루트를 찾기위한 배열 

// 중위 순회(왼 - 중 - 오)
void dfs(int x, int level) {
    if(tree[x].left>0) dfs(tree[x].left, level+1); // 왼쪽 자식이 있다면 자식부터 
    
    // 현재 레벨의 왼쪽 값이 col보다 크면 최솟값 업데이트
    storage[level].left=min(storage[level].left, col);

    // 현재 레벨의 오른쪽 값이 col보다 작으면 최댓값 업데이트
    storage[level].right=max(storage[level].right, col);

    col++; // 열 증가 

    if(tree[x].right>0) dfs(tree[x].right, level+1); // 오른쪽 자식이 있다면 자식부터 
}

int main(void) {

    cin >> N;

    // 트리 구성 
    for(int i=1;i<=N;i++) {
        int node, l_child, r_child;
        cin >> node >> l_child >> r_child;

        findroot[node]++;

        // 왼쪽 자식 연결
        if(l_child!=-1) {
            findroot[l_child]++;
            tree[node].left=l_child;
        }
        // 오른쪽 자식 연결 
        if(r_child!=-1) {
            findroot[r_child]++;
            tree[node].right=r_child;
        }
    }

    int root;

    // 값이 1인 곳만 루트가 될 수 있음 
   for(int i=1;i<=N;i++) {
        if(findroot[i]==1) {
            root=i;
            break;
        }
    }

    dfs(root, 1); // 루트부터 중위순회 

    int level=1;
    int width=storage[1].right - storage[1].left + 1;
    for(int i=2;i<=N;i++) {

        int temp=storage[i].right-storage[i].left+1; // 넓이 계산 

        // 업데이트 
        if(width<temp) {
            level=i;
            width=temp;
        }
    }

    cout << level << " " << width << "\n";

    return 0;
}