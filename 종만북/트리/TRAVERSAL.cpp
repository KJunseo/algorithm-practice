/*
    전위, 중위, 후위 순회를 출력하는 문제는 꽤 봤었는데, 전위, 중위를 사용하여 후위를 출력하는 문제는 처음봤다.
    먼저 전위를 이용하여 루트를 구하고, 루트와 후위를 이용하여 왼쪽 서브트리 크기, 오른쪽 서브트리를 구한 후, 재귀로 구현한다.
    혼자서는 구현도 할 수 있을지 모르겠지만, 이런 생각을 해내는 것이 더 힘든 것 같다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int N;

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin()+a, v.begin()+b);
}

// 후위 탐색 결과(왼 -> 오 -> 루)
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {

    // 트리에 포함된 노드 수
    const int N = preorder.size();

    // 기저 사례: 비어있는 트리이면 곧장 종료 
    if(preorder.empty()) return;

    // 전위 탐색은 루트부터 방문하므로 0번째 값이 루트 값 
    const int root = preorder[0];

    // 중위 탐색은 루트를 중간에 방문하므로 루트의 값을 찾으면 왼쪽 서브트리의 크기를 구할 수 있음 
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

    // 오른쪽 서브 트리 크기는 전체에서 왼쪽 서브트리와 루트를 뺀 값 
    const int R = N - 1 - L;

    // 왼쪽 서브트리 순회 
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));

    // 오른쪽 서브트리 순회 
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));

    // 마지막으로 루트 출력 
    cout << root << " ";
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N;

        vector<int> preorder(N);
        for(int i = 0; i < N; i++) {
            cin >> preorder[i];
        }

        vector<int> inorder(N);
        for(int i = 0; i < N; i++) {
            cin >> inorder[i];
        }

        printPostOrder(preorder, inorder);
        cout << "\n";
    }

    return 0;
}