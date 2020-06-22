#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<int>& elements) {
    if (!root) return;

    inorder(root->left, elements);
    elements.push_back(root->val);
    inorder(root->right, elements);
}

// time: O(N), space: O(N).
int kthSmallestV1(TreeNode* root, int k) {
    vector<int> elements;
    inorder(root, elements);
    return elements[k - 1];
}

// time: O(H + k), space: O(H + k)
int kthSmallestV2(TreeNode* root, int k) {
    stack<TreeNode*> s;

    while (true) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (--k == 0) return root->val;
        root = root->right;
    }
}

int main() {

    return 0;
}
