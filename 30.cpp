#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (!root)
        return;

    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
