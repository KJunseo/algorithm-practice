/*
    어려웠다.. 이진트리를 이용하여 구현하려고 시도했다.

    x좌표, y좌표, 부모의 x좌표, index, leftChild, rightChild를 가지고 있는 node를 만들고,
    y좌표를 기준으로 정렬하여, 가장 루트부터 채우면서, 자식노드를 업데이트 해주는 방법으로 구현했다.
    
    현재 노드가 부모의 x좌표보다 오른쪽에 있으면, 해당 노드의 왼쪽 자식은 부모노드의 x ~ 해당노드의 x 사이에 올 경우만 업데이트해주고,
                                                오른쪽 자식은 부모노드의 해당 노드의 x 보다 오른쪽에 있는 경우만 업데이트해주었다.
    
    현재 노드가 부모의 x좌표보다 왼쪽에 있으면, 해당 노드의 왼쪽 자식은 해당 노드의 x 보다 왼편에 있는 경우만 업데이트 해주었다.
                                                오른쪽 자식은 해당 해당 노드의 x ~ 부모노드의 x 사이에 올 경우만 업데이트 해주었다.

    그리고 전위 순회, 후위 순회를 만족하길래 맞게 풀었다고 생각했는데, 예시는 통과했지만, 정확성 24.1점 밖에 나오지 않았다..

    풀이를 보니 접근방법은 맞았던 것 같다. 구현하는 것이 많이 부족한 것 같다.
*/
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre;
vector<int> post;
struct Node {
    int id;
    int x, y;
    Node *left, *right;
};

bool compare(Node &a, Node &b) {
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}

// x값 기준으로 노드 삽입
void addNode(Node* parent, Node* child) {
    if(child->x < parent->x) { // 부모노드보다 작으면 
        if(parent->left==NULL) { // 자리가 비었으면 
            parent->left=child;
        } else {
            addNode(parent->left, child); 
        } 
    } else { // 부모노드보다 크고
        if(parent->right==NULL) { // 자리가 비었으면
            parent->right=child;
        } else {
            addNode(parent->right, child);
        }
    }
}

// 전위 순회
void preorder(Node* ptr) {
    if(ptr) { 
        pre.push_back(ptr->id);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// 후위 순회
void postorder(Node* ptr) {
    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        post.push_back(ptr->id);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int size=nodeinfo.size();
    vector<Node> nodes;

    for(int i=0;i<size;i++) {
        nodes.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL});
    }

    sort(nodes.begin(), nodes.end(), compare); // y를 기준으로 정렬

    Node* root = &nodes[0]; // 첫 번째 주소

    for(int i=1;i<size;i++) {
        addNode(root, &nodes[i]);
    }

    preorder(&nodes[0]);
    answer.push_back(pre);
    
    postorder(&nodes[0]);
    answer.push_back(post);

    return answer;
}



// 내가 구현한 풀이(실패)
/*vector<int> pre;
vector<int> post;
typedef struct node *treePointer;
typedef struct node {
    int x;
    int y;
    int p_x;
    int index;
    treePointer leftChild, rightChild;
} node;

bool compare(node a, node b) {
    return a.y>b.y;
}

void preorder(treePointer ptr) {
    if(ptr) { 
        pre.push_back(ptr->index);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr) {
    if(ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        post.push_back(ptr->index);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    node nodes[nodeinfo.size()];
    bool check[nodeinfo.size()];
    
    memset(check, false, sizeof(check));
    
    for(int i=0;i<nodeinfo.size();i++) {
        nodes[i].index=i+1;
        nodes[i].x=nodeinfo[i][0];
        nodes[i].y=nodeinfo[i][1];
        nodes[i].p_x=nodeinfo[i][0];
        nodes[i].leftChild=NULL;
        nodes[i].rightChild=NULL;
    }
    
    sort(nodes, nodes+nodeinfo.size(), compare);

    for(int i=0;i<nodeinfo.size();i++) {
        check[i]=true;
        
        for(int j=i+1;j<nodeinfo.size();j++) {
            if(nodes[i].y==nodes[j].y) continue;
            if(nodes[i].leftChild!=NULL && nodes[i].rightChild!=NULL) break;

            if(nodes[i].x<nodes[i].p_x) {
                if(check[j]) continue;
                if(nodes[j].x>nodes[i].x && nodes[j].x<nodes[i].p_x) {
                    if(nodes[i].rightChild!=NULL) continue;
                    nodes[i].rightChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                } else if(nodes[j].x<nodes[i].x) { 
                    if(nodes[i].leftChild!=NULL) continue;
                    nodes[i].leftChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                }
            } else if(nodes[i].x>nodes[i].p_x) {
                if(check[j]) continue;
                if(nodes[j].x>nodes[i].x) {
                    if(nodes[i].rightChild!=NULL) continue;
                    nodes[i].rightChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                } else if(nodes[j].x<nodes[i].x && nodes[j].x>nodes[i].p_x) { 
                    if(nodes[i].leftChild!=NULL) continue;
                    nodes[i].leftChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                } 
            } else {
                 if(nodes[j].x>nodes[i].x) {
                    nodes[i].rightChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                } else if(nodes[j].x<nodes[i].x) { 
                    nodes[i].leftChild=&nodes[j];
                    nodes[j].p_x=nodes[i].x;
                    check[j]=true;
                }  
            }
        }
    }
    
    preorder(&nodes[0]);
    answer.push_back(pre);
    
    postorder(&nodes[0]);
    answer.push_back(post);
    
    return answer;
}*/