#include <iostream>
#include <vector>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTreeFromPreorder(std::vector<int>& preorder, int& idx, int min, int max) {
    if (idx == preorder.size())
        return nullptr;

    int val = preorder[idx];
    if (val < min || val > max)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    ++idx;

    root->left = constructTreeFromPreorder(preorder, idx, min, val - 1);
    root->right = constructTreeFromPreorder(preorder, idx, val + 1, max);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (!root)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << " ";
}

void preorderToPostorder(std::vector<int>& preorder) {
    int idx = 0;
    TreeNode* root = constructTreeFromPreorder(preorder, idx, INT_MIN, INT_MAX);
    postorderTraversal(root);
}
