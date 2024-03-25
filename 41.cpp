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

TreeNode* constructTreeFromPostorder(std::vector<int>& postorder, int& idx, int min, int max) {
    if (idx < 0)
        return nullptr;

    int val = postorder[idx];
    if (val < min || val > max)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    --idx;

    root->right = constructTreeFromPostorder(postorder, idx, val + 1, max);
    root->left = constructTreeFromPostorder(postorder, idx, min, val - 1);

    return root;
}

void preorderTraversal(TreeNode* root) {
    if (!root)
        return;

    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderToPreorder(std::vector<int>& postorder) {
    int idx = postorder.size() - 1;
    TreeNode* root = constructTreeFromPostorder(postorder, idx, INT_MIN, INT_MAX);
    preorderTraversal(root);
}
