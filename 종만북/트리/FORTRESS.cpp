/*
    성벽이 닿거나 겹치지 않으므로 이 문제는 계층을 나누어 트리문제로 해결할 수 있다.
    트리로 만들고나면 트리의 최장 경로를 구하는 문제로 생각할 수 있다.

    최장 경로가 될 수 있는 경우의 수는 2가지이다.
    1. 가장 긴 루트 - 잎 길이
    2. 가장 긴 잎 - 잎 길이

    1번의 경우는 트리의 높이이다.
    2번의 경우는 현재 노드의 자손 노드 중 한쪽에서 올라와서 다른쪽으로 내려가는 경우이다. 따라서 각각 자손 루트를 노드로 하는 서브트리의 높이에 1을 더한 값이 된다. 

    풀이를 보고 차근히 계산해보면 이해는 가지만 혼자는 못할 것 같다.. 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int N;
int x[100], y[100], radius[100];

struct TreeNode {
    vector<TreeNode*> children;
};

int longest;

// x^2 을 반환 
int sqr(int x) {
    return x*x;
}

// 두 성벽 a, b의 중심점 간의 거리의 제곱을 반환 
int sqrdist(int a, int b) {
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

// 성벽 a가 b를 포함하는 지 확인 
bool encloses(int a, int b) {
    return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

// 성벽 트리에서 parent가 child의 부모인지 확인
// parent는 child를 꼭 직접 포함해야 한다. 
bool isChild(int parent, int child) {

    // parent가 child를 포함하는지 확인 
    if(!encloses(parent, child)) return false;

    for(int i = 0; i < N; i++)
        if(i != parent && i != child && encloses(parent, i) && encloses(i, child)) return false;

    return true;
}

// root를 루트로 하는 트리 생성
TreeNode* getTree(int root) {
    TreeNode* ret = new TreeNode();

    for(int ch = 0; ch < N; ch++) 

        // ch 성벽이 root 성벽에 직접적으로 포함되어 있다면 
        // 트리를 만들고 자손 목록에 추가
        if(isChild(root, ch)) ret->children.push_back(getTree(ch));
    
    return ret;
}

// root를 루트로 하는 서브트리의 높이를 반환 
int height(TreeNode* root) {
    
    // 각 자식을 루트로 하는 서브트리의 높이를 계산 
    vector<int> heights;

    for(int i = 0; i < root->children.size(); i++) {
        heights.push_back(height(root->children[i]));
    }

    // 자식이 하나도 없다면 0을 반환 
    if(heights.empty()) return 0; 

    sort(heights.begin(), heights.end());

    // root를 최상위 노드로 하는 경로 고려
    if(heights.size() >= 2) {
        longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
    }

    // 트리의 높이는 서브 트리 높이의 최대치에 1을 더한 것
    return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산 
int solve(TreeNode* root) {
    longest = 0;

    // 트리의 높이(루트 - 잎)와 최대 잎-잎 경로 길이 중 큰 것을 선택한다. 
    int h = height(root);
    return max(longest, h);
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> x[i] >> y[i] >> radius[i];
        }

        TreeNode* node = getTree(0); // 트리 생성 
        cout << solve(node) << "\n";
    }

    return 0;
}