#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetricV1(TreeNode* root) {
        if (!root) return true;
        return isNodesSymmetric(root->left, root->right);
    }

    bool isSymmetricV2(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            auto node1 = q.front();
            q.pop();
            auto node2 = q.front();
            q.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }

private:
    bool isNodesSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (left && right) {
            if (left->val != right->val) return false;
            return isNodesSymmetric(left->right, right->left) &&
                   isNodesSymmetric(left->left, right->right);
        }
        return false;
    }

    bool nodesEqual(TreeNode* first, TreeNode* second) {
        if (first && second && first->val == second->val) return true;
        return false;
    }
};

int main() {
    return 0;
}
