/*
    진짜 복잡했다. 혼자는 못 짤 것 같다..
    트립이라는 개념을 처음 알게되어 신기했다.
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int C;
int N;
int shifted[50000];
int A[50000];

typedef int KeyType;

// 트립의 한 노드 
struct Node {
    KeyType key; // 노드에 저장된 원소
    int priority, size; // 우선순위와, 이 노드를 루트로 하는 서브트리의 크기
    Node *left, *right; // 두 자식 노드의 포인터

    // 생성자
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {
    }

    void setLeft(Node* newLeft) {
        left = newLeft;
        calcSize();
    }

    void setRight(Node* newRight) {
        right = newRight;
        calcSize();
    }

    void calcSize() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

// root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두 개의 트립으로 분리한다.
NodePair split(Node* root, KeyType key) {

    if(root == NULL) return NodePair(NULL, NULL);

    // 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }

    // 루트가 key 이상이면 왼쪽 서브트리를 쪼갠다. 
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

// root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의 루트 반환
Node* insert(Node* root, Node* node) {

    if(root == NULL) return node;

    // node가 루트를 대체해야하는 경우 
    // 해당 서브트리를 반으로 잘라 각각 자손으로 한다. 
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else if(node->key < root->key) root->setLeft(insert(root->left, node));
    else root->setRight(insert(root->right, node));

    return root; 
}

// root를 루트로 하는 트리 중에서 k번째 원소를 반환
Node* kth(Node* root, int k) {
    int leftSize = 0; // 왼쪽 서브트리이 크기를 우선 계산 

    if(root->left != NULL) leftSize = root->left->size;
    if(k <= leftSize) return kth(root->left, k);
    if(k == leftSize + 1) return root;
    return kth(root->right, k - leftSize - 1);
}

// a와 b가 두 개의 트립이고, max(a) < min(b) 일 때 이 둘을 합친다.
Node* merge(Node* a, Node* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }

    a->setRight(merge(a->right, b));
    return a;
}

// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환 
Node* erase(Node* root, KeyType key) {
    
    if(root == NULL) return root;

    // root를 지우고 양 서브트리를 합친 뒤 반환 
    if(root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }

    if(key < root->key) root->setLeft(erase(root->left, key));
    else root->setRight(erase(root->right, key));

    return root;
}

void solve() {

    // 1 ~ N까지의 숫자를 모두 저장하는 트립을 만든다.
    Node* candidates = NULL;

    for(int i = 0; i < N; i++) 
        candidates = insert(candidates, new Node(i+1));

    for(int i = N-1; i >= 0; i--) {
        // 후보 중 이 수보다 큰 수가 larger개 있다. 
        int larger = shifted[i];
        Node* k = kth(candidates, i + 1 - larger);
        A[i] = k->key;
        candidates = erase(candidates, k->key);
    }
}

int main() {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N;

        for(int i = 0; i < N; i++)
            cin >> shifted[i];

        solve();

        for(int i = 0; i < N; i++) 
            cout << A[i] << " ";

        cout << "\n";
    }

    return 0;
}