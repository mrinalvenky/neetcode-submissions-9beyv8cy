/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int max_path;
public:
    int helper(TreeNode* root) {
        if (!root) return 0;
        int maxL = helper(root->left);
        int maxR = helper(root->right);
        max_path = max(max_path, maxL + maxR);
        return 1 + max(maxL , maxR);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        max_path = 0;
        helper(root);
        return max_path;
    }
};
