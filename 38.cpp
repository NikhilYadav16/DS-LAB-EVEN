#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leftView(TreeNode* root) {
    if (!root)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool isFirst = true; // Flag to identify the first node at each level
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (isFirst) {
                std::cout << node->val << " ";
                isFirst = false;
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    std::cout << std::endl;
}
