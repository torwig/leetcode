#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrderV1(TreeNode* root) {
    vector<vector<int>> result;

    if (!root) return result;

    vector<TreeNode*> nodes;
    nodes.push_back(root);

    while (!nodes.empty()) {
        vector<TreeNode*> next;
        vector<int> values;

        for (auto node : nodes) {
            values.push_back(node->val);

            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
        }

        result.push_back(values);
        nodes.swap(next);
    }

    return result;
}

void level(TreeNode* root, int l, vector<vector<int>>& levels) {
    if (!root) {
        return;
    }

    if (levels.size() <= l) {
        levels.emplace_back();
    }

    levels[l].push_back(root -> val);
    level(root -> left, l + 1, levels);
    level(root -> right, l + 1, levels);
}

vector<vector<int>> levelOrderV2(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> result;
    level(root, 0, result);
    return result;
}

int main() {

    return 0;
}
