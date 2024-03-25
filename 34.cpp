#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root) {
    if (!root)
        return 0;

    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (!root)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return std::max(leftHeight + rightHeight, std::max(leftDiameter, rightDiameter));
}
