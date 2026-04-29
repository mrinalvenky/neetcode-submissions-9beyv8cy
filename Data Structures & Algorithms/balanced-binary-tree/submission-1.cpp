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
public:
    /*pair<bool, int> helper(TreeNode* root) {
        if (!root) return {true, 0};
        auto [lb, lh] = helper(root->left);
        auto [rb, rh] = helper(root->right);
        int height = 1 + max(lh, rh);
        bool balanced = lb && rb && (abs(lh - rh) <= 1);
        return {balanced, height};
    }
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }*/
    int helper(TreeNode* root) {
        if (!root) return 0;
        int lh = helper(root->left);
        if (lh < 0) return -1;
        int rh = helper(root->right);
        if (rh < 0) return -1;
        if (abs(lh - rh) > 1) return -1;
        int height = 1 + max(lh, rh);
        return height;
    }
    bool isBalanced(TreeNode* root) {
        return (helper(root) >= 0);
    }
};
