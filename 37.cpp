#include <iostream>
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bottomView(TreeNode* root) {
    if (!root)
        return;

    std::map<int, int> mp; // Map to store horizontal distance and node values
    std::queue<std::pair<TreeNode*, int>> q; // Queue for level order traversal

    q.push({root, 0}); // Push root node with horizontal distance 0

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Update horizontal distance in the map
        mp[hd] = node->val;

        if (node->left) {
            // Push left child with horizontal distance - 1
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            // Push right child with horizontal distance + 1
            q.push({node->right, hd + 1});
        }
    }

    // Print the bottom view
    for (auto it : mp) {
        std::cout << it.second << " ";
    }
    std::cout << std::endl;
}
